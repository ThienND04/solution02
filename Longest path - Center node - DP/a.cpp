#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "a"
#define maxn 100001
#define reset(a) memset(a, 0, sizeof(a));

int n;
vector<pii> adj[maxn];
int d[maxn];
bool visited[maxn];


void dfs(int u){
    visited[u] = 1;
    for(pii e: adj[u]){
        int v = e.first, w = e.second;
        if(! visited[v]){
            d[v] = d[u] + w;
            dfs(v);
        }
    }
    visited[u] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n - 1; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs(1);
    int x = max_element(d + 1, d + n + 1) - d;
    // reset(d);
    d[x] = 0;
    dfs(x);
    cout << *max_element(d + 1, d + n + 1);
    return 0;
}