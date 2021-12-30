#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "hon"
#define inf 1e9
#define mod 1000000007
#define maxn 210

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
    int n, k;
    int a[maxn][maxn], maxRow[maxn], maxSecond[maxn];

    ll f[2][maxn][maxn], dp[2][maxn][maxn][maxn];

    void solve1(){
        reset(f);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n + i - 1; j++)
            {
                maximize(f[1][i][j], \
                         max(f[0][i - 1][j - 1], f[0][i - 1][j]) + maxRow[i]);
                maximize(f[1][i][j],
                         max(f[1][i - 1][j - 1], f[1][i - 1][j]) + a[i][j]);
                maximize(f[0][i][j],
                         max(f[0][i - 1][j - 1], f[0][i - 1][j]) + a[i][j]);
            }
        }
        for (int i = n - 1; i >= 1; i--)
        {
            int x = 2 * n - i;
            for (int j = 1; j <= n + i - 1; j++)
            {
                maximize(f[1][x][j],
                         max(f[0][x - 1][j + 1], f[0][x - 1][j]) + maxRow[x]);
                maximize(f[1][x][j],
                         max(f[1][x - 1][j + 1], f[1][x - 1][j]) + a[x][j]);
                maximize(f[0][x][j],
                         max(f[0][x - 1][j + 1], f[0][x - 1][j]) + a[x][j]);
            }
        }
        ll res = 0;
        for(int t = 0; t < 2; t ++){
            for(int j = 1; j <= n; j ++) maximize(res, f[t][2 * n - 1][j]);
        }
        cout << res;
    }

    void solve2(){
        reset(dp);
        for(int i = 1; i <= n; i ++){
            for(int j1 = 1; j1 < n + i - 1; j1 ++){
                for(int j2 = j1 + 1; j2 <= n + i - 1; j2 ++){
                    maximize(dp[0][i][j1][j2], \
                             max(dp[0][i - 1][j1][j2], dp[0][i - 1][j1 - 1][j2 - 1]) + a[i][j1] + a[i][j2]);
                    maximize(dp[0][i][j1][j2],
                             dp[0][i - 1][j1 - 1][j2] + a[i][j1] + a[i][j2]);
                    if(j2 - 1 != j1)
                        maximize(dp[0][i][j1][j2],
                                 dp[0][i - 1][j1][j2 - 1] + a[i][j1] + a[i][j2]);

                    ll d = (max(a[i][j1], a[i][j2]) == maxRow[i]) ? \
                             (maxSecond[i] + maxRow[i]) : (max(a[i][j1], a[i][j2]) + maxRow[i]);
                    maximize(dp[1][i][j1][j2],
                             max(dp[0][i - 1][j1][j2], dp[0][i - 1][j1 - 1][j2 - 1]) + d);
                    maximize(dp[1][i][j1][j2],
                             dp[0][i - 1][j1 - 1][j2] + d);
                    if (j2 - 1 != j1)
                        maximize(dp[1][i][j1][j2],
                                 dp[0][i - 1][j1][j2 - 1] + d);

                    maximize(dp[1][i][j1][j2],
                             max(dp[1][i - 1][j1][j2], dp[1][i - 1][j1 - 1][j2 - 1]) + a[i][j1] + a[i][j2]);
                    maximize(dp[1][i][j1][j2],
                             dp[1][i - 1][j1 - 1][j2] + a[i][j1] + a[i][j2]);
                    if (j2 - 1 != j1)
                        maximize(dp[1][i][j1][j2],
                                 dp[1][i - 1][j1][j2 - 1] + a[i][j1] + a[i][j2]);
                }
            }
        }
        for(int i = n - 1; i >= 1; i --){
            int x = 2 * n - i;
            for (int j1 = 1; j1 < n + i - 1; j1++)
            {
                for (int j2 = j1 + 1; j2 <= n + i - 1; j2++)
                {
                    maximize(dp[0][x][j1][j2],
                             max(dp[0][x - 1][j1][j2], dp[0][x - 1][j1 + 1][j2 + 1]) + a[x][j1] + a[x][j2]);
                    maximize(dp[0][x][j1][j2],
                             dp[0][x - 1][j1][j2 + 1] + a[x][j1] + a[x][j2]);
                    if (j1 + 1 != j2)
                        maximize(dp[0][x][j1][j2],
                                 dp[0][x - 1][j1 + 1][j2] + a[x][j1] + a[x][j2]);

                    ll d = (max(a[x][j1], a[x][j2]) == maxRow[x]) ? \
                             (maxSecond[x] + maxRow[x]) : (max(a[x][j1], a[x][j2]) + maxRow[x]);
                    maximize(dp[1][x][j1][j2],
                             max(dp[0][x - 1][j1][j2], dp[0][x - 1][j1 + 1][j2 + 1]) + d);
                    maximize(dp[1][x][j1][j2],
                             dp[0][x - 1][j1][j2 + 1] + d);
                    if (j1 + 1 != j2)
                        maximize(dp[1][x][j1][j2],
                                 dp[0][x - 1][j1 + 1][j2] + d);

                    maximize(dp[1][x][j1][j2],
                             max(dp[1][x - 1][j1][j2], dp[1][x - 1][j1 + 1][j2 + 1]) + a[x][j1] + a[x][j2]);
                    maximize(dp[1][x][j1][j2],
                             dp[1][x - 1][j1][j2 + 1] + a[x][j1] + a[x][j2]);
                    if (j1 + 1 != j2)
                        maximize(dp[1][x][j1][j2],
                                 dp[1][x - 1][j1 + 1][j2] + a[x][j1] + a[x][j2]);
                }
            }
        }
        ll res = 0;
        for(int t = 0; t < 2; t ++){
            for(int j1 = 1; j1 < n; j1 ++){
                for(int j2 = j1 + 1; j2 <= n; j2 ++){
                    maximize(res, dp[t][2 * n - 1][j1][j2]);
                }
            }
        }
        cout << res;
    }

    void process()
    {
        cin >> n >> k;
        reset(a);
        reset(maxRow);
        reset(maxSecond);
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n + i - 1; j ++){
                cin >> a[i][j];
                if(a[i][j] > maxRow[i]){
                    maxSecond[i] = maxRow[i];
                    maxRow[i] = a[i][j];
                }
                else{
                    maximize(maxSecond[i], a[i][j]);
                }
            }
        }
        for(int i = n - 1; i >= 1; i --){
            for(int j = 1; j <= n + i - 1; j ++){
                cin >> a[2 * n - i][j];
                if (a[2 * n - i][j] > maxRow[2 * n - i])
                {
                    maxSecond[2 * n - i] = maxRow[2 * n - i];
                    maxRow[2 * n - i] = a[2 * n - i][j];
                }
                else
                {
                    maximize(maxSecond[2 * n - i], a[2 * n - i][j]);
                }
            }
        }
        // for(int i = 1; i <= 10; i ++){
        //     for(int j = 1; j <= 10; j ++) cerr << a[i][j] << " ";
        //     cerr << "\n";
        // }
        if(k == 1){
            solve1();
        }
        else solve2();
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
