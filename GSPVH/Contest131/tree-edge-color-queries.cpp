#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "tree-edge-color-queries"
#define inf 1e9
#define maxn 300001
#define delta 0.0000001
#define mod 998244353

int t, n, q;
int par[maxn];
pii edge[maxn];
map<int, int> inZ[maxn], color[maxn];
int sColor[maxn];
vector<int> adj[maxn];

int cnt = 0;

void init(){
    cin >> t >> n;
    for(int i = 1; i < n; i ++) {
        int u, v;
        cin >> u >> v;
        edge[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
        cin >> color[u][v];
        color[v][u] = color[u][v];
    }
}

void dfs(int u){
    for(int v: adj[u]){
        if(v == par[u]) continue;
        par[v] = u;
        dfs(v);
        cnt += sColor[v];
        if(inZ[v][color[u][v]]){
            cnt --;
        }
        if(! inZ[u][color[u][v]]) {
            sColor[u] ++;
        }
        inZ[u][color[u][v]] ++;
    }
}

void update(int u, int v, int d){
    if(v == par[u]) swap(u, v);
    int old = color[u][v];
    if(d == old) return;
    inZ[u][old] --;
    if(inZ[u][old] || color[par[u]][u] == old){
        cnt ++;
    }
    if(inZ[v][old]) cnt ++;
    if(inZ[u][d] || color[par[u]][u] == d){
        cnt --;
    }
    if(inZ[v][d]) cnt --;
    inZ[u][d] ++;
    color[u][v] = color[v][u] = d;
}

void solve(){
    cin >> q;
    cnt = 0;
    dfs(1);
    cnt += sColor[1];
    cout << cnt << " ";
    while(q --){
        int i, d;
        cin >> i >> d;
        int u = edge[i].first, v = edge[i].second;
        update(u, v, d);
        cout << cnt << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    solve();
    return 0;
}