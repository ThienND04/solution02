#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "optbst"
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

namespace process{
    int n;
    int c[maxn];
    ll sumc[maxn][maxn], f[maxn][maxn], root[maxn][maxn];

    void process(){
        cin >> n;
        memset(f, -1, sizeof(f));
        for(int i = 1; i <= n; i ++) cin >> c[i];
        for(int l = 1; l <= n; l ++){
            f[l][l] = c[l];
            root[l][l] = l;
            sumc[l][l] = c[l];
            for(int r = l + 1; r <= n; r ++){
                sumc[l][r] = sumc[l][r - 1] + c[r];
            }
        }
        for(int len = 2; len <= n; len ++){
            for(int l = 1; l + len - 1 <= n; l ++){
                int r = l + len - 1;
                for(int k = root[l][r - 1]; k <= root[l + 1][r]; k ++){
                    if(f[l][r] == -1 || f[l][r] > f[l][k - 1] + f[k + 1][r] + sumc[l][r]){
                        f[l][r] = max(0ll, f[l][k - 1]) + max(0ll, f[k + 1][r]) + sumc[l][r];
                        root[l][r] = k;
                    }
                }
            }
        }
        cout << f[1][n];
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
