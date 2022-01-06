#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "majornum"
#define inf 1e9
#define mod 1000000007
#define maxn 7001

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
    int n, m;
    int a[maxn], cnt[maxn][maxn];

    void init(){
        cin >> n >> m;
        reset(cnt);
        vector<int> b(n);

        for(int i = 1; i <= n; i ++) {
            cin >> a[i];
            b[i - 1] = a[i];
        }
        sort(b.begin(), b.end());
        for(int i = 1; i <= n; i ++){
            a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++) cnt[i][j] = cnt[i - 1][j];
            cnt[i][a[i]] ++;
        }
    }

    bool ok(int l, int r){
        for (int i = l; i <= r; i++)
        {
            if (cnt[r][a[i]] - cnt[l - 1][a[i]] > (r - l + 1) / 2) return 1;
        }
        return 0;
    }

    void process()
    {
        init();
        while(m --){
            int l, r;
            cin >> l >> r;
            cout << ok(l, r) << "\n";
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
