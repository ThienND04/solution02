#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "d"
#define inf 1e9
#define mod 1000000007
#define maxn 301

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
    int a[maxn], b[maxn];
    void process(){
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        for(int i = 1; i <= n; i ++) cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        int s = 0;
        for(int i = 1; i <= n; i ++) s += abs(a[i] - b[i]);
        cout << fixed << setprecision(9) << 1.0 * s / n;
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
