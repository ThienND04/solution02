#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "d13snp"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

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

    #define SQRT 333

    int n;
    int f[maxn][SQRT];

    void process()
    {
        cin >> n;
        reset(f);
        f[0][0] = 1;
        for(int i = 1; i <= n; i ++){
            for(int k = 1; k < SQRT; k ++){
                if(i - k >= 0) add(f[i][k], f[i - k][k]);
                if(i - 2 * k + 1 >= 0) add(f[i][k], f[i - 2 * k + 1][k - 1]);
            }
        }
        int res = 0;
        for(int i = 1; i < SQRT; i ++) add(res, f[n][i]);
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
