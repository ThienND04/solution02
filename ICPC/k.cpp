#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "k"
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
    int n;
    int x[maxn], y, z;
    ll s[maxn];
    void process(){
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> x[i];
        cin >> y >> z;
        for(int i = 1; i <= n; i ++){
            x[i] = abs(x[i] - z);
        }
        y = abs(y - z);
        int res = 0;
        sort(x + 1, x + n + 1);
        s[0] = 0;
        for(int i = 1; i <= n; i ++){
            s[i] = s[i - 1] + x[i];
        }
        for(int i = 1; i <= n; i ++){
            int t = upper_bound(s, s + i + 1, s[i] - y) - s + 1;
            maximize(res, i - t + 1);
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
