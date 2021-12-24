#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "subset"
#define inf 1e9
#define mod 1000000007
#define maxn 20

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
    int a[maxn], res[100001], cnt = 0;
    bool ok[maxn][maxn * 30][maxn * 30];
    void process(){
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        reset(ok);
        ok[0][0][0] = 1;
        for(int i = 1; i <= n; i ++){
            for(int s1 = 0; s1 < maxn * 30; s1 ++){
                for(int s2 = 0; s2 < maxn * 30; s2 ++){
                    if(! ok[i - 1][s1][s2]) continue;
                    ok[i][s1][s2] = 1;
                    ok[i][s1 + a[i]][s2] = 1;
                    ok[i][s1][s2 + a[i]] = 1;
                }
            }
        }
        for(int x = 1; x < maxn * 30; x ++){
            if(ok[n][x][x]) res[++ cnt] = x;
        }
        cout << cnt << "\n";
        for(int i = 1; i <= cnt; i ++) cout << res[i] << " ";
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
