#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "xorSet"
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

namespace process{
    int n, k;
    int a[maxn];
    int f[105][105][129];

    void init(){
        cin >> n >> k;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
        }
    }

    void process(){
        init();
        reset(f);
        f[0][0][128] = 1;
        for(int i = 0; i <= 128; i ++) f[0][0][i] = 1;
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j <= k; j ++){
                for(int mask = 0; mask <= 128; mask ++){
                    add(f[i][j][mask], f[i - 1][j][mask]);
                    if(j > 0 && a[i] + mask == (a[i] ^ mask)){
                        add(f[i][j][mask], f[i - 1][j - 1][mask | a[i]]);
                    }
                }
            }
        }
        int res = 0;
        for(int j = 1; j <= k; j ++){
            for(int t = 0; t <= 128; t ++) add(res, f[n][j][t]);
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