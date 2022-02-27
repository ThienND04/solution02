#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "diamond"
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

int n, k;
int a[maxn], b[maxn];

namespace subtask3{
    pair<double, int> tmp[maxn];

    bool check(double x){
        for(int i = 1; i <= n; i ++){
            tmp[i] = {1.0 * a[i] / b[i] - x, i};
        }
        sort(tmp + 1, tmp + n + 1);
        double s = 0;
        for(int i = n; i >= n - k + 1; i --) s += tmp[i].first;
        return (s >= 0);
    }

    void subtask3(){
        double delta = 0.000000001;
        double l = 0, r = 1e16;
        while(r - l > delta){
            double mid = (l + r) / 2;
            if(check(mid)) l = mid;
            else l = mid;
        }
        check(l);
        ll ts = 0, ms = 0;
        for(int i = n; i >= n - k + 1; i --){
            ts += a[tmp[i].second];
            ms += b[tmp[i].second];
        }
        ll gg = __gcd(ts, ms);
        ts /= gg; ms /= gg;
        cout << ts << " " << ms;
    }
}

namespace process{
    void process(){
        cin >> n >> k;
        for(int i = 1; i <= n; i ++){
            cin >> a[i] >> b[i];
        }
        return subtask3::subtask3();
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
