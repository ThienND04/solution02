#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "sweets"
#define inf 1e18
#define mod 1000000007
#define maxn 101

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
    ll s = 0, f[1 << 20];
    map<vector<ll>, bool> mp[maxn];

    void subtask4(){
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        mp[0][{0, 0, 0}] = 1;
        vector<ll> tmp = {0, 0, 0};
        for (int i = 1; i <= n; i++)
        {
            for (auto [vt, b] : mp[i - 1])
            {
                if (!b)
                    continue;
                for (int t = 0; t < 3; t++)
                {
                    tmp = vt;
                    tmp[t] += a[i];
                    sort(tmp.begin(), tmp.end());
                    mp[i][tmp] = 1;
                }
            }
        }
        ll res = inf;
        for (auto [vt, b] : mp[n])
        {
            if (!b)
                continue;
            minimize(res, vt[2] - vt[0]);
        }
        cout << res;
    }

    void subtask3(){
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
            s += a[i];
        }
        reset(f);
        for(int x = 0; x < (1 << n); x ++){
            ll s1 = 0;
            for(int i = 1; i <= n; i ++){
                if(bit(x, (i - 1))) s1 += a[i];
            }
            if(s1 <= s / 3) f[x] = s1;
            for(int j = 1; j <= n; j ++){
                if(bit(x, (j - 1))) maximize(f[x], f[x ^ (1 << j - 1)]);
            }
        }
        ll res = 1e18;
        for(int x = 0; x < (1 << n); x ++){
            ll s2 = 0, s3 = 0;
            for (int i = 1; i <= n; i++)
            {
                if (! bit(x, (i - 1)))
                    s2 += a[i];
                else s3 += a[i];
            }
            s3 -= f[x];
            if(f[x] <= s2 && s2 <= s3) {
                minimize(res, s3 - f[x]);
            }
        }
        cout << res;
    }

    void process()
    {
        cin >> n;
        if(n <= 20){
            subtask3();
        }
        else subtask4();
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
