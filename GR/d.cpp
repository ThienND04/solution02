#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a))
#define clearst(st) while(! st.empty()) st.pop();
#define task "d"
#define inf 999999999
#define maxn 202

int n, a, b, k;
int d[13][maxn], res = inf;
vector<pii> adj[maxn];

void init(){
    cin >> a >> b >> n >> k;
    while(k --){
        int u, v, t;
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj[v + n].push_back({u + n, t});
    }
}

void dijkstra(){
    for(int i = 0; i < 13; i ++) fill(d[i], d[i] + 2 * n + 1, inf);
    priority_queue<vector<int>> q;
    d[0][a] = 0;
    d[0][a + n] = 12;
    q.push({0, 0, a});
    q.push({-12, 0, a + n});
    while(!q.empty()){
        int u = q.top()[2], us = q.top()[1], l = - q.top()[0];
        q.pop();
        if(l != d[us][u]) continue;
        int remain = 12 - us;
        for(pii e: adj[u]){
            int v = e.first, t = e.second;
            int dv, dvn;
            if(remain >= t) {
                dv = l + t;
                dvn = l + remain;
            }
            else continue;
            if(d[us + t][v] > dv){ //
                d[us + t][v] = dv;
                q.push({-d[us + t][v], us + t,  v});
            }
            if(v > n){
                if(d[0][v - n] > dvn){
                    d[0][v - n] = dvn;
                    q.push({- d[0][v - n], 0,  v - n});
                }
            }
            else{
                if(d[0][v + n] > dvn){
                    d[0][v + n] = dvn;
                    q.push({- d[0][v + n], 0,  v + n});
                }
            }
        }
    }
}

void solve(){
    dijkstra();
    int res = inf;
    for(int i = 0; i <= 12; i ++) {
        res =  min(res, min(d[i][b], d[i][b + n]));
    }
    if(res == inf) cout << -1;
    else cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();
    solve();
    return 0;
}