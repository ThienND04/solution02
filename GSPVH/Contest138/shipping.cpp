#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "shipping"
#define inf 1e9
#define mod 1000000007
#define maxn 5001
#define delta 0.0000001

struct host
{
    int u, c, p;
};


int n, m, k, q;
vector<int> adj[maxn];
host h[maxn];

int dist[maxn][maxn];

void dijkstra(int s){
    priority_queue<pii> que;
    que.push({0, s});
    dist[s][s] = 0;
    while(! que.empty()){
        int u = que.top().second, l = - que.top().first;
        que.pop();
        if(l != dist[s][u]) continue;
        for(int v: adj[u]){
            if(dist[s][v] > l + 1){
                dist[s][v] = l + 1;
                que.push({- dist[s][v], v});
            }
        }
    }
}

bool check(int maxDist, int v, int t, ll b){
    int sl = 0;
    ll tien = 0;
    for(int i = 1; i<= k; i ++){
        int u = h[i].u, c = h[i].c, p = h[i].p;
        if(dist[u][v] <= maxDist){
            int tmp = min(c, t - sl);
            sl += tmp;
            tien += 1ll * tmp * p;
        }
    }
    return (sl == t && tien <= b);
}

int query(int v, int t, ll b){
    int l = -1, r = n + 20;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(check(mid, v, t, b)) r = mid;
        else l = mid;
    }
    if(r <= n) return r;
    return -1;
}

void solve(){
    cin >> n >> m;
    memset(dist, 99, sizeof(dist));
    for(int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> k;
    for(int i = 1; i <= k; i ++){
        cin >> h[i].u >> h[i].c >> h[i].p;
        dijkstra(h[i].u);
    }
    sort(h + 1, h + k + 1, [](host u, host v){return u.p < v.p; });
    cin >> q;
    while(q --){
        int v, t;
        ll b;
        cin >> v >> t >> b;
        cout << query(v, t, b) << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    solve();
    return 0;
}