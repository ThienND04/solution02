#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "e"
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
    int a;
    double h;
    void process(){
        cin >> a >> h;
        double res = 0;
        for(int i = 0; i <= a; i ++){
            double tmp = h / 6 / a * i;
            maximize(res, (h - tmp) * i);
        }
        for(int i = a; i <= 100; i ++){
            double tmp = (h / 3 - h / 6) / (100 - a) * (i - a) + h / 6;
            maximize(res, (h - tmp) * i);
        }
        maximize(res, 2 * h / 3 * 100);
        cout << fixed << setprecision(8) << res;
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
