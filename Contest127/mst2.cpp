#include <bits/stdc++.h>

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
ll sum = 0;
int par[maxn], q[maxn], sz = 0;
bool res[maxn];
canh ed[maxn];

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
}

void solve()
{
    int j = 1;
    for (int i = 1; i <= m; i++)
    {
        while(ed[j].c < ed[i].c){
            int u = ed[j].u, v = ed[j].v;
            if(root(u) != root(v)) {
                join(u, v);
            }
            j ++;
        }
        if(root(ed[i].u) == root(ed[i].v)) res[ed[i].id] = 0;
        else res[ed[i].id] = 1;
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
    init();
    solve();
    for (int i = 1; i <= m; i++)
    {
        if (res[i])
            cout << "Yes ";
        else
            cout << "No ";
    }
    return 0;
}