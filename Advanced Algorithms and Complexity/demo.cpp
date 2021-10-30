#include <iostream>
#include <vector>
#include <queue>
#include<cstring>

using namespace std;

typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a));

#define maxn 103

int n, m;
vector<pii> adj[maxn];
vector<int> caj[maxn];
vector<int> curFlow;

vector<pii> adjR[maxn];
vector<int> cajR[maxn];
vector<int> curFlowR[maxn];

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
        for(pii edge: adj[u]){
            int v = edge.first, c = edge.second;
            if(par[v]) continue;
            if(c - curFlow[u][v] > 0) {
                addFlow[v] = min(addFlow[u], c - curFlow[u][v]);
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
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        caj[u].push_back(0);
        adjR[v].push_back({u, 0});
        
    }
    cout << maxFlow();
    return 0;
}
