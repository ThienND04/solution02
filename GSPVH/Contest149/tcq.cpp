#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "tcq"
#define maxn 500001
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

class FenwickTree {
private:
    vector<int> v;
    int n;
 
public:
    FenwickTree(int _n = 0) {
        n = _n;
        v.assign(n + 7, 0);
    }
 
    void update(int x, int d) {
        if (x == 0) return;
        for (; x <= n; x += x & -x) v[x] += d;
    }
 
    int get(int x) const {
        int res = 0;
        for (; x >= 1; x -= x & -x) res += v[x];
        return res;
    }
};

int subtask, n, numQuery, cnt = 0;
int color[maxn], node[maxn], sta[maxn], fin[maxn], par[maxn];
vector<int> adj[maxn];
Query qr[maxn];
vector<int> queryAt[maxn];

#define sz(u) (fin[u] - sta[u])

int cntColor[maxn];
FenwickTree bit(maxn);

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
        qr[i].ans = bit.get(n) - bit.get(qr[i].k - 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> subtask >>  n;
    for(int i = 1; i <= n; i ++) cin >> color[i];
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> numQuery;
    for(int i = 1; i <= numQuery; i ++) {
        qr[i].nhap();
        queryAt[qr[i].v].push_back(i);
    }
    DFS(1);
    processDFS(1);
    // cerr << numQuery;
    for(int i = 1; i <= numQuery; i ++) cout << qr[i].ans << " ";
    return 0;
}