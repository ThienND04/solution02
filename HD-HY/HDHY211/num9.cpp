#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "num9"
#define inf 1e9
#define mod 1000000007
#define maxn 1000001

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
    int a[maxn];
    int pos[10], numPos = 0, neg[10], numNeg = 0;
    ll f[10][10][4];

    void init(){
        cin >> n;
        assert(n >= 9);
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i ++){
            if(a[i] >= 0 || numNeg == 9) break;
            neg[++ numNeg] = a[i];
        }
        for(int i = n; i >= 1; i --){
            if(a[i] < 0 || numPos == 9) break;
            pos[++ numPos] = a[i];
        }
    }

    void process(){
        init();

        for(int i = 0; i <= 9; i ++){
            for(int j = 0; j <= 9; j ++){
                for(int t = 0; t <= 3; t ++) f[i][j][t] = -4 * (1e18);
            }
        }

        f[0][0][0] = 0;
        
        for(int i = 0; i <= numNeg; i ++){
            for(int j = 0; j <= numPos; j ++){
                f[i][j][0] = 0;
                // cerr << i << " " << j << " " << 0 << ": " << f[i][j][0] << "\n";
                for(int t = 1; t <= 3; t ++){
                    if(j >= 1) maximize(f[i][j][t], f[i][j - 1][t]);
                    if(i >= 1) maximize(f[i][j][t], f[i - 1][j][t]);
                    if(i >= 1 && j >= 2) maximize(f[i][j][t], f[i - 1][j - 2][t - 1] + 1ll * neg[i] * pos[j] * pos[j - 1]);
                    if(j >= 1 && i >= 2) maximize(f[i][j][t], f[i - 2][j - 1][t - 1] + 1ll * pos[j] * neg[i] * neg[i - 1]);
                    if(j >= 3) maximize(f[i][j][t], f[i][j - 3][t - 1] + 1ll * pos[j - 2] * pos[j] * pos[j - 1]);
                    if(i >= 3) maximize(f[i][j][t], f[i - 3][j][t - 1] + 1ll * neg[i - 2] * neg[i] * neg[i - 1]);
                    // cerr << i << " " << j << " " << t << ": " << f[i][j][t] << "\n";
                }
            }
        }
        cout << f[numNeg][numPos][3];
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
