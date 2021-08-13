#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "f"
#define maxn 100001
#define bit(x, i) ((x >> i) & 1)

int n, m, k;
int a[maxn];
ll f[maxn][33];
vector<pii> adj;

void init(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] --;
    }
    while(m --){
        int u, v;
        cin >> u >> v;
        adj.push_back({u, v});
    }
    for(int i = 1; i <= n; i ++){
        f[i][1 << a[i]] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();
    for(int i = 1; i < (1 << k); i ++){
        for(pii e: adj){
            int u = e.first, v = e.second;
            if(bit(i, a[u]) && !bit(i, a[v]))  f[v][i + (1 << a[v])] += f[u][i];
            if(bit(i, a[v]) && !bit(i, a[u]))  f[u][i + (1 << a[u])] += f[v][i];
        }
    }
    ll res = 0;
    for(int i = 1; i < (1 << k);  i++){
        if(__builtin_popcount(i) < 2) continue;
        for(int j = 1; j <= n; j ++) res += f[j][i];
    }
    cout << res;
    return 0;
}
