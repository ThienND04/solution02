#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bai3"
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
    int subtask, num = 0;
    int n, t, q;
    vector<int> adj[maxn];
    int id[maxn], par[maxn], h[maxn], cnt[3][maxn];

    void DFS(int u){
        for(int v: adj[u]){
            if(par[v] == 0) {
                par[v] = u;
                h[v] = h[u] + 1;
                DFS(v);
            }
        }
        id[u] = ++num;
    }

    int lca(int u, int v){
        if(h[u] < h[v]) swap(u, v);
        while(h[u] > h[v]) u = par[u];
        while(u != v){
            u = par[u];
            v = par[v];
        }
        return u;
    }

    int path[maxn];
    bool calc(int _u, int _v){
        num = 0;
        int u = _u, v = _v;
        if(id[u] > id[v]) swap(u, v);
        int l = lca(u, v);
        cnt[0][u] ++;
        while(u != l){
            cnt[1][u] ++;
            u = par[u];
        }
        cnt[2][v] --;
        while(v != l){
            path[++ num] = v;
            cnt[1][v] ++;
            v = par[v];
        }
        path[++ num] = l;
        cnt[1][l] ++;
        reverse(path + 1, path + num + 1);
        u = _u; v = _v;
        int s = 0, d = cnt[0][u] - cnt[1][u];
        while(u != l){
            s += cnt[0][u];
            if(s - cnt[1][u] != d) return 0;
            s += cnt[2][u];
            u = par[u];
            if(s < 0) return 0;
        }
        for(int i = 1; i <= num; i ++){
            u = path[i];
            s += cnt[0][u];
            if(s - cnt[1][u] != d) return 0;
            s += cnt[2][u];
            if(s < 0) return 0;
        }
        return 1;
    }

    bool solve(){
        reset(cnt);
        cin >> q;
        while(q --){
            int u, v;
            cin >> u >> v;
            if(! calc(u, v)) return 0;
        }
        return 1;
    }

    void process(){
        cin >> subtask >> n;
        reset(par);
        for(int i = 1; i <= n - 1; i ++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); 
            adj[v].push_back(u);
        }
        h[1] = 0; par[1] = -1; 
        DFS(1);
        cin >> t;
        while(t --){
            if(solve()) cout << "RO RANG\n";
            else cout << "MAP MO\n";
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
