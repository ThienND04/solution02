#include<bits/stdc++.h>

using  namespace std;

typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "mafia"
#define inf 1e9
#define maxn 1000

int n, m, s, t;
int c[maxn][maxn], f[maxn][maxn];
int tr[maxn], dq[maxn * 2], l = 1, r = 0, res = 0;
vector<int> adj[maxn];

void init(){
    cin >> n >> m >> s >> t;
    t += n;
    reset(c);
    reset(f);
    for(int i = 1; i <= n; i ++){
        cin >> c[i][i + n];
        adj[i].push_back(i + n);
        adj[i + n].push_back(i);
    }
    while(m --){
        int u, v;
        cin >> u >> v;
        c[u + n][v] = inf;
        c[v + n][u] = inf;
        adj[u + n].push_back(v);
        adj[v].push_back(u + n);
        adj[v + n].push_back(u);
        adj[u].push_back(v + n);
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
    tr[s] = -1;
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
    reset(tr);
    tr[s] = -1;
    BFS();
    vector<int> tmp;
    for(int i = 1; i <= n; i ++){
        if(tr[i] && ! tr[i + n]){
            tmp.push_back(i);
        }
    }
    cout << tmp.size() << "\n";
    for(int i: tmp) cout << i << " ";
    cerr << res;
    return 0;
}