#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "e"
#define inf 1e9
#define mod 1000000007
#define maxn 7

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
    int t;
    pii a[maxn], poly[maxn];
    int sz = 0;

    bool CCW(pii& p1, pii& p2, pii& p3){
        ll tmp = 1ll * (p3.first - p1.first) * (p2.second - p1.second) - 1ll * (p3.second - p1.second) * (p2.first - p1.first);
        return tmp < 0;
    }

    bool cmp(pii& p1, pii& p2){
        return CCW(a[1], p1, p2);
    }

    void convexHull(){
        sort(a + 1, a + 5);
        sort(a + 2, a + 5, cmp);
        a[5] = a[1];
        sz = 0;
        for(int i = 1; i < 4; i ++){
            if(a[i] == a[i + 1]) return;
        }
        for(int i = 2; i <= 5; i ++){
            while(sz >= 2 && !CCW(poly[sz - 1], poly[sz], a[i])) sz --;
            poly[++ sz] = a[i];
        }
    }

    void process()
    {
        cin >> t;
        while(t --){
            for(int i = 1; i <= 4; i ++) cin >> a[i].first >> a[i].second;
            convexHull();
            cout << (sz == 4 ? "YES\n" : "NO\n");
        }
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
