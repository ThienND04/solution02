#include<bits/stdc++.h>

using  namespace std;

typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "table"
#define inf 1e9
#define maxn 200
#define reset(a) memset(a, 0, sizeof(a))

int m, n, s, t, sr = 0, sc = 0;
int r[maxn], c[maxn], d[maxn][maxn], f[maxn][maxn], q[maxn  * 2], tr[maxn];
vector<int> adj[maxn];
int res = 0;

void init(){
    cin >> m >> n;
    s = m + n + 1;
    t = m + n + 2;
    for(int i = 1; i <= m; i ++) cin >> r[i];
    for(int i = 1; i <= n; i ++) cin >> c[i];
    for(int i = 1; i <= m; i ++){
        sr += r[i];
        adj[s].push_back(i);
        adj[i].push_back(s);
        d[s][i] = r[i];
        for(int j  = 1; j <= n; j ++){
            d[i][j + m] = 1;
            adj[i].push_back(j + m);
            adj[j + m].push_back(i);
        }
    }
    for(int i = 1; i <= n; i ++){
        d[i + m][t] = c[i];
        sc += c[i];
        adj[t].push_back(i + m);
        adj[i + m].push_back(t);
    }
}

void BFS(){
    reset(tr);
    // tr[s] = -1;
    int lf = 1, rt = 0;
    q[++ rt] = s;
    while(lf <= rt){
        int u  = q[lf ++];
        for(int v: adj[u]){
            if(! tr[v] && f[u][v] < d[u][v]){
                tr[v] = u;
                q[++ rt] = v;
            }
        }
    }
}

bool findPath(){
    BFS();
    return tr[t];
}

void incrFlow(){
    int v = t;
    int delta = inf;
    while(v != s){
        delta = min(delta, d[tr[v]][v] - f[tr[v]][v]);
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

void solve(){
    while(findPath()){
        incrFlow();
    }
    if(! (res == sr && res == sc)) {
        cout << -1;
        return ;
    }
    for(int u = 1; u <= m; u ++){
        for(int v = 1; v <= n; v ++){
            if(f[u][v + m]){
                f[s][u] --;
                f[v + m][t] --;
                if(findPath()){
                    incrFlow();
                    f[u][v + m] = 2;
                }
                else{
                    f[s][u] ++;
                    f[v + m][t] ++;
                }
            }
            else f[u][v + m] = 2;
        }
    }
    for(int u = 1; u <= m; u ++){
        for(int v = 1; v <= n; v ++){
            if(f[u][v + m] == 1) cout << 1;
            else cout << 0;
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    //
    init();
    solve();
    return 0;
}