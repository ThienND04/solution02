#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "a"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

namespace caculate
{
    template <class T>
    void add(T &x, T y)
    {
        x += y;
        if (x >= mod)
            x -= mod;
    }
    template <class T>
    void sub(T &x, T y)
    {
        x -= y;
        if (x < 0)
            x += mod;
    }
    template <class T>
    void maximize(T &x, T y)
    {
        if (x < y)
            x = y;
    }
    template <class T>
    void minimize(T &x, T y)
    {
        if (x > y)
            x = y;
    }
}

using namespace caculate;

namespace process
{
    int n;
    int a[maxn];

    bool ok(int i, int l, int r){
        if(i + r - l > n) return 0;
        for(int j = 0; j < r - l + 1; j ++){
            if(a[i + j] != a[l + j]) return 0;
        }
        return 1;
    }

    void process()
    {
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        int L = 0, R = 0, maxCnt = 0;
        
        for(int l = n; l >= 1; l --){
            for(int r = n; r >= l; r --){
                int cnt = 0;
                for(int p = 1; p <= n; p ++) cnt += ok(p, l, r);
                if(cnt > maxCnt || (cnt == maxCnt && r - l > R - L)) {
                    L = l;
                    R = r;
                    maxCnt = cnt;
                }
            }
        }
        cout << L << " " << R;
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
