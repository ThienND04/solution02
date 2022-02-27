#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "shipcount"
#define inf 1e9
#define mod 1000000007
#define maxn 2001

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

int k, n;

namespace subtask2{
    int f[maxn][maxn];
    int a[maxn][maxn];

    void subtask2(){    
        reset(f);
        f[0][0] = 1;
        for(int i = 0; i <= n; i ++){
            for(int j = i; j <= n; j ++){
                a[i][j] = 1;
                for(int t = j - i + 1; t <= j; t ++) {
                    a[i][j] = (1ll * a[i][j] * t) % mod;
                }
            }
        }
        for(int i = 1; i <= k; i ++){
            for(int s = 0; s <= n; s ++){
                for(int t = 0; t <= s; t ++){
                    int tmp = (1ll * f[i - 1][t] * a[s - t][n - t]) % mod;
                    add(f[i][s], tmp);
                }
            }
        }
        cout << f[k][n];
    }       
}

namespace subtask3{
    int a[maxn][maxn];

    void subtask3(){    
        reset(a);
        for(int i = 0; i <= n; i ++) a[0][i] = 1;
        for(int i = 1; i <= n; i ++){
            for(int j = i; j <= n; j ++){
                if(i == 0) a[i][j] = 1;
                else{
                    a[i][j] = (a[i - 1][j - 1] + a[i][j - 1]) % mod;
                }
            }
        }
        // for(int i = 0; i <= n; i ++){
        //     for(int j = 0; j <= n; j ++){
        //         cerr << i << " C " << j << " = " << a[i][j] << "\n";
        //     }
        // }
        int sum = 0;
        for(int i = 1; i <= min(k, n); i ++){
            int s = 1;
            for(int j = 1; j <= n; j ++) s = (1ll * s * j) % mod;
            s = (1ll * s * a[i][k]) % mod;
            s = (1ll * s * a[i - 1][n - 1]) % mod;
            add(sum, s);
        }
        cout << sum;
    }       
}

namespace process{
    void process(){
        cin >> k >> n;
        //if(k <= 200 && n <= 200) return subtask2::subtask2();
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
