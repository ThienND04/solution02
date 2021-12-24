#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "e"
#define maxn 100001
#define reset(a) memset(a, 0, sizeof(a));
#define inf 1000000000000000000

int n;
vector<pii> adj[maxn];
ll p[maxn], s[maxn], t[maxn], c[maxn];
bool visited[maxn];
ll sum = 0;

void dfs1(int u){
    s[u] = p[u];
    visited[u] = 1;
    for(pii e: adj[u]){
        int v = e.first, w = e.second;
        if(! visited[v]){   
            dfs1(v);
            s[u] += s[v];
            t[u] += t[v] + s[v] * w;
        }
    }
    visited[u] = 0;
}

void dfs2(int u){
    visited[u] = 1;
    for(pii e: adj[u]){
        int v = e.first, w = e.second;
        if(! visited[v]) {
            c[v] = c[u] + t[u] - t[v] - s[v] * w + w * (sum - s[v]);
            dfs2(v);
        }
    }
    visited[u] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n - 1; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for(int i = 1; i <= n; i ++) {
        cin >> p[i];
        sum += p[i];
    }
    dfs1(1);
    reset(visited);
    reset(c);
    dfs2(1);
    ll res1 = inf, res2 = 0;
    for(int i = 1; i <= n; i ++){
        res2 = max(res2, t[i] + c[i]);
        res1 = min(res1, t[i] + c[i]);
    }
    cout << res1 << " " << res2 << endl;
    return 0;
}