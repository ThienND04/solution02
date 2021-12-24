#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "treecoloring"
#define maxn 1000009
#define inf 1000000007
#define mod 998244353

int n, t;
int p[maxn], cost[maxn], res[maxn];
vector<int> adj[maxn];

int calc(int u){
    int first = -1, second = -1;
    for(int v: adj[u]){
        if(cost[v] > first) {
            second = first;
            first = cost[v];
        }
        else second = max(second, cost[v]);
    }
    if(first < 0) return 1;
    return max(first, second + 1);
}

void addNode(int x){
    while(x > 1){
        int tmp = calc(x);
        if(tmp == cost[x]) break;
        cost[x] = tmp;
        res[p[x]] = max(res[p[x]], cost[x]);
        x = p[x];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> t >> n;
    memset(cost, -1, sizeof(cost));
    calc(1);
    cost[1] = calc(1);
    // cerr << cost[1];
    for(int i = 2; i <= n + 1; i ++){
        cin >> p[i];
        adj[p[i]].push_back(i);
        addNode(i);
        cout << res[1] << " ";
    }
    return 0;
}