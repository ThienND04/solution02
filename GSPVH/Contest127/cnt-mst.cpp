#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "cnt-mst"
#define inf 1e9
#define mod 998244353
#define maxn 300003
#define bit(x, i) ((x >> i) & 1)

struct canh
{
    int u, v, c, id; 
};

int t, n, m;
int par[maxn], par2[maxn];
int ds[maxn], num = 0; // ds: history update DSU
canh ed[maxn];
vector<canh> block[maxn];

int root(int parent[], int u)
{
    ds[++ num] = u;
    if (u == parent[u])
        return u;
    return (parent[u] = root(parent, parent[u]));
}

void join(int parent[], int u, int v){
    parent[root(parent, u)] = v;
    ds[++ num] = u;
}

void init()
{
    cin >> t >> n >> m;
    vector<int> vt;
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        vt.push_back(c);
        ed[i] = {u, v, c, i};
    }
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        par2[i] = i;
    }
    sort(vt.begin(), vt.end());
    vt.resize(unique(vt.begin(), vt.end()) - vt.begin());
    for(int i = 1; i <= m; i ++){
        int u = lower_bound(vt.begin(), vt.end(), ed[i].c) - vt.begin() + 1;
        block[u].push_back(ed[i]);
    }
}

int solveBlock(int x){
    int cnt = 0;
    int res = 0;
    num = 0;
    for(canh e: block[x]){
        int u = root(par2, e.u), v = root(par2, e.v);
        if(u != v){
            cnt ++;
            join(par2, u, v);
        }
    }
    for(int i = 0; i < (1 << block[x].size()); i ++){
        if(__builtin_popcount(i) != cnt) continue;
        int cnt2 = cnt;
        for(int k = 1; k <= num; k ++) par2[ds[k]] = par[ds[k]];
        num = 0;

        // naive code
        // for(int i = 1; i <= n; i ++) par2[i] = par[i];

        for(int j = 0; j < block[x].size(); j ++){
            if(! bit(i, j)) continue;
            int u = root(par2, root(par, block[x][j].u));
            int v = root(par2, root(par, block[x][j].v));
            if(u != v){
                cnt2 --;
                join(par2, u, v);
            }
            else{
                cnt2 = 1;
                break;
            }
        }
        if(! cnt2) res ++;
    }
    for(int k = 1; k <= num; k ++) par2[ds[k]] = par[ds[k]];
    num = 0;
    for(canh e: block[x]){
        int u = root(par2, e.u), v = root(par2, e.v);
        if(u != v){
            join(par2, u, v);
        }
    }
    for(canh e: block[x]){
        int u = root(par, e.u), v = root(par, e.v);
        if(u != v){
            join(par, u, v);
        }
    }
    //for(int i = 1; i <= n; i ++) par2[i] = par[i]; // Naive
    if(res == 0) cerr << -1;
    return max(res, 1);
}

void solve(){
    init();
    int res = 1;
    for(int i = 1; i <= m; i ++){
        if(! block[i].empty()) res = (1ll * res * solveBlock(i)) % mod;
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
    solve();
    return 0;
}