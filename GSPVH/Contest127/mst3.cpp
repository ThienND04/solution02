#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "mst"
#define inf 1e9
#define maxn 500003

struct canh
{
    int u, v, c, id; 
};

int t, n, m;
int tr[maxn], par[maxn], disc[maxn], low[maxn], num, node[2 * maxn];
bool res[maxn];
canh ed[maxn];
vector<canh> block[maxn];
vector<pii> adj[maxn];
int check[maxn];
bool used[maxn];

int root(int u)
{
    if (u == par[u])
        return u;
    return (par[u] = root(par[u]));
}

void join(int u,int v){
    par[root(u)] = v;
}

void init()
{
    cin >> t >> n >> m;
    vector<int> vt;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        vt.push_back(c);
        ed[i] = {u, v, c, i};
    }
    for (int i = 1; i <= n; i++)
        par[i] = i;
    sort(vt.begin(), vt.end());
    vt.resize(unique(vt.begin(), vt.end()) - vt.begin());
    for(int i = 1; i <= m; i ++){
        int u = lower_bound(vt.begin(), vt.end(), ed[i].c) - vt.begin() + 1;
        block[u].push_back(ed[i]);
    }
}

void dfs(int u){
    disc[u] = low[u] = ++num;
    for(pii e: adj[u]){
        int v = e.first;
        if(! tr[v]){
            tr[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]) res[e.second] = 1;
        }
        else if(v != tr[u]) low[u] = min(low[u], disc[v]);
    }
}

void solveBlock(int x){
    num = 0;
    int cnt = 0;
    for(canh e: block[x]){
        int u = root(e.u), v = root(e.v);
        if(u != v){
            if(! used[u]) node[++ cnt] = u;
            if(! used[v]) node[++ cnt] = v;
        }
    }
    for(canh e: block[x]){
        int u = root(e.u), v = root(e.v);
        if(u != v){
            adj[u].push_back({v, e.id});
            adj[v].push_back({u, e.id});
        }
    }
    for(int i = 1; i <= cnt; i ++){
        int u = node[i];
        if(! tr[u]) {
            tr[u] = -1;
            dfs(u);
        }
    }
    for(canh e: block[x]){
        int u = root(e.u), v = root(e.v);
        if(u != v) join(e.u, e.v);
    }
    for(int i = 1; i <= cnt; i ++){
        int u = node[i];
        for(pii e: adj[u]){
            if(! check[e.first]) check[e.first] = e.second;
            else{
                res[check[e.first]] = 0;
                res[e.second] = 0;
            }
        }
        for(pii e: adj[u]){
            check[e.first] = 0;
        }
        adj[u].clear();
        used[u] = 0;
        tr[u] = 0;
        disc[u] = low[u] = 0;
    }
}

void solve(){
    init();
    for(int i = 1; i <= m; i ++){
        if(! block[i].empty()) solveBlock(i);
    }
    for(int i = 1; i <= m; i ++){
        if(res[i]) cout << "Yes ";
        else cout << "No ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    solve();
    return 0;
}