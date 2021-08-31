#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 1000001
#define task "friends"
#define inf 1000000000

int n, q;
vector<pii> adj[maxn];
int dist[maxn];

void dijkstra(int s){
    priority_queue<pii> que;
    memset(dist, 69, sizeof(dist));
    dist[s] = 0;
    que.push({0, s});
    while(! que.empty()){
        int u = que.top().second, l = -que.top().first;
        que.pop();
        if(l > dist[u]) continue;
        for(pii e: adj[u]){
            int v = e.first, c = e.second;
            if(dist[v] > l + c){
                dist[v] = l + c;
                que.push({- dist[v], v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r",  stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i < n; i ++){
        int x, c;
        cin >> x >> c;
        adj[x].push_back({i + 1, c});
        adj[i + 1].push_back({x, c});
    }
    cin >> q;
    for(int i = 1; i <= q; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        dijkstra(a);
        adj[a].pop_back();
        adj[b].pop_back();
        cout << dist[1] + min(c, dist[b]) << "\n";
    }
    return 0;
}