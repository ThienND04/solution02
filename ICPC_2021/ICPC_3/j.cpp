#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "j"
#define inf 1e9
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
    ll m, a[maxn], b[maxn];

    ll calcR(){
        ll minDay = 1e16;
        for(int i = 1; i <= n; i ++){
            ll x = m / a[i] + 1;
            minimize(minDay, x - x / (b[i] + 1));
        }
        return minDay;
    }

    bool check(int x){
        ll p = 0;
        for(int i = 1; i <= n; i ++){
            ll y = x - x / (b[i] + 1);
            p += a[i] * y;
        }
        return (p >= m);
    }

    void process()
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i ++) cin >> a[i] >> b[i];
        ll l = 0, r = calcR();
        while(r - l > 1){
            ll mid = (l + r) / 2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        cout << r;
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
