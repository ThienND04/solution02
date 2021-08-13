#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define task "conf"
#define inf 999999999
#define maxn 101

int n, m, x, y, z, ans = inf;
vector<pii> adj[maxn];
int d[maxn], par[maxn], dpre[maxn]; 

void dijkstra(int s){
    fill(d + 1, d + n + 1, inf);
    priority_queue<pii> q;
    q.push({0, s});
    d[s] = 0;
    while(q.size()){
        int u = q.top().second, l = -q.top().first;
        q.pop();
        if(l != d[u]) continue;
        for(pii e: adj[u]){
            int v = e.first, c = e.second;
            if(d[v] > l + c){
                par[v] = u;
                d[v] = l + c;
                dpre[v] = c;
                q.push({- d[v], v});
            }
        }
    }
}

void solve(int s){
    int res = 0;
    map<pii, bool> mp;
    int u = x;
    while(u != s){
        int l = u, t = par[u];
        if(l > t) swap(l, t);
        if(! mp[{l, t}]){
            mp[{l, t}] = 1;
            res += dpre[u];
        }   
        u = par[u];
    }
    u = y;
    while(u != s){
        int l = u, t = par[u];
        if(l > t) swap(l, t);
        if(! mp[{l, t}]){
            mp[{l, t}] = 1;
            res += dpre[u];
        }   
        u = par[u];
    }
    u = z;
    while(u != s){
        int l = u, t = par[u];
        if(l > t) swap(l, t);
        if(! mp[{l, t}]){
            mp[{l, t}] = 1;
            res += dpre[u];
        }   
        u = par[u];
    }
    ans = min(ans, res);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> m;
    while( m --){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    cin >> x >> y >> z;
    dijkstra(x);
    solve(x);
    dijkstra(y);
    solve(y);
    dijkstra(z);
    solve(z);
    cout << ans;
    return 0;
}