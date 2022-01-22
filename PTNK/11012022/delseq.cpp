#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "delseq"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

#define LOG 20

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
    int n;
    int a[maxn];
    int f[maxn][1024];

    void process(){
        cin >> n;
        reset(f);
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
        }
        int res = 0;
        f[0][0] = 0;
        for(int i = 1; i <= n; i ++) {
            f[i][0] = f[i - 1][0] + a[i];
        }
        for(int s = 1; s < 1024; s ++){
            f[0][s] = 0;
            for(int i = 1; i <= n; i ++){
                maximize(f[i][s], f[i - 1][s] + a[i]);
                for(int k = 0; (1 << k) <= i; k ++){
                    if(bit(s, k)){
                        maximize(f[i][s], f[i - (1 << k)][s ^ (1 << k)]);
                    }
                }
                maximize(res, f[i][s]);
            }
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
