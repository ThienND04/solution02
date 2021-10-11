//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define MIN(x, y) \
    if (x > y)    \
    x = y
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define Task "tienluong"
#define maxn 100001
#define maxk 1001
#define MOD 1000000007
#define remain(x) \
    if (x > MOD)  \
    x -= MOD
#define pii pair<int, int>

using namespace std;
int n, k, dp[maxn][maxk], root, w[maxn];
vector<int> child[maxn];

void read()
{
    for (int i = 0; i <= n; i++)
        child[i].clear();
    int par;
    for (int i = 1; i <= n; i++)
    {
        cin >> par >> w[i];
        if (par)
            child[par].PB(i);
        else
            root = i;
    }
}

void dfs(int u, int par)
{
    for (int i = 0; i <= k; i++)
        dp[u][i] = dp[par][i];
    for (int i = 0; i < child[u].size(); i++)
        dfs(child[u][i], u);
    for (int i = k; i; i--)
        dp[par][i] = max(dp[u][i], dp[par][i - 1] + w[u]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    int ntest;
    cin >> ntest;
    while (ntest--)
    {
        cin >> n >> k;
        read();
        dp[0][0] = 0;
        for (int i = 1; i <= k; i++)
            dp[0][i] = -1000000000;
        dfs(root, 0);
        cout << max(dp[0][k], 0) << endl;
        //cout << n << " " << k << endl;
    }
    return 0;
}