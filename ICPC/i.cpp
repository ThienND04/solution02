#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "i"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

namespace caculate{
    template<class T>
    void add(T& x, T y){
        x += y;
        if(x >= mod) x -= mod;
    }
    template<class T>
    void sub(T& x, T y){
        x -= y;
        if(x < 0) x += mod;
    }
    template<class T>
    void maximize(T& x, T y){
        if(x < y) x = y;
    }
    template<class T>
    void minimize(T& x, T y){
        if(x > y) x = y;
    }
}

using namespace caculate;

namespace process{
    int n;
    int a[maxn];
    int cnt[maxn], cnt2[maxn];

    void update(int x, int d){
        while(x <= n) {
            cnt[x] += d;
            x += x & -x;
        }
    }

    void update2(int x, int d){
        while(x <= n) {
            cnt2[x] += d;
            x += x & -x;
        }
    }

    ll get(int x){
        ll res = 0;
        while(x){
            res += cnt[x];
            x -= x & -x;
        }
        return res;
    }

    ll get2(int lf, int rt){
        ll res = 0;
        while(rt){
            res += cnt2[rt];
            rt -= rt & -rt;
        }
        rt = lf - 1;
        while(rt){
            res -= cnt2[rt];
            rt -= rt & -rt;
        }
        return res;
    }

    int left[maxn], right[maxn];

    void process(){
        reset(cnt);
        reset(left);
        reset(right);
        cin >> n;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
        }
        ll s = 0;
        for(int i = n; i >= 1; i --){
            right[i] = get(a[i] - 1);
            s += right[i];
            update(a[i], 1);
        }
        // cerr << s << "\n";
        for(int i = 1; i <= n; i ++){
            left[i] = get2(a[i] + 1, n);
            update2(a[i], 1);
        }
        ll res = inf;
        for(int i = 1; i <= n; i ++){
            ll tmp = s - 1ll * left[i] * right[i] - left[i] - right[i];
            minimize(res, tmp);
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
