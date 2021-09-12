#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "mst"
#define inf 1e9
#define maxn 500001

struct canh
{
    int u, v, c, id; 
};

int t, n, m;
int par[maxn], res[maxn], sz = 0;
canh ed[maxn];

int root(int u)
{
    if (u == par[u])
        return u;
    return (par[u] = root(par[u]));
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
}

void solve()
{
    for (int i = 1; i <= m; i++)
    {
        int u = ed[i].u, v = ed[i].v;
        int x = root(u), y = root(v);
        if (root(u) != root(v))
        {
            par[x] = y;
            res[++ sz] = ed[i].id;
        }
    }
    sort(res + 1, res + sz + 1);
    for(int i = 1; i <= sz; i ++) cout << res[i] << " ";
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