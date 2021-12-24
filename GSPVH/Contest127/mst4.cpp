#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "mst"
#define inf 1e18
#define maxn 500001

#define bit(x, i) ((x >> i) & 1)

struct canh
{
    int u, v, c, id; 
};

int t, n, m;
int par[maxn], res[maxn], sz = 0;
canh ed[maxn];
bool inMST[maxn];
vector<pii> adj[maxn];
int p[20][maxn], maximum[20][maxn], hight[maxn]; // lca
ll minimize[maxn];
int nt[maxn], pre[maxn];

int root(int u)
{
    if (u == par[u])
        return u;
    return (par[u] = root(par[u]));
}

void join(int u, int v){
    par[root(u)] = v;
}

void init()
{
    cin >> t >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        ed[i] = {u, v, c, i};
    }
    for (int i = 1; i <= n; i++)
        par[i] = i;
    sort(ed + 1, ed + m + 1, [](canh &a, canh &b)
         { return a.c < b.c; });
    for (int i = 1; i <= m; i++)
    {
        int u = ed[i].u, v = ed[i].v;
        if (root(u) != root(v))
        {
            join(u, v);
            adj[u].push_back({v, ed[i].c});
            adj[v].push_back({u, ed[i].c});
            inMST[ed[i].id] = 1;
        }
    }
}

int getMaximum(int u, int v){
    int ans = 0;
    if(hight[u] < hight[v]) swap(u, v);
    int delta = hight[u] - hight[v];
    for(int i  = 19; i >= 0; i --){
        if(bit(delta, i)){
            ans = max(ans, maximum[i][u]);
            u = p[i][u];
        }
    }
    if(u == v) return ans;
    for(int i = 19; i >= 0; i --){
        if(p[i][u] != p[i][v]){
            ans = max(ans, maximum[i][u]);
            u = p[i][u];
            ans = max(ans, maximum[i][v]);
            v = p[i][v];
        }
    }
    ans = max(ans, maximum[0][u]);
    ans = max(ans, maximum[0][v]);
    return ans;
}

int lca(int u, int v){
    if(hight[u] < hight[v]) swap(u, v);
    int delta = hight[u] - hight[v];
    for(int i  = 19; i >= 0; i --){
        if(bit(delta, i)){
            u = p[i][u];
        }
    }
    if(u == v) return u;
    for(int i = 19; i >= 0; i --){
        if(p[i][u] != p[i][v]){
            u = p[i][u];
            v = p[i][v];
        }
    }
    return p[0][u];
}

void dfs(int u){
    for(pii e: adj[u]){
        int v = e.first, c = e.second; 
        if(p[0][u] == v) continue;
        hight[v] = hight[u] + 1;
        p[0][v] = u;
        maximum[0][v] = c;
        for(int i = 1; i < 20; i ++){
            p[i][v] = p[i - 1][p[i - 1][v]];
            maximum[i][v] = max(maximum[i - 1][v], maximum[i - 1][p[i - 1][v]]);
        }
        dfs(v);
    }
}

int getNt(int x){
    if(minimize[x] == inf) return x;
    return (nt[x] = getNt(nt[x]));
}

void update(int u, int v, ll z){
    int rt = lca(u, v);
    u = getNt(u);
    v = getNt(v);
    while(hight[u] > hight[rt]){
        minimize[u] = min(minimize[u], z);
        nt[pre[u]] = nt[u];
        pre[nt[u]] = pre[u];
        u = nt[u];
    }
    while(hight[v] > hight[rt]){
        minimize[v] = min(minimize[v], z);
        nt[pre[v]] = nt[v];
        pre[nt[v]] = pre[v];
        v = nt[v];
    }
}

void solve()
{
    fill(minimize + 1, minimize + n + 1, inf);
    dfs(1);
    for(int i = 1; i <= n; i ++) nt[i] = p[0][i];
    for(int i = 1; i <= n; i ++) pre[nt[i]] = i;
    for(int i = 1; i <= m; i ++){
        if(! inMST[ed[i].id]){
            int u = ed[i].u, v = ed[i].v, c = ed[i].c;
            res[ed[i].id] = getMaximum(u, v) - 1;
            update(u, v, c - 1);
        }
    }
    for(int i = 1; i <= m; i ++){
        if(inMST[ed[i].id]) {
            int u = ed[i].u, v = ed[i].v;
            if(hight[u] < hight[v]) swap(u, v);
            if(minimize[u] != inf) res[ed[i].id] = minimize[u];
            else res[ed[i].id] = -1;
        }
    }
    for(int i = 1; i <= m; i ++) cout << res[i] << " ";
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
    init();
    solve();
    return 0;
}