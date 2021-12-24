#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "m"
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
    int n, m;

    int par[maxn];
    int num[maxn];

    int findPar(int u){
        if(u == par[u]) return u;
        return (par[u] = findPar(par[u]));
    }

    void join(int u, int v){
        u = findPar(u), v = findPar(v);
        if(u == v) return;
        par[u] = v;
        num[v] += num[u];
    }

    void process()
    {
        cin >> n >> m;
        for(int i = 0; i <= n; i ++) {
            par[i] = i;
            num[i] = 1;
        }
        while(m --){
            int u, v;
            cin >> u >> v;
            join(u, v);
        }
        int res = 0;
        for(int i = 0; i <= n; i ++){
            if(par[i] == i && num[i] > 2){
                int s = 1;
                for(int j = 2; j <= num[i]; j ++) s = (1ll * s * j) % mod;
                add(res, s);
            }
        }
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
