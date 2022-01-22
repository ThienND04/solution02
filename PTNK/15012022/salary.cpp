#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "salary"
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
    int n, m, par[maxn], num = 0;
    int l[maxn], r[maxn];
    ll fenwichTree[maxn], w[maxn];
    vector<int> child[maxn];

    void DFS(int u){
        l[u] = ++num;
        // cerr << u << " ";
        for(int v: child[u]){
            DFS(v);
        }
        r[u] = num;
        // cerr << u << ": " << l[u] << " " << r[u] << "\n";
    }

    void update(int x, int d){
        for(; x < maxn; x += x & -x){
            fenwichTree[x] += d;
        }
    }

    ll get(int x){
        ll res = 0;
        for(; x > 0; x -= x & -x){
            res += fenwichTree[x];
        }
        return res;
    }

    void process(){
        reset(fenwichTree);
        cin >> n >> m >> w[1];
        par[1] = -1;
        for(int i = 2; i <= n; i ++)  {
            cin >> w[i] >> par[i];
            child[par[i]].push_back(i);
        }
        DFS(1);
        for(int i = 1; i <= m; i ++){
            char c;
            int u, x;
            cin >> c >> u;
            if(c == 'p'){
                cin >> x;
                update(l[u] + 1, x);
                update(r[u] + 1, -x);
                // cerr << "Update " << l[u] + 1 << " -> " << r[u] + 1 << " += " << x << "\n";
            }
            else{
                ll d = get(l[u]);
                // cerr << "Get " << l[u] << " = " << d << "\n";
                cout << d + w[u] << "\n";
            }
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
