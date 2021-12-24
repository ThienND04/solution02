#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "tree"
#define inf 1e9 + 7
#define maxn 500001
#define delta 0.0000001

int t, query, n, m, k;
bool visited[maxn];
int node[maxn], pre[maxn], nt[maxn];
vector<int> nonAdj[maxn];

void erase(int u){
    nt[pre[u]] = nt[u];
    pre[nt[u]] = pre[u];
}

void BFS(int s){
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    erase(s);
    while(! q.empty()){
        int u  = q.front();
        q.pop();
        vector<int> next;
        int i  = 0;
        for(int v = nt[0]; v != n + 1; v = nt[v]){
            while(i < nonAdj[u].size() && nonAdj[u][i] < v) i ++;
            if((i == nonAdj[u].size()) || (i < nonAdj[u].size() && nonAdj[u][i] != v)) next.push_back(v);
        }
        for(int v: next){
            q.push(v);
            erase(v);
            visited[v] = 1;
        }
    }
}

void init(){
    cin >> n >> m >> k;
    reset(visited);
    pre[n + 1] = n;
    nt[0] = 1;
    for(int i = 1; i <= n; i ++){
        pre[i] = i - 1;
        nt[i] = i + 1;
    }
    for(int i = 1; i <= m; i ++) nonAdj[i].clear();
    for(int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        nonAdj[u].push_back(v);
        nonAdj[v].push_back(u);
    }
    for(int i = 1; i <= n; i ++) sort(nonAdj[i].begin(), nonAdj[i].end());
}

void solve(){
    init();
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        if(! visited[i]) {
            BFS(i);
            cnt ++;
        }
    }
    if(cnt != 1 || n - nonAdj[1].size() < k){
        cout << "No ";
        return;
    }
    reset(visited);
    visited[1] = 1;
    pre[n + 1] = n;
    nt[0] = 1;
    for(int i = 1; i <= n; i ++){
        pre[i] = i - 1;
        nt[i] = i + 1;
    }
    erase(1);
    cnt = 0;
    for(int i = 2; i <= n; i ++){
        if(! visited[i]){
            cnt ++;
            BFS(i);
        }
    }
    if(cnt > k) cout << "No ";
    else cout << "Yes ";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    for(int i = 1; i < maxn; i ++) node[i] = i;
    cin >> t >> query;
    while(query --) solve();
    return 0;
}