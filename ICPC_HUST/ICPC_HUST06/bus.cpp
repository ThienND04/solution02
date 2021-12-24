#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bus"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

struct road
{
    int u, v, cost;
};

int n, c, m;

int par[maxn];
road nr[maxn];

int root(int u){
    if(par[u] == u) return u;
    return (par[u] = root(par[u]));
}

bool join(int u, int v){
    int p1 = root(u), p2 = root(v);
    if(p1 == p2) return 0;
    par[p1] = p2;
    return 1;
}

void init(){
    cin >> n >> c >> m;
    for(int i = 1; i <= n; i ++) par[i] = i;
    while(c --){
        int u, v;
        cin >> u >> v;
        join(u, v);
    }
}

void process(){
    for(int i = 1; i <= m; i ++){
        cin >> nr[i].u >> nr[i].v >> nr[i].cost;
    }
    sort(nr + 1, nr + m + 1, [](road& r1, road& r2){return r1.cost < r2.cost; });
    ll res = 0;
    for(int i = 1; i <= m; i ++){
        if(join(nr[i].u, nr[i].v)){
            res += nr[i].cost;
        }
    }
    cout << res;
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
    init();
    process();
    return 0;
}