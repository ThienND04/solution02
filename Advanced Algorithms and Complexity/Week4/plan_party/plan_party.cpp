#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;
vector<vector<int>> adj;
vector<long long> f;
vector<int> par;

void DFS(int u){
    long long s1 = 0, s2 = 0;
    for(int v: adj[u]){
        if(v == par[u]) continue;
        par[v] = u;
        DFS(v);
        s1 += f[v];
    }
    s2 = a[u];
    for(int v: adj[u]){
        if(v == par[u]) continue;
        for(int w: adj[v]){
            if(w == u) continue;
            s2 += f[w];
        }
    }
    f[u] = max(s1, s2);
}

int main() {
    cin >> n;
    a.resize(n + 1);
    adj.resize(n + 1);
    f.resize(n + 1);
    par.resize(n + 1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1);
    cout << f[1];
    return 0;
}
