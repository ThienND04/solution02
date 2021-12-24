#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "sumlove"
#define inf 1e9
#define mod 1000000007
#define maxn 6
#define SQRT 6

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 32
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
    int n, q;
    int f[maxn][SQRT];
    int g[maxn];

    void process(){
        cin >> n >> q;  
        reset(f);
        reset(g);
        f[0][0] = 1;
        for(int k = 1; k <= n; k ++){
            for(int t = 0; t <= sqrt(n); t ++){
                if(k - t >= 0){
                    add(f[k][t], f[k - t][t]);
                    if(t >= 1) add(f[k][t], f[k - t][t - 1]);
                    if(t >= 2) add(f[k][t], f[k - t][t - 2]);
                }
                if(k > n && t > 0) sub(f[k][t], f[k - n - 1][t - 1]);
            }
        }
        for(int k = 1; k <= n; k ++){
            for(int t = 1; t <= k; t ++){
                cerr << k << " " << t << " : " << f[k][t] << "\n";
            }
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
