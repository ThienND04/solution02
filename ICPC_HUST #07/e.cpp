#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "e"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

int n, m;
int p[maxn];
vector<int> adj[maxn];
bool visited[maxn], root[maxn], sign[maxn];
ll f[maxn];
ll res = 0;

void init(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) root[i] = 1;
    for(int i = 1; i <= n; i ++) cin >> p[i];
    for(int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        root[v] = 0;
        adj[v].push_back(u);
    }
    reset(visited);
    reset(f);
    reset(sign);
}

void signing(int u){
    sign[u] = 1;
    for(int v: adj[u]){
        if(! sign[v]) {
            signing(v);
        }
    }
}

void DFS(int u){
    f[u] = p[u];
    visited[u] = 1;
    for(int v: adj[u]){
        if(! visited[v]) {
            DFS(v);
        }
        if(! sign[v]) f[u] += f[v];
    }
    if(f[u] > 0){
        signing(u);
        res += f[u];
    }
}

void process(){
    for(int i = 1; i <= n; i ++){
        if(! visited[i]) DFS(i);
    }
    cout << res;
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
    process();
    return 0;
}