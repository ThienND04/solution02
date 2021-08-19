#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "kiosks"
#define maxn 10001
#define inf 1000000007
#define mod 1000000007

int n, k;
int c[maxn], par[maxn];
pii ed[maxn];
int res = 0;

bool visited[maxn], co[maxn];

int root(int u){
    if(par[u] == u) return u;
    return (par[u] = root(par[u]));
}

void join(int u, int v){
    par[u] = v;
}

bool check(){
    int cnt = 0;
    memset(co, 0, sizeof(co));
    for(int i = 1; i <= n; i ++) par[i] = i;
    for(int i = 1; i <= n; i ++){
        if(visited[i]){
            cnt ++;
            co[c[i]] = 1;
        }
    }
    for(int i = 1; i <= k; i ++){
        if(! co[i]) return 0;
    }
    for(int i = 1; i < n; i ++){
        int u = ed[i].first, v = ed[i].second;
        if(visited[u] && visited[v]){
            if(root(u) != root(v)){
                join(u, v);
                cnt --;
            }
        }
    }
    return (cnt == 1);
}

void duyet(int p){
    if(p > n){
        res += check();
        return;
    }
    visited[p] = 1;
    for(int i = p + 1; i <= n + 1; i ++){
        duyet(i);
    }
    visited[p] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> c[i];
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        ed[i] = {u, v};
    }
    duyet(0);
    if(res) cout << res % mod;
    else cout << 1;
    return 0;
}