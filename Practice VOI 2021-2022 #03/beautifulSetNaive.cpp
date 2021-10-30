#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "beautifulSet"
#define inf 1e9
#define mod 1000000007
#define maxn 2001

#define bit(x, i) ((x >> i) & 1)

// subtask 1

int n, q;
int color[maxn];
vector<int> adj[maxn];
int cnt[maxn][maxn], s[maxn], hight[maxn], par[maxn];
int d[maxn];

void init(){
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) cin >> color[i];
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
    for(int v: adj[u]) {
        if(v == par[u]) continue;
        hight[v] = hight[u] + 1;
        par[v] = u;
        DFS(v);
        s[u] += s[v];
        for(int i = 1; i <= n; i ++){
            cnt[u][i] += cnt[v][i];
        }
    }
}

int query1(int u){
    int l = s[u] / 2 + 1;
    for(int i = 1; i <= n; i ++){
        if(cnt[u][i] >= l) return i;
    }
    return -1;
}

int query2(int u){
    int l = (n - s[u]) / 2 + 1;
    for(int i = 1; i <= n; i ++){
        if(cnt[1][i] - cnt[u][i] >= l) return i;
    }
    return -1;
}

int query3(int u, int v){
    reset(d);
    int numVer = 0;
    if(hight[u] < hight[v]) swap(u, v);
    while(hight[u] > hight[v]){
        d[color[u]] ++;
        numVer ++;
        u = par[u];
    }
    while (u != v)
    {
        d[color[u]] ++;
        numVer ++;
        u = par[u];
        d[color[v]] ++;
        numVer ++;
        v = par[v];
    }
    d[color[u]]++;
    numVer++;
    int l = numVer / 2 + 1;
    for(int i = 1; i <= n; i ++){
        if(d[i] >= l) return i;
    }
    return -1;
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