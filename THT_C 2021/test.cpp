#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "test"
#define maxn 200200
#define inf 1000000007
#define mod 998244353

int n, color[maxn];
vector<int> adj[maxn];
int id[maxn], par[maxn], res[maxn];
set<int> s[maxn];

void DFS(int u){
    s[id[u]].insert(color[u]);
    for(int v: adj[u]){
        if(v == par[u]) continue;
        par[v] = u;
        DFS(v);
        int iu = id[u], iv = id[v];
        if(s[iu].size() >= s[iv].size()){
            for(int e: s[iv]) s[iu].insert(e);
        }
        else{
            for(int e: s[iu]) s[iv].insert(e);
            id[u] = id[v];
        }
    }
    res[u] = s[id[u]].size();
}

void init(){
    cin >> n;
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i ++) {cin >> color[i]; id[i] = i; }
}

void solve(){
    DFS(1);
    for(int i = 1; i <= n; i ++) cout << res[i] << " ";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    init();
    solve();
    return 0;
}