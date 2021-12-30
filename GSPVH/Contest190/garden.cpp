#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, -0x3f, sizeof(a))
#define task "garden"
#define inf 1e9
#define mod 1000000007
#define maxn 2222

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

namespace caculate
{
    template <class T>
    void add(T &x, T y)
    {
        x += y;
        if (x >= mod)
            x -= mod;
    }
    template <class T>
    void sub(T &x, T y)
    {
        x -= y;
        if (x < 0)
            x += mod;
    }
    template <class T>
    void maximize(T &x, T y)
    {
        if (x < y)
            x = y;
    }
    template <class T>
    void minimize(T &x, T y)
    {
        if (x > y)
            x = y;
    }
}

using namespace caculate;

namespace process
{
    int m, n, k;
    int a[maxn][maxn];
    ll f[maxn][maxn][11];
    ll maxFirstRow[maxn][11], maxSecondRow[maxn][11];
    ll maxFirstCol[maxn][11], maxSecondCol[maxn][11];

    void process()
    {
        reset(f);
        reset(maxFirstRow); reset(maxSecondRow);
        reset(maxFirstCol); reset(maxSecondCol);
        cin >> m >> n >> k;
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++) cin >> a[i][j];
        }
        for(int t = 0; t <= k; t ++){
            for(int i = 0; i <= m + 1; i ++) f[i][0][t] = 0;
            for(int j = 1; j <= n; j ++){
                for(int i = 1; i <= m; i ++){
                    maximize(f[i][j][t], f[i - 1][j - 1][t]);
                    maximize(f[i][j][t], f[i][j - 1][t]);
                    maximize(f[i][j][t], f[i + 1][j - 1][t]);
                    
                    if(t){
                        maximize(f[i][j][t], (maxFirstRow[i][t - 1] == f[i][j][t - 1] ?\
                                 maxSecondRow[i][t - 1] : maxFirstRow[i][t - 1]));
                        maximize(f[i][j][t], (maxFirstCol[j][t - 1] == f[i][j][t - 1] ?\
                                 maxSecondCol[j][t - 1] : maxFirstCol[j][t - 1]));
                    }

                    f[i][j][t] += a[i][j];
                    // maximize(maxRow[i][t], f[i][j][t]);
                    if(f[i][j][t] > maxFirstRow[i][t]){
                        maxSecondRow[i][t] = maxFirstRow[i][t];
                        maxFirstRow[i][t] = f[i][j][t];
                    }
                    else
                        maximize(maxSecondRow[i][t], f[i][j][t]);
                    // maximize(maxCol[j][t], f[i][j][t]);
                    if(f[i][j][t] > maxFirstCol[j][t]){
                        maxSecondCol[j][t] = maxFirstCol[j][t];
                        maxFirstCol[j][t] = f[i][j][t];
                    }
                    else maximize(maxSecondCol[j][t], f[i][j][t]);
                }
            }
        }
        ll res = -(1e18);
        for(int i = 1; i <= m; i ++) maximize(res, f[i][n][k]);
        cout << res;
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
    process::process();
    return 0;
}
