#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "covercir"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

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

int t;
ll n, u, v;

namespace subtask2{
    bool In(int x, int l, int r){
        if(r < l) return (x >= l || x <= r);
        return (x >= l && x <= r);
    }

    int calc(int x, int l, int r){
        if(r < l){
            r += n;
        }

        if(x < l) x += n;

        int d1 = x - l, d2 = r - x;
        return min(d1, d2) * 2 + max(d1, d2);
    }

    int subtask2(){
        if(u == v) return n / 2;
        int res = 1e9;

        for(int p = 1; p <= n; p ++){
            for(int q = 1; q <= n; q ++){
                if(! In(u, p, q)) continue;
                if(! In(v, q % n + 1, (p - 2 + n) % n + 1)) continue;
                int s1 = calc(u, p, q);
                int s2 = calc(v, q % n + 1, (p - 2 + n) % n + 1);
                minimize(res, max(s1, s2));
            }       
        }
        return res;
    }
}

namespace subtask4{
    bool ok(ll d1, ll d2, ll y){
        return 2 * (d1 + y) >= d2;
    }

    ll subtask4(){
        if(u == v) return n / 2;
        ll d1 = v - u - 1;
        ll d2 = u + n - v - 1;
        
        if(d1 > d2) swap(d1, d2);
        if(2 * d1 >= d2) return d2;

        ll l = 0, r = d2;
        while(r - l > 1){
            ll mid = (l + r) / 2;
            if(ok(d1, d2, mid)) r = mid;
            else l = mid;
        }

        // 2 * d1 + 2 * y >= d2
        // t = 2 * d1 + y
        return min(d2, 2 * d1 + r);
    }
}

namespace process{
    void process(){
        cin >> t;
        while(t --){
            cin >> n >> u >> v;
            if(u > v) swap(u, v);
            cout << subtask2::subtask2() << '\n';
            //cout << subtask4::subtask4() << '\n';
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
