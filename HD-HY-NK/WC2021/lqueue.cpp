#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "lqueue"
#define inf 1e9
#define mod 1000000007
#define maxn 200200

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
    int n, x, m;
    int a[maxn], cnt[maxn];

    void process()
    {
        cin >> n >> x;
        cnt[0] = 0;
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
        }
        cnt[0] = (a[0] >= x);
        for(int i = 1; i < n; i ++) {
            cnt[i] = cnt[i - 1] + (a[i] >= x);
        }
        int l = 0, r = n - 1;
        cin >> m;
        while(m --){
            int t, k;
            cin >> t;
            if(t == 1){
                r ++;
                cin >> a[r];
                cnt[r] = cnt[r - 1] + (a[r] >= x);
            }
            else if(t == 2){
                l ++;
            }
            else{
                cin >> k;
                int res = (l == 0? cnt[k]: cnt[k + l] - cnt[l - 1]) - (a[k + l] >= x);
                cout << res << "\n";
            }
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
