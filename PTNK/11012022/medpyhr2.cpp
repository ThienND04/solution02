#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "medpyhr2"
#define inf 1e9
#define mod 1000000007
#define maxn 1001000

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
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
    int t, n;
    int a[maxn];
    bool b[maxn];

    bool check(int x){
        for(int i = 1; i < 2 * n; i ++) b[i] = (a[i] >= x);
        for(int i = 0; i < n - 1; i ++){
            if(b[n - i] == b[n - i - 1]) return b[n - i];
            if(b[n + i] == b[n + i + 1]) return b[n + i];
        }
        return b[1];
    }

    void solve(){
        cin >> n;
        for(int i = 1; i < 2 * n; i ++) cin >> a[i];
        int l = -1000, r = inf + 100;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else r = mid;
        }
        cout << l << "\n";
    }


    void process(){
        cin >> t;
        while (t --)
        {
            solve();
        }
    }
}

signed main()
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
