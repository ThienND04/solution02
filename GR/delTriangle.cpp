#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a))
#define task "delTriangle"
#define inf 1e9
#define maxn 100001

int n;
vector<int> ke[maxn], adj[maxn];
map<pii, int> canh, soh;
int d[maxn][2];
bool visited[maxn];

void init(){
    cin >> n;
    for(int i = 1; i <= n - 3; i ++){
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        canh[{u, v}] = 1;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    for(int i = 1; i < n; i ++) canh[{i, i + 1}] = 1;
    for(int i = 1; i <= n; i ++){
        if(i == n) ke[i].push_back(1);
        else ke[i].push_back(i + 1);
        if(i == 1) ke[i].push_back(n);
        else ke[i].push_back(i - 1);
    }
    for(int i = 1; i <= n; i ++) sort(ke[i].begin(), ke[i].end());
}

void initGraph(){
    int nn = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < ke[i].size() - 1; j ++){
            int u = ke[i][j], v = ke[i][j + 1];
            if(! canh[{u, v}] || u <= i) continue;
            nn ++;
            int c1 =  soh[{i, u}], c2 = soh[{i, v}], c3 = soh[{u, v}];
            if(c1){
                adj[c1].push_back(nn);
                adj[nn].push_back(c1);
            }
            if(c2){
                adj[c2].push_back(nn);
                adj[nn].push_back(c2);
            }
            if(c3){
                adj[c3].push_back(nn);
                adj[nn].push_back(c3);
            }
            soh[{i, u}] = nn; soh[{i, v}] = nn; soh[{u, v}] = nn;
        }
    }
    n = nn;
}

void DFS(int u){
    visited[u] = 1;
    d[u][1] = 1;
    for(int v: adj[u]){
        if(! visited[v]) {
            DFS(v);
            int res1 = d[u][0] + min(d[v][0], d[v][1]) + 1;
            int res2 = d[u][1] + min(d[v][0] + 1, d[v][1]);
            d[u][1] = min(res1, res2);
            d[u][0] += d[v][1];
        }
    }
}

void solve(){
    init();
    initGraph();
    DFS(1);
    // for(int i = 1; i <= n; i ++){
    //     cout << i << ": ";
    //     for(int v: adj[i]) cout << v << " ";
    //     cout << endl;
    // }
    cout << d[1][1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){ freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);}
    solve();
    for(int i = 1; i <= n; i ++) assert(visited[i]);
    return 0;
}
