#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "c"
#define maxn 100001
#define reset(a) memset(a, 0, sizeof(a));
#define inf 1000000000

int n, m, l;
vector<pii>adj[maxn];
ll res = 0;
ll d[3][maxn];
bool visited[maxn], used[maxn];
vector<int> zone;

void dfs(int u, int t){
    visited[u] = used[u] = 1;
    zone.push_back(u);
    for(pii e: adj[u]){
        int v = e.first, w = e.second;
        if(! visited[v]) {
            d[t][v] = d[t][u] + w;
            dfs(v, t);
        }
    }
    visited[u] = 0;
}

ll checkTree(int u){
    zone.clear();
    dfs(u, 0);
    int x = u;
    for(int v: zone) if(d[0][x] < d[0][v]) x = v;
    dfs(x, 1);
    int y = x;
    for(int v: zone) if(d[1][y] < d[1][v]) y = v;
    dfs(y, 2);
    res = max(res, d[1][y]);
    int tmp = u;
    for(int v: zone){
        if(max(d[1][v], d[2][v]) < max(d[1][tmp], d[2][tmp])) tmp = v;
    }
    return max(d[1][tmp], d[2][tmp]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> m >> l;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<ll> r;
    for(int i = 0; i < n; i ++){
        if(! used[i]) r.push_back(checkTree(i));
    }
    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());
    if(r.size() >= 3) res = max(res, 2ll * l + r[1] + r[2]);
    if(r.size() >= 2) res = max(res, 1ll * l + r[0] + r[1]);
    cout << res;
    return 0;
}
