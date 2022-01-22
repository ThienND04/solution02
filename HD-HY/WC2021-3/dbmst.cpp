#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "dbmst"
#define inf 1e9
#define mod 1000000007
#define maxn 26

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

struct Edge{
    int u, v;
    ll w;
};

bool cmp(Edge& a, Edge& b){
    return a.w < b.w;
}

namespace process{
    int n, m;
    ll k;
    int par[maxn];
    Edge edges[maxn];
    vector<pii> adj[maxn];
    ll res = -1, dist[maxn][maxn];

    void resetU(){
        for(int i = 1; i <= n; i ++) par[i] = i;
    }

    int root(int u){
        if(par[u] == u) return u;
        return (par[u] = root(par[u]));
    }

    void join(int u, int v){
        par[root(u)] = root(v);
    }

    void IJK(int s){
        memset(dist[s], 99, sizeof(dist[s]));
        dist[s][s] = 0;
        queue<int> q;
        q.push(s);
        while(! q.empty()){
            int u = q.front();
            ll l = dist[s][u];
            q.pop();
            if(l != dist[s][u]) continue;
            for(pii e: adj[u]){
                int v = e.first, w = e.second;
                if(l + w < dist[s][v]){
                    dist[s][v] = l + w;
                    q.push(v);
                }
            }
        }
    }

    void init(){
        cin >> n >> m >> k;
        resetU();
        for(int i = 1; i <= m; i ++) cin >> edges[i].u >> edges[i].v >> edges[i].w;
        sort(edges + 1, edges + m + 1, cmp);
        // for(int i = 1; i <= n; i ++){
        //     if(root(edges[i].u) != root(edges[i].v)){
        //         join(edges[i].u, edges[i].v);
        //         mst += edges[i].w;
        //     }
        // }
    }

    int ls[maxn];

    bool calc(){
        resetU();
        for(int i = 1; i <= n; i ++) adj[i].clear();
        for(int i = 1; i <= n - 1; i ++){
            int u = edges[ls[i]].u, v = edges[ls[i]].v, w = edges[ls[i]].w;
            if(root(u) == root(v)) return 0;
            join(u, v);
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }
        ll maxRes = 0;
        for(int i = 1; i <= n; i ++){
            IJK(i);
            for(int j = 1; j <= n; j ++){
                maximize(maxRes, dist[i][j]);
            }
        }
        return (maxRes <= k);
    }

    void Try(int pos, int num, ll sum){
        if(pos == m + 1 && num == n){
            if(num == n) {
                if(calc()){
                    if(res == -1 || sum < res) res = sum;
                }
            }
            return;
        }
        if(pos == m + 1) return;
        if(m - pos + 1 < n - num) return;
        if(num > n) return;
        ls[num] = pos;
        Try(pos + 1, num + 1, sum + edges[pos].w);
        Try(pos + 1, num, sum);
    }

    void process(){
        init();
        // cerr << mst;
        Try(1, 1, 0);
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
