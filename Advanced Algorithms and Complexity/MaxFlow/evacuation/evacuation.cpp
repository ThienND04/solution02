#include <iostream>
#include <vector>
#include <queue>
#include<cstring>

using namespace std;

typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a));

#define maxn 103

int n, m;
vector<int> adj[maxn];
int c[maxn][maxn];
int curFlow[maxn][maxn];

int par[maxn], addFlow[maxn];

bool findPath(){
    reset(par);
    reset(addFlow);
    queue<int> q;
    q.push(1);
    addFlow[1] = 2000000000;
    while(! q.empty()){
        int u = q.front();
        q.pop();
        for(int v: adj[u]){
            if(par[v]) continue;
            if(c[u][v] - curFlow[u][v] > 0) {
                addFlow[v] = min(addFlow[u], c[u][v] - curFlow[u][v]);
                par[v] = u;
                q.push(v);
            }
        }
    }
    return par[n];
}

void add(long long& result){
    int cur = n;
    int d = addFlow[n];
    result += d;
    while(cur != 1){
        curFlow[par[cur]][cur] += d;
        curFlow[cur][par[cur]] -= d;
        cur = par[cur];
    }
}

long long maxFlow(){
    long long result = 0;
    reset(curFlow);
    while(findPath()){
        add(result);
    }
    return result;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin >> n >> m;
    while(m --){
        int u, v, ci;
        cin >> u >> v >> ci;
        adj[u].push_back(v);
        adj[v].push_back(u);
        c[u][v] += ci;
    }
    cout << maxFlow();
    return 0;
}
