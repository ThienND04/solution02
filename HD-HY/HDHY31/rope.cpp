 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "rope"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

namespace caculate{
    template<class T>
    void add(T& x, T y){
        x += y;
        if(x >= mod) x -= mod;
    }
    template<class T>
    void sub(T& x, T y){
        x -= y;
        if(x < 0) x += mod;
    }
    template<class T>
    void maximize(T& x, T y){
        if(x < y) x = y;
    }
    template<class T>
    void minimize(T& x, T y){
        if(x > y) x = y;
    }
}

using namespace caculate;

namespace process{
    int n, m;
    vector<int> adj[maxn];
    int h[maxn], f[maxn], res = 0;
    bool visited[maxn];

    void MAX(int& maxFirst, int& maxSecond, int x){
        if(x > maxFirst){
            maxSecond = maxFirst;
            maxFirst = x;
        }
        else maximize(maxSecond, x);
    }

    void DFS(int u, int par){
        int maxFirst = -1, maxSecond = -1;

        f[u] = 0;
        visited[u] = 1;

        for(int v: adj[u]){
            if(v == par) continue;
            h[v] = h[u] + 1;
            DFS(v, u);
            maximize(f[u], f[v] + 1);
            MAX(maxFirst, maxSecond, f[v] + 1);
        }

        maximize(res, h[u]);
        maximize(res, maxFirst + maxSecond);
    }

    void process(){
        cin >> n >> m;

        while(m --){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        reset(visited);
        for(int i = 1; i <= n; i ++){
            if(! visited[i]) DFS(i, -1);
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
