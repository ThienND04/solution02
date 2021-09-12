#include<bits/stdc++.h>

using  namespace std;

typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "a"
#define inf 1e9
#define maxn 1001

int n, m, s, t;
int c[maxn][maxn], f[maxn][maxn];
int tr[maxn], dq[maxn * 2], l = 1, r = 0, res = 0;
vector<int> adj[maxn];

void init(){
    cin >> n >> m >> s >> t;
    reset(c);
    reset(f);
    while(m --){
        int u, v;
        cin >> u >> v;
        cin >> c[u][v];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void BFS(){
    l = 1, r = 0;
    dq[++ r] = s;
    while(l <= r){
        int u = dq[l ++];
        for(int v: adj[u]){
            if(! tr[v] && f[u][v] < c[u][v]) {
                tr[v] = u;
                dq[++ r] = v;
            }
        }
    }
}

bool findPath(){
    reset(tr);
    BFS();
    return tr[t];
}

void incrFlow(){
    int delta = inf;
    int v = t;
    while(v != s){
        delta = min(delta, c[tr[v]][v] - f[tr[v]][v]);
        v = tr[v];
    }
    v = t;
    while(v != s){
        f[tr[v]][v] += delta;
        f[v][tr[v]] -= delta;
        v = tr[v];
    }
    res += delta;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    while(findPath()){
        incrFlow();
    }
    cout << res;
    return 0;
}