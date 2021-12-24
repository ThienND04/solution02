#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "dance"
#define inf 1e18
#define mod 1000000007
#define maxn 5001

int n, m;
bool ok[maxn][maxn];
vector<int> adj[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= m; i ++){
        int u, v;
        cin >> u >> v;
        if(! ok[u][v]){
            ok[u][v] = 1;
            adj[u].push_back(v);
        }
    }
    int res = 0;
    for(int u1 = 1; u1 <= n; u1 ++){
        for(int v1: adj[u1]){
            for(int u2 = 1; u2 <= n; u2 ++){
                if(u2 == u1) continue;
                for(int v2: adj[u2]){
                    if(v2 == v1) continue;
                    if(ok[u1][v2] && ok[u2][v1]) res ++;
                }
            }
        }
    }
    cout << res / 4;
    return 0;
}