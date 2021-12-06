#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "a"
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
    int n, t;
    int a[maxn];
    void process(){
        cin >> t >> n;
        while(t -- ){
            for(int i = 1; i <= 3 * n; i ++) cin >> a[i];
            sort(a + 1, a + 3 * n + 1);
            int lf = 1, rt = 3 * n;
            int res = 0;
            while(lf < rt){
                // if((a[rt] - a[lf]) * a[rt - 1] > (a[rt - 1] - a[lf]) * a[rt]) 
                res += max((a[rt] - a[lf]) * a[rt - 1], (a[rt - 1] - a[lf]) * a[rt]);
                lf ++;
                rt -= 2;
            }
            cout << res << "\n";
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
