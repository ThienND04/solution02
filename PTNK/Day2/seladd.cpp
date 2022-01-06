 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "seladd"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

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
    int n, q, k;
    int a[maxn], t[6];

    bool ok(const int& x){
        for(int i = 1; i <= k; i ++) if(x == t[i]) return 1;
        return 0;
    }

    void process(){
        cin >> n >> q >> k;
        ll res = 0;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
            res += a[i];
        }
        for(int i = 1; i <= k; i ++) cin >> t[i];
        while(q --){
            int l, r, x;
            cin >> l >> r >> x;
            for(int i = l; i <= r; i ++){
                if(! ok(a[i])){
                    res += x;
                    a[i] += x;
                }
            }
            cout << res << "\n";
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
