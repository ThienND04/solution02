#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "travel"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

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
    int n, m, k;
    vector<int> ke[maxn];
    vector<pii> adj[maxn];
    int low[maxn], id[maxn], par[maxn];
    bool bright[maxn], chon[maxn];

    void prepare(int u){
        static int num = 0;
        id[u] = low[u] = ++num;
        for(int v: ke[u]){
            if(v == par[u]) continue;
            if(! par[v]){
                par[v] = u;
                prepare(v);
                low[u] = min(low[u], low[v]);
                if(low[v] > id[u]){
                    adj[u].push_back({v, 1});
                }
                else{
                    adj[u].push_back({v, 0});
                }
            }
            else low[u] = min(low[u], id[v]);
        }
    }
    void calc(int u){
        for(pii e: adj[u]){
            int v = e.first;
            calc(v);
        }
    }

    void DFS(int u){
        calc(u);
        for(pii e: adj[u]){
            int v = e.first;
            DFS(v);
        }
    }

    void init(){
        cin >> n >> m >> k;
        for(int i = 1; i <= m; i ++){
            int u, v;
            cin >> u >> v;
            ke[u].push_back(v);
            ke[v].push_back(u);
        }
    }

    void process(){
        init();
        par[1] = -1;
        prepare(1);
        DFS(1);
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
