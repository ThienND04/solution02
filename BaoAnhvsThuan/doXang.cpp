#include<bits/stdc++.h>

using  namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "doXang"
#define maxn 301
#define inf 1e9

int n, m, l, q;
int c[maxn][maxn], res[maxn], xang[maxn];
vector<int> adj[maxn];

void init(){
    memset(c, 99, sizeof(c));
    cin >> n >> m >> l;
    while(m --){
        int u, v;
        cin >> u >> v;
        cin >> c[u][v];
        c[v][u] = c[u][v];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dijkstra(int s){
    priority_queue<vector<int> > pq;
    pq.push({0, l, s});
    xang[s] = l;
    res[s] = 0;
    while(! pq.empty()){
        vector<int> tmp = pq.top();
        pq.pop();
        int k = - tmp[0], x = tmp[1], u = tmp[2];
        if(k != res[u] || x != xang[u]) continue;
        for(int v: adj[u]){
            if(res[v] < res[u]) continue;
            if(xang[u] < c[u][v]){
                if(res[v] > res[u] + 1) {
                    res[v] = res[u] + 1;
                    xang[v] = l - c[u][v];
                    pq.push({-res[v], xang[v], v});
                }
                else if(res[v] == res[u] + 1 && xang[v] < l - c[u][v]) {
                    xang[v] = l - c[u][v];
                    pq.push({-res[v], xang[v], v});
                }
            }
            else {
                if(res[v] > res[u]) {
                    res[v] = res[u];
                    xang[v] = xang[u] - c[u][v];
                    pq.push({-res[v], xang[v], v});
                }
                else if(res[v] == res[u] && xang[v] < xang[u] - c[u][v]) {
                    xang[v] = xang[u] - c[u][v];
                    pq.push({-res[v], xang[v], v});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    cin >> q;
    while(q --){
        int u, v;
        cin >> u >> v;
        fill(res + 1, res + n + 1, inf);
        res[u] = 0;
        dijkstra(u);
        if(res[v] == inf) cout << -1 << "\n";
        else cout << res[v] << "\n";
    }
    return 0;
}