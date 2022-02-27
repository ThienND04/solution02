#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "dsur"
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

struct Query{
    int type, u, v;
};

class DSU{
private: 
    int n;
    vector<int> par;

public: 
    DSU(){ }
    DSU(int _n){
        n = _n;
        par.resize(n + 1);
        resetDSU();
    }

    void resetDSU(){
        for(int i = 1; i <= n; i ++) par[i] = i;
    }

    int root(int u, stack<pii>& pre){
        if(u == par[u]) return u;
        pre.push({u, par[u]});
        return (par[u] = root(par[u], pre));
    }

    void join(int u, int v, stack<pii>& pre){
        u = root(u, pre); v = root(v, pre);
        pre.push({u, par[u]});;
        par[u] = v;
    }

    void under(stack<pii>& pre){
        while(! pre.empty()){
            par[pre.top().first] = pre.top().second;
            pre.pop();
        }
    }

    bool sameSet(int u, int v, stack<pii>& pre){
        u = root(u, pre); v = root(v, pre);
        return (u == v);
    }
};

namespace process{
    int n, q;
    Query queries[maxn];
    vector<pii> seg[4 * maxn];
    DSU graph;

    void update(int node, int l, int r, int u, int v, pii d){
        if(u > r || v < l) return;
        if(u <= l &&  r <= v){
            seg[node].push_back(d);
            return;
        }
        int mid = (l + r) / 2;
        update(node * 2 + 1, l, mid, u, v, d);
        update(node * 2 + 2, mid + 1, r, u, v, d);
    }
    

    void solve(int node, int l, int r){
        stack<pii> pre;
        for(pii& e: seg[node]){
            graph.join(e.first, e.second, pre);
        }
        if(l == r){
            if(queries[l].type == 3) {
                if(graph.sameSet(queries[l].u, queries[l].v, pre)) cout << "YES\n";
                else cout << "NO\n";
            }
            graph.under(pre);
            return ;
        }
        int mid = (l + r) / 2;
        solve(node * 2 + 1, l, mid);
        solve(node * 2 + 2, mid + 1, r);
        graph.under(pre);
    }

    void init(){
        cin >> n >> q;
        graph = DSU(n);
        map<pii, int> mp;
        for(int i = 1; i <= q; i ++) {
            int t, u, v;
            cin >> t >> u >> v;
            if(u > v) swap(u, v);
            queries[i] = {t, u, v};

            pii tmp = {u, v};
            if(t == 1){
                if(mp.find(tmp) != mp.end() && mp[tmp] != 0) continue;
                mp[tmp] = i;
            }
            else if(t == 2){
                if(mp.find(tmp) == mp.end() || mp[tmp] == 0) continue;
                update(0, 1, q, mp[tmp], i - 1, tmp);
                mp[tmp] = 0;
            }
        }
        for(auto e: mp){
            if(e.second == 0) continue;
            else update(0, 1, q, e.second, q, e.first);
        }
    }

    void process(){
        init();
        solve(0, 1, q);
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
