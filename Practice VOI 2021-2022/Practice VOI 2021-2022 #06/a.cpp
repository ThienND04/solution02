#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "a"
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

#define B 321

    int n;
    int a[maxn];
    int lt[maxn], h[maxn];

    void init()
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        lt[0] = 1;
        h[0] = 0;
        for (int i = 1; i <= n; i++)
            lt[i] = (1ll * lt[i - 1] * B) % mod;
        for (int i = 1; i <= n; i++)
            h[i] = (1ll * h[i - 1] * B + a[i]) % mod;
    }

    const ll mod2 = 1ll * mod * mod;

    int get(int l, int r)
    {
        return (h[r] - 1ll * h[l - 1] * lt[r - l + 1] + mod2) % mod;
    }

    int maxF(){
        int res = 0;
        map<int, int> mp;
        for(int i = 1; i <= n; i ++) mp[a[i]] ++;
        for(auto i: mp){
            maximize(res, i.second);
        }
        return res;
    }

    void process()
    {
        init();

        int L = 0, R = 0, maxCnt = maxF();

        int lf = 0, rt = n + 1;
        while(rt - lf > 1){
            int mid = (lf + rt) / 2;
            bool ok = 0;
            map<int, int> cnt;

            for(int l = 1; l + mid - 1 <= n; l ++) cnt[get(l, l + mid - 1)] ++;

            for (int l = 1; l <= n; l++)
            {
                int r = l + mid - 1;
                if(r > n) continue;
                int hs = get(l, r);
                if(cnt[hs] == maxCnt){
                    ok = 1;
                    L = l;
                    R = r;
                    maxCnt = cnt[hs];
                }
            }
            if(ok) lf = mid;
            else rt = mid;
        }
        cout << L << " " << R;
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
