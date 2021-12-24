#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "k"
#define inf 1e9
#define mod 1000000007
#define maxn 501

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
    int m, n, q;
    int a[maxn][maxn], v[maxn * maxn], cnt = 0;

    void process()
    {
        cin >> m >> n;
        for(int i = 1; i <= n * m; i ++){
            int x;
            cin >> x;
            v[++ cnt] = x;
        }
        sort(v + 1, v + cnt + 1, greater<int>());
        cnt = 0;
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                a[i][j] = v[++ cnt];
            }
        }
        cin >> q;
        while(q --){
            int x, y;
            cin >> x >> y;
            cout << a[x][y] << "\n";
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
