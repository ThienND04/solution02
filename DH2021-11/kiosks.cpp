#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "kiosks"
#define maxn 10001
#define inf 1000000007
#define mod 1000000007

int n, k, nset;
int c[maxn], f[maxn], q[maxn];
vector<int> adj[maxn];

void build(int u, int par = -1){
    for(int &v: adj[u]) {
        if(v == par) {
            v = adj[u].back();
            adj[u].pop_back();
            break;
        }
    }
    for(int v: adj[u]) build(v, u);
}

void init(){
    cin >> n >> k;
    nset = 1 << k + 1;
    for(int i = 1; i <= n; i ++){
        cin >> c[i];
        if(c[i] <= k) c[i] = 1 << c[i];
        else c[i] = 1;
    }
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    build(1);
}

void visit(int u, int s){
    for(int v: adj[u]) visit(v, s);
    if((c[u] & s) != c[u]) {
        f[u] = 0;
    }
    else{
        f[u] = 1;
        for(int v: adj[u]){
            f[u] = (f[u] + 1ll * f[u] * f[v]) % mod;
        }
    }
}

int calc(int s){
    int res = 0;
    for(int x = 0; x < nset; x ++){
        if((x & s) != x) continue;
        int t = __builtin_popcount(x ^ s);
        if(t % 2 == 0){
            
        }
    }
}

void solve(){
    for(int s = 0; s < nset; s ++){
        visit(1, s);
        q[s] = 0;
        for(int u = 1; u <= n; u ++) q[s] = (q[s] + f[u]) % mod;
    }
    int res = calc(nset - 1) + calc(nset - 2);

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();
    return 0;
}