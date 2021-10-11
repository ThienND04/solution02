#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "treeConstran"
#define maxn 51
#define reset(a) memset(a, 0, sizeof(a))
#define mod 1000000007

#define bit(x, i) ((x >> i) & 1)

int n, m;
vector<int> adj[maxn];
pii ed[maxn];
int par[maxn], h[maxn], cnt;
ll res = 0;
bool check[maxn];

void DFS(int u){
    for(int v: adj[u]){
        if(v != par[u]) {
            par[v] = u;
            h[v] = h[u] + 1;
            DFS(v);
        }
    }
}

void di(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    while(h[u] > h[v]){
        if(! check[u]) cnt ++;
        check[u] = 1;
        u = par[u];
    }
    while(u != v){
        if(! check[u]) cnt ++;
        check[u] = 1;
        u = par[u];
        if(! check[v]) cnt ++;
        check[v] = 1;
        v = par[v];
    }
}

void solve(){
    h[1] = 1;
    DFS(1);
    res = 0;
    for(int x = 0; x < (1 << m); x ++){
        cnt = 0;
        reset(check);
        for(int i = 0; i < m; i ++){
            if(bit(x, i)){
                di(ed[i].first, ed[i].second);
            }
        }
        int k = __builtin_popcount(x);
        ll tmp = 1ll << (n - cnt - 1);
        assert(tmp >= 0);
        if(k % 2 == 0) res += tmp;
        else res -= tmp;
    }
    // cout << (1 << ll(n - 1)) - res;
    // assert(res >= 0);
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    if(fopen(task ".inp", "r")) {freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);}
    cin >> n;
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> m;
    for(int i = 0; i < m; i ++) cin >> ed[i].first >> ed[i].second;
    solve();
    return 0;
}