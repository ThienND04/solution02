#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "photos"
#define inf 1e9
#define mod 998244353
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
    ll n, m;
    int c[maxn], cntBit[maxn][LOG];
    int res = 0;

    void init(){
        reset(cntBit);
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> c[i];
        sort(c + 1, c + n + 1);
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j < LOG; j ++) {
                cntBit[i][j] = cntBit[i - 1][j] + bit(c[i], j);
            }
        }
    }

    bool ok(int patten, int b){
        ll cnt = 0;
        int sum = 0;
        for(int i = 1; i <= n; i ++){
            int left = (patten ^ (c[i] >> b)) << b;
            int right = left | ((1 << b) - 1);
            int lp = lower_bound(c + 1, c + n + 1, left) - c;
            int rp = upper_bound(c + 1, c + n + 1, right) - c - 1;
            if(lp > rp) continue;
            cnt += rp - lp + 1;
            if(cnt > 2 * m) return 0;
            sum = (sum + 1ll * (patten << b) * (rp - lp + 1)) % mod;
            for(int j = 0; j < b; j ++){
                int tmp = cntBit[rp][j] - cntBit[lp - 1][j];
                if (bit(c[i], j)) tmp = rp - lp + 1 - tmp;
                sum = (sum + 1ll * (1 << j) * tmp) % mod;
            }
        }
        cnt /= 2;
        sum = (sum & 1) ? (sum + mod) / 2 : sum / 2;
        if(m < cnt) return 0;
        m -= cnt;
        add(res, sum);
        return 1;
    }

    void process()
    {
        init();
        int patten = 0;
        for(int i = LOG - 1; i >= 0; i --){
            if(ok((patten << 1) ^ 1, i)) {
                patten <<= 1;
            }
            else patten = (patten << 1) ^ 1;
        }
        res = (res + 1ll * m * patten) % mod;
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