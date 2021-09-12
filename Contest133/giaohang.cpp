#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "giaohang"
#define inf 1e9
#define maxn 501
#define delta 0.0000001

int n, m, q, k;
int w[maxn][maxn];
ll dist[maxn][maxn];
int c[maxn];
vector<pii> adj[maxn];

ll res = 0;

void floyd(){
    memset(dist, 99, sizeof(dist));
    for(int i = 1; i <= n; i ++) dist[i][i] = 0;
    for(int t = 1; t <= n; t ++){
        for(int u = 1; u <= n; u ++){
            for(int v = 1; v <= n; v ++){
                if(dist[u][v] > dist[u][k] + dist[k][v]){
                    dist[u][v] = dist[u][k] + dist[k][v];
                }
            }
        }
    }
}

void calc(){
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m >> q;
    while(m --){
        int u, v, l;
        cin >> u >> v >> l;
        w[u][v] = w[v][u] = l;
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
    }
    floyd();
    return 0;
}