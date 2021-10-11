#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "giaohang"
#define inf 1e9 + 7
#define maxn 501
#define delta 0.0000001

int n, m, q, k;
int cost[maxn][maxn], minCost[maxn][maxn];
ll dist[maxn][maxn];
int c[maxn];
ll res = 0;

void floyd(){
    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= n; j ++) dist[i][j] = 1e18;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(cost[i][j] < inf) dist[i][j] = cost[i][j];
        }
    }
    for(int i = 1; i <= n; i ++) dist[i][i] = 0;
    for(int t = 1; t <= n; t ++){
        for(int u = 1; u <= n; u ++){
            for(int v = 1; v <= n; v ++){
                dist[u][v] = min(dist[u][v], dist[u][t] + dist[t][v]);
            }
        }
    }
    for(int u = 1; u <= n; u ++){
        for(int v = 1; v <= n; v ++){
            if(u == v) continue;
            minCost[u][v] = -1;
            for(int t = 1; t <= n; t ++){
                if(t != v && dist[u][t] + cost[t][v] == dist[u][v]){
                    if(minCost[u][v] < 0 || minCost[u][v] > cost[t][v]) minCost[u][v] = cost[t][v];
                }
            }
        }
    }
}

void calc(){
    res = 0;
    for(int v = 1; v <= n; v ++){
        int tmp = inf;
        ll miDist = 1e18;
        for(int i = 1; i <= k; i ++) {
            miDist = min(miDist, dist[c[i]][v]);
        }
        if(miDist == 0) continue;
        for(int i = 1; i <= k; i ++) {
            if(miDist == dist[c[i]][v]){
                tmp = min(tmp, minCost[c[i]][v]);
            }
        }
        res += tmp;
    }
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m >> q;
    for(int i  = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) cost[i][j] = inf;
    }
    while(m --){
        int u, v, l;
        cin >> u >> v >> l;
        cost[u][v] = min(cost[u][v], l);
        cost[v][u] = min(cost[v][u], l);
    }
    floyd();
    while(q --){
        cin >> k;
        for(int i = 1; i <= k; i ++) cin >> c[i];
        calc();
        cout << res << "\n";
    }
    for(int i = 1; i <= n; i ++){
        assert(dist[i][i] == 0);
    }
    return 0;
}