#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "tcq"
#define maxn 500001
#define inf 1e18
#define mod 1000000007

int subtask, n;
int c[maxn];
vector<int> adj[maxn];
int cntColor[maxn][111];
int par[maxn];

void DFS(int u){
    cntColor[u][c[u]] = 1;
    for(int v: adj[u]){
        if(v == par[u]) continue;
        par[v] = u;
        DFS(v);
        for(int )
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n;
    return 0;
}