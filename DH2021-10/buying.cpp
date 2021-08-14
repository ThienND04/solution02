#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "buying"
#define maxn 201
#define bit(x, i) ((x >> i) & 1)
#define inf 1000000000000000

int n;
int x[maxn], y[maxn], z[maxn];
ll l[maxn][maxn][maxn];

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i] >> z[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int k = 0; k <= i; k++)
            {
                l[i][j][k] = inf;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(task ".inp", "r", stdin);
    // freopen(task ".out", "w", stdout);
    init();
    for (int i = 1; i <= n; i++)
    {
        for (int t = 1; t <= 3; t++)
        {
            for (int j = 0; j < i; j++)
            {
                for (int k = 0; k < i; k++)
                {
                    if (t == 1)
                    {
                        l[i][j][k] = min(l[i][j][k], l[i - 1][j][k] + x[i]);
                    }
                    else if (t == 2)
                    {
                        l[i][j + 1][k] = min(l[i][j + 1][k], l[i - 1][j][k] + y[i] - j);;
                    }
                    else
                    {
                        l[i][j][k + 1] = min(l[i][j][k + 1], l[i - 1][j][k] + z[i] - k);
                    }
                }
            }
        }
    }
    ll res = inf;
    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= n; j++) res = min(res, l[n][i][j]);
    }
    cout << res;
    return 0;
}