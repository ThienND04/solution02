#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "delseq"
#define inf 1e9
#define mod 1000000007
#define maxn 1001

#define maxbit 20

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
    int f[maxn][1024];

    void process(){
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        reset(f);
        for(int i = 1; i <= n; i ++){
            for(int s = 0; s <= i; s ++){
                f[i][s] = max(0, f[i - 1][s] + a[i]);
                for(int k = 0; (1 << k) <= i; k ++){
                    if(! bit(s, k)) continue;
                    maximize(f[i][s], f[i - (1 << k)][s ^ (1 << k)]);
                }
            }
        }
        // cout << *max_element(f[n] + 0, f[n] + 1024);
        int res = 0;
        for(int i = 1; i <= n; i ++)  maximize(res, *max_element(f[i], f[i] + i + 1));
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
