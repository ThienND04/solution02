#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "f"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 27

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
    int t, n;
    string s;

    int lf[maxn][ALPHABET], rt[maxn][ALPHABET];
    int xh[ALPHABET];

    ll calc(){
        reset(xh);
        ll res = 0;
        for(int i = 1; i <= n; i ++){
            lf[i][s[i] - 'a'] = xh[s[i] - 'a'];
            xh[s[i] - 'a'] = i;
        }
        for(int i= 0; i < ALPHABET; i ++) xh[i] = n + 1;
        for(int i = n; i >= 1; i --){
            rt[i][s[i] - 'a'] = xh[s[i] - 'a'];
            xh[s[i] - 'a'] = i;
        }
        for(int i = 1; i <= n; i ++){
            res += 1ll * (i - lf[i][s[i] - 'a']) * (rt[i][s[i] - 'a'] - i);
        }
        return res;
    }

    void process()
    {
        cin >> t;
        while(t --){
            cin >> s;
            n = s.size();
            s = " " + s;
            cout << calc() << "\n";
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
