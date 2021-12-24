#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "pacman"
#define inf 1000000000000000000
#define mod 1000000007
#define maxn 21

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
    ll dist[maxn][maxn], level[maxn];
    ll dp[1048577];
    ll res = 0;

    void Floyd(){
        for(int i = 1; i <= n; i ++) dist[i][i] = 0;
        for(int k = 1; k <= n; k ++){
            for(int u = 1; u <= n; u ++){
                for(int v = 1; v <= n; v ++){
                    minimize(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }
    }

    bool check(){
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) {
                if(dist[i][j] > inf && level[i] && level[j]) return 0;
            }
        }
        return 1;
    }

    void process()
    {
        cin >> n >> m;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++ ) dist[i][j] = inf;
        }
        memset(dp, 99, sizeof(dp));
        reset(level);
        while(m --){
            ll u, v, c;
            cin >> u >> v >> c;
            level[u] ++;
            level[v] ++;
            minimize(dist[u][v], c);
            minimize(dist[v][u], c);
            res += c;
        }
        Floyd();
        if(! check()){
            cout << -1;
            // assert(0);
            return;
        }
        dp[0] = 0;
        for(int x = 0; x < (1 << n); x ++){
            for(int i = 1; i <= n; i ++){
                if((level[i] & 1) == 0)  continue;
                for(int j = i + 1; j <= n; j ++){
                    if((level[j] & 1) == 0) continue;
                    if(bit(x, i - 1) || bit(x, j - 1)) continue;
                    minimize(dp[x ^ (1 << i - 1) ^ (1 << j - 1)], dp[x] + dist[i][j]);
                }
            }
        }

        int mask = 0;
        for(int i = 1; i <= n; i ++){
            if(level[i] % 2 == 1) mask ^= (1 << i - 1);
        }
        assert(dp[mask] < inf);
        res += dp[mask];
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
