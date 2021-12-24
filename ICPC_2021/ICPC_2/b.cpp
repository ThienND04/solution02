#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "b"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

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

    int equalZero(){
        int res = 0;
        for(int i = 1; i <= n; i ++){
            if(a[i] == 0){
                if(res == 0) res = i;
                else return -1;
            }
        }
        return res;
    }

    int cntNeg(){
        int cnt = 0;
        for(int i = 1; i <= n; i ++){
            cnt += (a[i] < 0);
        }
        return cnt;
    }

    int getMaxNeg(){
        int res = 0;
        for(int i = 1; i <= n; i ++){
            if(a[i] < 0){
                if(res == 0)  res = i;
                else if(a[res] < a[i]) res = i;
            }
        }
        return res;
    }

    void process()
    {
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        int tmp = equalZero();
        if(tmp == -1){
            cout << 0;
            return;
        }
        else if(tmp) {
            int res = 1;
            for(int i = 1; i <= n; i ++){
                if(i != tmp) res = (1ll * res * a[i]) % mod;
            }
            maximize(res, 0);
            cout << res;
            return;
        }
        if(cntNeg() % 2 == 0){
            int res = 1;
            for (int i = 1; i <= n; i++)
            {
                res = (1ll * res * a[i]) % mod;
            }
            cout << res;
        }
        else{
            tmp = getMaxNeg();
            int res = 1;
            for (int i = 1; i <= n; i++)
            {
                if (i != tmp)
                    res = (1ll * res * a[i]) % mod;
            }
            cout << res;
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
