#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "pnum"
#define maxn 51
#define inf 1000000007

#define bit(x, i) ((x >> i) & 1)

int mod;

void add(int &x, int y)
{
    x += y;
    if (x >= mod)
        x -= mod;
}

int n, m, k;
int l[7], r[7];
int dp[maxn][13][13][13][13][13];
int s[7];

void init()
{
    cin >> n >> k >> m >> mod;
    for (int i = 1; i <= m; i++)
    {
        cin >> l[i];
        r[i] = l[i] + 9;
        s[i] = 10;
    }
}

void solve()
{
    dp[0][0][0][0][0][0] = 1;
    // for(int i = 0; i <= 5; i ++) cerr << l[i] << " " << r[i] << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int s1 = 0; s1 <= 10; s1++)
        {
            for (int s2 = 0; s2 <= 10; s2++)
            {
                for (int s3 = 0; s3 <= 10; s3++)
                {
                    for (int s4 = 0; s4 <= 10; s4++)
                    {
                        for (int s5 = 0; s5 <= 10; s5++)
                        {
                            for (int d = 0; d < k; d++)
                            {
                                int n1 = s1 + d * (l[1] <= i && i <= r[1]);
                                int n2 = s2 + d * (l[2] <= i && i <= r[2]);
                                int n3 = s3 + d * (l[3] <= i && i <= r[3]);
                                int n4 = s4 + d * (l[4] <= i && i <= r[4]);
                                int n5 = s5 + d * (l[5] <= i && i <= r[5]);
                                if (max({n1, n2, n3, n4, n5}) > 10)
                                    break;
                                add(dp[i][n1][n2][n3][n4][n5], dp[i - 1][s1][s2][s3][s4][s5]);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << dp[n][s[1]][s[2]][s[3]][s[4]][s[5]];
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