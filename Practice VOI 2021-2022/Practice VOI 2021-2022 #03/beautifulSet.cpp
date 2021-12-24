#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "beautifulSet"
#define inf 1e9
#define mod 1000000007
#define maxn 50050

#define bit(x, i) ((x >> i) & 1)

#define LOG 21

const int T = 320;

int n, q;
int color[maxn], h[maxn], s[maxn], cnt[maxn];
int p[maxn][LOG], id[maxn];
vector<int> adj[maxn];
int cntTmp[maxn], cntColor[maxn][T], pColor[maxn][T];
int to[maxn], numTo = 0;

int tmp[maxn], numTmp = 0;

int verNgu = 0;

void DFS(int u, int par){  
    if(u == verNgu)  return;
    cntTmp[color[u]] ++;
    tmp[++ numTmp] = color[u];
    for(int v: adj[u]){
        if(v == par || v == verNgu) continue;
        DFS(v, u);
    }
}

void clearmen(){
    for(int i = 1; i <= numTmp; i ++) cntTmp[tmp[i]] = 0;
    numTmp = 0;
}

int query1(int u){
    int numVer = s[u];
    if(numVer <= 2 * T){
        clearmen();
        verNgu = 0;
        DFS(u, p[u][0]);
        for(int i = 1; i <= numTmp; i ++){
            assert(tmp[i]);
            if(cntTmp[tmp[i]] > numVer / 2) return tmp[i];
        }
        return -1;
    }
    for(int i = 1; i <= numTo; i ++){
        assert(to[i] != 0);
        if(cntColor[u][i] > numVer / 2) return to[i];
    }
    return -1;
}

int query2(int u){
    int numVer = n - s[u];
    if(numVer <= 2 * T){
        clearmen();
        verNgu = u; 
        DFS(1, 0);
        for(int i = 1; i <= numTmp; i ++){
            assert(tmp[i]);
            if(cntTmp[tmp[i]] > numVer / 2) return tmp[i];
        }
        return -1;
    }
    for(int i = 1; i <= numTo; i ++){
        assert(to[i] != 0);
        if(cntColor[1][i] - cntColor[u][i] > numVer / 2) return to[i];
    }
    return -1;
}

int lca(int u, int v){
    if(h[u] < h[v]) swap(u, v);
    int delta = h[u] - h[v];
    for(int i = 0; i < LOG; i ++){
        if(bit(delta, i)) u = p[u][i];
    }
    if(u == v) return u;
    for(int i = LOG - 1; i >= 0; i --){
        if(p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}

void diLen(int u, int v, int llca){
    while(u != llca){
        tmp[++ numTmp] = color[u];
        cntTmp[color[u]] ++;
        u = p[u][0];
    }
    while(v != llca){
        tmp[++ numTmp] = color[v];
        cntTmp[color[v]] ++;
        v = p[v][0];
    }
    cntTmp[color[llca]] ++;
    tmp[++ numTmp] = color[llca];
}

int query3(int u, int v){
    int llca = lca(u, v);
    int numVer = h[u] + h[v] - 2 * h[llca] + 1;
    if(numVer <= 2 * T){
        clearmen();
        diLen(u, v, llca);
        for(int i = 1; i <= numTmp; i ++){
            assert(tmp[i] != 0);
            if(cntTmp[tmp[i]] > numVer / 2) return tmp[i];
        }
        return -1;
    }
    for(int i = 1; i <= numTo; i ++){
        assert(to[i] != 0);
        if(pColor[u][i] + pColor[v][i] - 2 * pColor[llca][i] + (color[llca] == to[i]) > numVer / 2){
            return to[i];
        }
    }
    return -1;
}

void preDFS(int u, int par){
    s[u] = 1;
    pColor[u][id[color[u]]] = 1;
    for(int i = 1; i <= numTo; i ++) pColor[u][i] += pColor[par][i];
    cntColor[u][id[color[u]]] = 1;
    for(int v: adj[u]){
        if(v == par) continue;
        h[v] = h[u] + 1;
        p[v][0] = u;
        for(int i = 1; i < LOG; i++){
            p[v][i] = p[p[v][i - 1]][i - 1];
        }

        preDFS(v, u);
        s[u] += s[v];
        for(int i = 1; i <= numTo; i ++){
            cntColor[u][i] += cntColor[v][i];
        }
    }
}

void init(){
    cin >> n >> q;
    for(int i = 1; i <= n; i ++){
        cin >> color[i];
        cnt[color[i]] ++;
    }
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    reset(id);
    for(int i = 1; i <= n; i ++){
        if(cnt[i] > T) {
            to[++numTo] = i;
            id[i] = numTo;
        }
    }
}

void process(){
    reset(cntTmp);
    reset(p[1]);
    preDFS(1, 0);
    reset(cntTmp);
    while(q --){
        int t, u, v;
        cin >> t >> u;
        if(t == 1){
            cout << query1(u) << "\n";
        }
        else if(t == 2){
            cout << query2(u) << "\n";
        }
        else {
            cin >> v;
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