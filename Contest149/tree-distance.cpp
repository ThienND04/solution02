#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "tree-distance"
#define maxn 300001
#define inf 1e18
// #define mod 1000000007

const int mod = 998244353;

int subtask;
int n, k;
vector<int> adj[maxn];
int hight[maxn], cntHight[maxn];
int node[maxn], sta[maxn], fin[maxn], cnt = 0;
ll res = 0;
int par[maxn];

#define TREE_SIZE(u) (fin[u] - sta[u] + 1)

void Add(int& x, int y){
    x += y;
    if(x > mod) x -= mod;
}

void DFS(int u){
    node[++ cnt] = u;
    sta[u] = cnt;
    for(int v: adj[u]) {
        if(v != par[u]){
            par[v] = u;
            hight[v] = hight[u] + 1;
            DFS(v);
        }
    }
    fin[u] = cnt;
}

void processDFS(int u){    
    int bigChild = -1;
    for(int v: adj[u]){
        if(v == par[u]) continue;
        if(bigChild == -1 || TREE_SIZE(v) > TREE_SIZE(bigChild)) bigChild = v;
    }
    if(bigChild < 0) {
        cntHight[hight[u]] ++;
        return;
    }
    for(int v: adj[u]){
        if(v == par[u] || v == bigChild) continue;
        processDFS(v);
        for(int j = sta[v]; j <= fin[v]; j ++){
            cntHight[hight[node[j]]] --;
        }
    }
    processDFS(bigChild);
    for(int v: adj[u]){
        if(v == par[u] || v == bigChild) continue;
        for(int j = sta[v]; j <= fin[v]; j ++){
            int need = k + 2 * hight[u] - hight[node[j]];
            if(0 <= need && need < n) res += cntHight[need];
        }
        for(int j = sta[v]; j <= fin[v]; j ++){
            cntHight[hight[node[j]]] ++;
        }
    }
    if(hight[u] + k < n) res += cntHight[hight[u] + k];
    cntHight[hight[u]] ++;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> subtask;
    cin >> n >> k;
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    processDFS(1);
    cout << res;
    return 0;
}