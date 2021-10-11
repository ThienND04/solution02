#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "g-longestpath"
#define maxn 100001
#define inf 1000000007
#define mod 998244353

int n, m;
vector<int> adj[maxn];
bool visited[maxn];
int res = 0;
int dp[maxn];

void dfs(int u){
    visited[u] = 1;
    for(int v: adj[u]){
        if(! visited[v]) dfs(v);
        dp[u] = max(dp[u], dp[v] + 1);
    }
    res = max(res, dp[u]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n >> m;
    reset(dp);
    while(m --){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i ++){
        if(! visited[i]) dfs(i);
    }
    cout << res;
    return 0;
}