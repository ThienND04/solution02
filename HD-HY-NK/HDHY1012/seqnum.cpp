#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "seqnum"
#define inf 1e9
#define mod 1000000007
#define maxn 200200

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
    ll fl[maxn], fr[maxn];
    ll maxL[maxn], maxR[maxn];

    void process()
    {
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        fl[0] = -(1e18);
        for(int i = 1; i <= n; i ++){
            if(i < 3) fl[i] = -(1e18);
            else{
                fl[i] = 0ll + a[i] + a[i - 1] + a[i - 2];
                maximize(fl[i], fl[i] + fl[i - 3]);
            }
        }
        maxL[0] = (-1e18);
        for(int i = 1; i <= n; i ++){
            maxL[i] = max(maxL[i - 1], fl[i]);
        }

        fr[n + 1] = -(1e18);
        for(int i = n; i >= 1; i --){
            if(i > n - 2)
                fr[i] = -(1e18);
            else{
                fr[i] = 0ll + a[i] + a[i + 1] + a[i + 2];
                maximize(fr[i], fr[i] + fr[i + 3]);
            }
        }
        maxR[n + 1] = -(1e18);
        for(int i = n; i >= 1; i --){
            maxR[i] = max(maxR[i + 1], fr[i]);
        }
        ll res = -(1e18);
        for(int i = 2; i < n - 2; i ++){
            maximize(res, maxL[i] + maxR[i + 1]);
        }
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
