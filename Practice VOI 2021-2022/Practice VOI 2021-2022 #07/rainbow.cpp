#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "rainbow"
#define inf 1e9
#define mod 1000000009
#define maxn 1001

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
    int n, k;
    vector<int> adj[maxn];
    pii edge[maxn];
    int color[maxn][maxn], res = 0;
    bool ok = 1;

    void DFS(int u, int par, int parCo){
        for(int v: adj[u]){
            if(v == par) continue;
            if(color[u][v] == parCo){
                ok = 0;
                return;
            }
            DFS(v, u, color[u][v]);
            for(int v2: adj[u]){
                if(v2 == par) continue;
                if(v2 != v && color[v2][u] == color[v][u]){
                    ok = 0;
                    return;
                }
                for(int v3: adj[v2]){
                    if(v3 == u) continue;
                    if(color[v2][v3] == color[u][v] || color[v2][v3] == parCo){
                        ok = 0;
                        return;
                    }
                }
            }
        }
        
    }

    void Try(int pos){
        if(pos == n){
            ok = 1;
            DFS(1, -1, 0);
            if(ok) res ++;
            return;
        }
        for(int i = 1; i <= k; i ++) {
            color[edge[pos].first][edge[pos].second] = color[edge[pos].second][edge[pos].first] = i;
            Try(pos + 1);
        }
    }

    void sub1(){
        Try(1);
        cout << res;
    }

    void process(){
        cin >> n >> k;
        for(int i = 1; i < n; i ++) {
            int u, v;
            cin >> u >> v;
            edge[i] = {u, v};
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // if(n <= 8 && k <= 8){
            return sub1();
        // }
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
