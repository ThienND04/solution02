#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "retout"
#define inf 1e9
#define mod 1000000007
#define maxn 1001

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
    int n;
    int a[maxn];
    ll m;

    int f[maxn][5001];

    void sub13(){
        reset(f);
        f[0][0] = 1;
        for(int i = 1; i <= n; i ++){
            for(int g = a[i]; g <= m; g ++){
                f[i][g] = (f[i][g - a[i]] + f[i - 1][g - a[i]]) % mod;
            }
        }
        cout << f[n][m];
    }

    int POW(int num, int k){
        if(k == 1) return num;
        int c = POW(num, k / 2);
        c = (1ll * c * c) % mod;
        if(k % 2 == 1) c = (1ll * c * num) % mod;
        return c;
    }

    int comb(int b, int k){
        ll tu = 1, mau = 1;
        for(int i = 1; i <= k; i ++) mau = (mau * i) % mod;
        for(ll i = b - k + 1; i <= b; i ++){
            tu = (tu * (i % mod)) % mod;
        }
        int res = (tu * POW(mau, mod - 2)) % mod;
        return res;
    }

    void sub2(){
        cout << comb(m - 1, n - 1);
    }

    void process()
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        if(n <= 1000 && m <= 5000){
            sub13();
        }
        else sub2();
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
