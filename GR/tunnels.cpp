#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a))
#define task "tunnels"
#define inf 999999999999999
#define maxn 11

struct edge
{
    int v, h, w;
};

int n, m, x, y;
ll d[maxn], h[maxn];
bool visited[maxn], used[maxn];
vector<edge> adj[maxn];

void DFS(int u){
    visited[u] = 1;
    used[u] = 1;
    if(u == y) return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> x >> y;
    cin >> m;
    while( m --){
        int u, v, h, w;
        cin >> u >> v >> h >> w;
        adj[u].push_back({v, h, w});
        adj[v].push_back({u, h, w});
    }
    dijkstra();
    cout << h[y] << " " << d[y];
    return 0;
}