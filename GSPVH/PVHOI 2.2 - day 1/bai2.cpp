#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bai2"
#define inf 1e9
#define mod 1000000007
#define maxn 101

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

class DSU{
public:
    int n;
    vector<int>par;

    DSU(){}

    void init(){
        for(int i = 1; i <= n; i ++) par[i] = i;
    }

    DSU(const int& _n){
        n = _n;
        par.resize(n + 1);
        init();
    }
    int root(int u){
        if(u == par[u]) return u;
        return (par[u] = root(par[u]));
    }
    bool join(int u, int v){
        u = root(u);
        v = root(v);
        if(u == v) return 0;
        par[u] = v;
        return 1;
    }
};

namespace process{
    int n, m;
    ll k;
    pii st[maxn];
    bool visted[maxn], pc[maxn];
    int ke[maxn];

    ll cnt(int curPos, int last){
        if(curPos == n - 1) return 1;
        ll res = 0;
        DSU tmp(n);
        for(int x = 0; x < (1 << m); x ++){
            int cnt = __builtin_popcount(x), ok = 1;
            ll sum = 1;
            reset(pc); reset(ke);
            tmp.init();
            
            for(int i = 0; i < m; i ++){
                if(! bit(x, i)) continue;
                int u = st[i].first, v = st[i].second;
                if(visted[u] || visted[v]) continue;
                if(! tmp.join(u, v)) {
                    ok = 0;
                    break;
                }
                ke[u] ++; ke[v] ++;
            }

            int cnt = 0;
            for(int i = 1; i <= n; i ++){
                if(ke[i] > 2) ok = 0;
                if(tmp.root(i) == i || pc[tmp.root(i)]) continue;
                cnt ++;
                pc[tmp.root(i)] = 1;
                sum *= 2;
            }
            for(int i = 1; i <= n; i ++){
                if(! visted[i] && ! pc[tmp.root(i)]) cnt ++; 
            }
            for(int i = 1; i <= cnt; i ++){
                
            }
        }
    }   

    void process(){
        cin >> n >> m >> k;
        for(int i = 0; i < m; i ++)  cin >> st[i].first >> st[i].second;

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
