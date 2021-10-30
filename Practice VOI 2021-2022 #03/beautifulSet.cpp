#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "beautifulSet"
#define inf 1e9
#define mod 1000000007
#define maxn 50001

#define bit(x, i) ((x >> i) & 1)

#define LOG 21

// subtask 1

int n, q;
int color[maxn];
vector<int> adj[maxn], cnt[maxn];
int s[maxn], hight[maxn], par[maxn], nt[maxn][LOG];
int d[maxn];

int maxColor = 0;

void init(){
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) {
        cin >> color[i];
        maxColor = max(maxColor, color[i]);
    }
    for(int i = 1; i <= n; i ++) cnt[i].assign(maxColor + 1, 0);
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void DFS(int u){
    cnt[u][color[u]] = 1;
    s[u] = 1;
    nt[u][0] = par[u];
    for(int i = 1; i < LOG; i ++){
        nt[u][i] = nt[nt[u][i - 1]][i - 1];
    }
    for(int v: adj[u]) {
        if(v == par[u]) continue;
        hight[v] = hight[u] + 1;
        par[v] = u;
        DFS(v);
        s[u] += s[v];
        for(int i = 1; i <= maxColor; i ++){
            cnt[u][i] += cnt[v][i];
        }
    }
}

int query1(int u){
    int l = s[u] / 2 + 1;
    for(int i = 1; i <= maxColor; i ++){
        if(cnt[u][i] >= l) return i;
    }
    return -1;
}

int query2(int u){
    int l = (n - s[u]) / 2 + 1;
    for(int i = 1; i <= maxColor; i ++){
        if(cnt[1][i] - cnt[u][i] >= l) return i;
    }
    return -1;
}

int ok(int numVer){
    int l = numVer / 2 + 1;
    for(int i = 1; i <= maxColor; i ++){
        if(d[i] >= l) return i;
    }
    return -1;
}

int query3(int u, int v){
    if(u == v) return color[u];
    for(int i = 1; i <= maxColor; i ++) d[i] = 0;
    d[color[u]] ++;
    d[color[v]] ++;
    int numVer = 0;
    if(hight[u] < hight[v]) swap(u, v);
    int delta = hight[u] - hight[v];
    for(int i = 0; i < LOG; i ++){
        if(bit(delta, i)){
            for(int j = 1; j <= maxColor; j ++){
                d[j] += cnt[nt[u][i]][j] - cnt[u][j];
            }
            numVer += (1 << i);
            u = nt[u][i];
        }
    }

    if(u == v){
        return ok(numVer + 1);
    }
    
    for(int i = LOG - 1; i >= 0; i --){
        if(nt[u][i] != nt[v][i]){
            for(int j = 1; j <= maxColor; j ++){
                d[j] += cnt[nt[u][i]][j] - cnt[u][j];
            }
            numVer += (1 << i);
            u = nt[u][i];
            for(int j = 1; j <= maxColor; j ++){
                d[j] += cnt[nt[v][i]][j] - cnt[v][j];
            }
            numVer += (1 << i);
            v = nt[v][i];
        }
    }
    d[color[par[u]]] ++;
    numVer += 2;
    // cerr << ok(numVer + 1) << endl;
    return ok(numVer + 1);
}

void process(){
    DFS(1);
    while(q --){
        int t, u, v;
        cin >> t;
        if(t == 1){
            cin >> u;
            cout << query1(u) << "\n";
        }
        else if(t == 2){
            cin >> u;
            cout << query2(u) << "\n";
        }
        else {
            cin >> u >> v;
            cout << query3(u, v) << "\n";
        }
    }
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