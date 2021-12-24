#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "p"
#define inf 1e9
#define mod 1000000007
#define maxn 101

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
    int t;
    int dp[11][101][101][101];

    void calc(int u, int x, int y, int z){
        // maximize(dp[u][x][y][z], dp[u][x - 1][y][z]);
        // maximize(dp[u][x][y][z], dp[u][x][y - 1][z]);
        // maximize(dp[u][x][y][z], dp[u][x][y][z - 1]);
        if(x <= y && x <= z && x >= u){
            maximize(dp[u][x][y][z], y * z);
        }
        if(y <= x && y <= z && y >= u){
            maximize(dp[u][x][y][z], x * z);
        }
        if(z <= x && z <= y && z >= u){
            maximize(dp[u][x][y][z], x * y);
        }
        if(x > u){
            maximize(dp[u][x][y][z], dp[u][x - u][y][z] + dp[u][u][y][z]);
        }
        if (y > u)
        {
            maximize(dp[u][x][y][z], dp[u][x][y - u][z] + dp[u][x][u][z]);
        }
        if (z > u)
        {
            maximize(dp[u][x][y][z], dp[u][x][y][z - u] + dp[u][x][y][u]);
        }
    }

    void process()
    {
        reset(dp);
        for(int u = 1; u <= 10; u ++){
            for(int x = 1; x <= 100; x ++){
                for(int y = 1; y <= 100; y ++){
                    for(int z = 1; z <= 100; z ++){
                        calc(u, x, y, z);
                    }
                }
            }
        }

        cin >> t;
        while(t --){
            int x, y, z, u;
            cin >> x >> y >> z >> u;
            cout << dp[u][x][y][z] << "\n";
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
