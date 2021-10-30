#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "ex4"
#define maxn 300300
#define inf 1000000007
#define mod 998244353 

int subtask;
int n, numRoad, num = 0, ti = 0;
pii road[maxn];
vector<int> adj[maxn];
int par[maxn], low[maxn], id[maxn];
int in[maxn], out[maxn], res[maxn];
bool isCut[maxn];

#define numNode(u) ((out[u] - in[u] + 1) / 2)

void add(int& x1, int x2){
    x1 += x2;
    if(x1 >= mod) x1 -= mod;
}

void DFS(int u){
    int child = (par[u] != -1);
    res[u] = 0;
    int s = num;
    low[u] = id[u] = ++ num;
    in[u] = ++ ti;
    for(int v: adj[u]){
        if(v != par[u]){
            if(id[v] != 0) low[u] = min(low[u], low[v]);
            else{
                par[v] = u;
                DFS(v);
                low[u] = min(low[u], low[v]);
                if(low[v] >= id[u]) {
                    child ++;
                    add(res[u], (1ll * s * numNode(v)) % mod);
                    s += numNode(v);
                }
            }
        }
    }
    out[u] = ++ti;
    if(child >= 2) isCut[u] = 1;
    else res[u] = 0;
}

void solve2()
{
    for(int i = 1; i <= numRoad; i ++){
        int u = road[i].first, v = road[i].second;
        if(id[u] > id[v]) swap(u, v);
        if(low[v] >= id[v]) cout << (1ll * (n - numNode(v)) * numNode(v)) % mod << " ";
        else cout << 0 << " ";
    }
}

void solve1(){
    for(int i = 1; i <= n; i ++){
        cout << res[i] << " ";
    }
    cout << "\n";
}

void init()
{
    cin >> subtask >> n >> numRoad;
    for(int i = 1; i <= numRoad; i ++){
        int u, v;
        cin >> u >> v;
        road[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(par, -1, sizeof(par));
    DFS(1);
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
    solve1();
    solve2();
    return 0;
}