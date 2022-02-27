#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "deltree"
#define inf 1e9
#define mod 1000000007
#define maxn 300300

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
    string s;
    int color[maxn], f[2][maxn];
    vector<int> adj[maxn];

    void DFS(int u, int par){
        f[0][u] = f[1][u] = 1;
        f[! color[u]][u] ++;
        for(int v: adj[u]){
            if(v == par) continue;
            DFS(v, u);
            if(f[0][v] - 1 < f[1][v]) f[0][u] += f[0][v] - 1;
            else f[0][u] += f[1][v];

            if(f[1][v] - 1 < f[0][v]) f[1][u] += f[1][v] - 1;
            else f[1][u] += f[0][v];
        }
    }

    void process()
    {
        cin >> n >> s;
        s = "0" + s;
        for(int i = 1; i <= n; i ++) color[i] = s[i] - '0';
        for(int i = 1; i < n; i ++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        DFS(1, -1);
        cout << min(f[0][1], f[1][1]);
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
