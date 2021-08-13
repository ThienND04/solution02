#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "b"
#define maxn 100001
#define reset(a) memset(a, 0, sizeof(a));
#define inf 1000000000

int n;
vector<pii> adj[maxn];
int d[3][maxn];
bool visited[maxn];

void dfs(int u, int t){
    visited[u] = 1;
    for(pii e: adj[u]){
        int v = e.first, w = e.second;
        if(! visited[v]){
            d[t][v] = d[t][u] + w;
            dfs(v, t);
        }
    }
    visited[u] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n - 1; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1, 0);
    int x = max_element(d[0] + 1, d[0] + n + 1) - d[0];
    dfs(x, 1);
    int y = max_element(d[1] + 1, d[1] +n + 1) - d[1];
    dfs(y, 2);
    int res = 0;
    d[1][0] = inf;
    d[2][0] = inf;
    for(int u = 1; u <= n; u++){
        if(max(d[1][u], d[2][u]) < max(d[1][res], d[2][res])){
            res = u;
        }
    }
    // cout << res; 
    cout << max(d[1][res], d[2][res]);
    cerr << res;
    return 0;
}