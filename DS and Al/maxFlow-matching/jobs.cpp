#include<bits/stdc++.h>

using  namespace std;

typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "jobs"
#define inf 1e9
#define maxn 1009

int n, m, s, t;
int c[maxn][maxn], f[maxn][maxn], job[maxn][maxn];
vector<int> adj[maxn];

int tr[maxn * 3], dq[maxn * 3];

void Add(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
    c[u][v] = 1;
}

void init(){
    cin >> m >> n;
    s = n + m + 1, t = n + m + 2;
    for(int i = 1; i <= n; i ++){
        int v;
        while(cin >> v){
            if(v == 0) break;
            Add(i, v + n);
        }
        adj[s].push_back(i);
        adj[i].push_back(s);
    }
    for(int v = 1; v <= m; v ++){
        Add(v + n, t);
    }
}

void bfs(){
    int l = 1, r = 0;
    dq[++ r] = s;
    while(l <= r){
        int u = dq[l ++];
        for(int v: adj[u]){
            if(! tr[v] && f[u][v] < c[u][v]) {
                dq[++ r] = v;
                tr[v] = u;
            }
        }
    }
}

bool findPath(){
    reset(tr);
    tr[s] = -1;
    bfs();
    return tr[t];
}

void incrFlow(int& sum){
    int v = t, delta = inf;
    while(v != s){
        delta = min(delta, c[tr[v]][v] - f[tr[v]][v]);
        v = tr[v];
    }
    v = t;
    while(v != s){
        f[tr[v]][v] += delta;
        f[v][tr[v]] -= delta;
        job[tr[v]][v] = 1;
        job[v][tr[v]] = 0;
        v = tr[v];
    }
    sum += delta;
}

bool check(int x){
    int res = 0;
    reset(f);
    reset(job);
    for(int i = 1; i <= n; i ++){
        c[s][i] = x;
    }
    while(findPath()){
        incrFlow(res);
    }
    return (res == m);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    int l = -1, r = 5000;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    if(! check(r)) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n" << r << "\n";
    for(int i = 1; i <= n; i ++){
        for(int j = n + 1; j <= n + m; j ++){
            if(job[i][j]) cout << j - n << " ";
        }
        cout << 0 << "\n";
    }
    return 0;
}