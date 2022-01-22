 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "stree"
#define inf 1e9
#define mod 1000000007
#define maxn 200001

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

struct edge
{
    int u, v;
    bool select = 0;
};


namespace process{
    int n, m1, m2, k;
    edge red[maxn], blue[maxn];

    int par[maxn];

    int root(int u){
        if(par[u] == u) return u;
        return (par[u] = root(par[u]));
    }

    void join(int u, int v){
        u = root(u);
        v = root(v);
        par[u] = v;
    }

    void resetDSU(){
        for(int i = 1; i <= n; i ++) par[i] = i;
    }

    void process(){
        cin >> n >> m1 >> m2 >> k;
        for(int i = 1; i <= m1; i ++){
            cin >> blue[i].u >> blue[i].v;
        }
        for(int j = 1; j <= m2; j ++){
            cin >> red[j].u >> red[j].v;
        }
        resetDSU();
        for(int i = 1; i <= m2; i++){
            int u = red[i].u, v = red[i].v;
            if(root(u) != root(v)) join(u, v);
        }
        for(int i = 1; i <= m1; i ++){
            int u = blue[i].u, v = blue[i].v;
            if(root(u) != root(v)){
                join(u, v);
                blue[i].select = 1;
            }
        }
        resetDSU();
        for(int i = 1; i <= m1; i ++){
            int u = blue[i].u, v = blue[i].v;
            if(blue[i].select){
                join(u, v);
                k --;
            }
        }
        for(int i = 1; i <= m1 && k != 0; i ++){
            if(blue[i].select == 1) continue;
            int u = blue[i].u, v = blue[i].v;
            if(root(u) != root(v)) {
                join(u, v);
                blue[i].select = 1;
                k --;
            }
        }
        for(int i = 1; i <= m2; i++){
            int u = red[i].u, v = red[i].v;
            if(root(u) != root(v)) {
                join(u, v);
                red[i].select = 1;
            }
        }
        for(int i = 1; i <= m1; i ++){
            if(blue[i].select) cout << i << "\n";
        }
        for(int i = 1; i <= m2; i ++){
            if(red[i].select) cout << i << "\n";
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
