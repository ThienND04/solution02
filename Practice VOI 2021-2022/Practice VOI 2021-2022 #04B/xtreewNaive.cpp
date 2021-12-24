#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "xtreew"
#define inf 1000000000
#define mod 1000000007
#define maxn 100001

int n;
vector<pii> adj[maxn];
ll s[maxn];
ll result = 0;

void DFS(int u, int par){
    result += s[u];
    for(pii e: adj[u]){
        int v = e.first, c = e.second;
        if(v == par) continue;
        s[v] = s[u] ^ c;
        DFS(v, u);
    }
}

void process(){
    cin >> n;
    for(int i = 0; i < n - 1; i ++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    for(int i = 1; i <= n; i ++){
        reset(s);
        DFS(i, -1);
    }
    cout << result / 2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    process();
    return 0;
}