#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "tcq"
#define maxn 100005
#define inf 1e18
#define mod 1000000007

struct Query
{
    int v, k, ans;

    Query(int v_ = 0, int k_  = 0) : v(v_ ), k(k_ )
    { }

    void nhap(){
        cin >> v >> k;
    }
};

#define BLOCK_SIZE 330
#define IN_BLOCK(pos) ((pos - 1) / BLOCK_SIZE + 1)

class noClass {
private:
    vector<int> blocks[BLOCK_SIZE];
    vector<int> cntBlock;
    int n;
 
public:
    noClass(int _n = 0) {
        n = _n;
        for(int i = 1; i <= n / BLOCK_SIZE + 6; i ++) {
            // cerr << i << endl;
            blocks[i].assign(BLOCK_SIZE + 6, 0);
        }
        cntBlock.assign(BLOCK_SIZE + 6, 0);
    }
 
    void update(int x, int d) {
        int bl_id = IN_BLOCK(x);
        cntBlock[bl_id] += d;
        blocks[bl_id][x - (bl_id - 1) * BLOCK_SIZE] += d;
    }
 
    int get(int left, int right) {
        int result = 0;
        for(int i = 0; i <= right - (IN_BLOCK(right) - 1) * BLOCK_SIZE; i ++){
            result += blocks[IN_BLOCK(right)][i];
        }
        for(int i = left - (IN_BLOCK(left) - 1) * BLOCK_SIZE; i <= BLOCK_SIZE; i ++){
            result += blocks[IN_BLOCK(left)][i];
        }
        for(int i = IN_BLOCK(left) + 1; i < IN_BLOCK(right); i ++){
            result += cntBlock[i];
        }
        return result;
    }
};

int subtask, n, numQuery, cnt = 0;
int color[maxn], node[maxn], sta[maxn], fin[maxn], par[maxn];
vector<int> adj[maxn];
Query qr[maxn];
vector<int> queryAt[maxn];

#define sz(u) (fin[u] - sta[u])

int cntColor[maxn];
noClass bit(maxn);

void insertNode(int u){
    bit.update(cntColor[color[u]], -1);
    cntColor[color[u]] ++;
    bit.update(cntColor[color[u]], 1);
}

void removeNode(int u){
    bit.update(cntColor[color[u]], -1);
    cntColor[color[u]] --;
    bit.update(cntColor[color[u]], 1);
}

void DFS(int u){
    node[++ cnt] = u;
    sta[u] = cnt;
    for(int v: adj[u]) {
        if(v != par[u]){
            par[v] = u;
            DFS(v);
        }
    }
    fin[u] = cnt;
}

void processDFS(int u){
    int bigChild = -1;
    for(int v: adj[u]){
        if(v == par[u]) continue;
        if(bigChild < 0 || sz(bigChild) < sz(v)) bigChild = v;
    }
    if(bigChild < 0) {
        insertNode(u);
        for(int i: queryAt[u]) {
            if(qr[i].k == 1) qr[i].ans = 1;
            else qr[i].ans = 0;
        }
        return;
    }
    for(int v: adj[u]){
        if(v == par[u] || v == bigChild) continue;
        processDFS(v);
        for(int j = sta[v]; j <= fin[v]; j ++){
            removeNode(node[j]);
        }
    }
    processDFS(bigChild);
    for(int v: adj[u]){
        if(v == par[u] || v == bigChild) continue;
        for(int j = sta[v]; j <= fin[v]; j ++){
            insertNode(node[j]);
        }
    }
    insertNode(u);
    for(int i: queryAt[u]){
        qr[i].ans = bit.get(qr[i].k, n);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >>  n >> numQuery;
    for(int i = 1; i <= n; i ++) cin >> color[i];
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= numQuery; i ++) {
        qr[i].nhap();
        queryAt[qr[i].v].push_back(i);
    }
    DFS(1);
    processDFS(1);
    // cerr << numQuery;
    for(int i = 1; i <= numQuery; i ++) cout << qr[i].ans << "\n";
    return 0;
}

