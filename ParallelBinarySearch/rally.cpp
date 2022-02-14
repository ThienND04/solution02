#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "rally"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

class DSU{
private:
    int n;
    vector<int> par, num;

public:
    void Reset(){
        for(int i = 0; i <= n; i ++) par[i] = i;
        for(int i = 0; i <= n; i ++) num[i] = 1;
    }

    DSU(){}
    DSU(int _n): n(_n){
        par.resize(n + 1);
        //for(int i = 0; i <= n; i ++) par[i] = i;
        num.resize(n + 1);
        //for(itn i = 0; i <= n; i ++) num[i] = 1;
        Reset();
    }

    int root(int u){
        if(par[u] == u) return u;
        return (par[u] = root(par[u]));
    }

    void join(int u, int v){
        u = root(u); v = root(v);
        if(u == v) return;
        par[u] = v;
        num[v] += num[u];
    }

    int sum(int u, int v){
        u = root(u); v = root(v);
        if(u == v) return num[u];
        return num[u] + num[v];
    }
};

struct Query{
    int x, y, z;
};

namespace process{
    int n, m, q;
    int L[maxn], R[maxn];
    pii Edge[maxn];
    Query queries[maxn];

    vector<int> gr[maxn];

    void process(){
        cin >> n >> m;
        reset(L);
        for(int i = 1; i <= m; i ++) {
            cin >> Edge[i].first >> Edge[i].second;
        }
        cin >> q;
        for(int i = 1; i <= q; i ++){
            cin >> queries[i].x >> queries[i].y >> queries[i].z;
            R[i] = m;
        }
        DSU ds(n);
        for(int t = log2(m) + 3; t >= 0; t --){
            for(int i = 1; i <= q; i ++){
                if(R[i] - L[i] > 1) {
                    gr[(L[i] + R[i]) / 2].push_back(i);
                }
            }
            for(int i = 1 ; i <= m; i ++){
                ds.join(Edge[i].first, Edge[i].second);

                for(int k: gr[i]){
                    int x = queries[k].x, y = queries[k].y, z = queries[k].z;
                    if(ds.sum(x, y) >= z) R[k] = i;
                    else L[k] = i;
                }
                gr[i].clear();
            }
            ds.Reset();
        }
        for(int i = 1; i <= q; i ++) cout << R[i] << "\n";
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