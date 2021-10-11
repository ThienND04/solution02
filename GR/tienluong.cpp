#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a))
#define task "tienluong"
#define inf 1e9
#define maxn 100001
#define maxk 1001

int t;
int n, k, root;
int par[maxn], money[maxn];
int dp[maxn][maxk];
vector<int> child[maxn];

void DFS(int u, int par){
    for(int i = 0; i <= k; i ++) dp[u][i] = dp[par][i];
    for(int v: child[u]) DFS(v, u);
    for(int i = k; i > 0; i --){
        dp[par][i] = max(dp[u][i], dp[par][i - 1] + money[u]);
    }
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i <= n; i ++) child[i].clear();
    for(int i = 1; i <= n; i ++){
        int p, w;
        cin >> p >> w;
        par[i] = p;
        if(! p) root = i;
        child[p].push_back(i);
        money[i] = w;
    }
    for(int i = 0; i <= n; i ++){
        for(int j  = 0; j <= k; j ++) dp[i][j] = -inf;
    }
    dp[0][0] = 0;
    DFS(root, 0);
    cout << max(0, dp[0][k]) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){ freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);}
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}