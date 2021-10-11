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
    ll res = 0;
    for(int u1 = 1; u1 <= n; u1 ++){
        for(int u2 = u1 + 1; u2 <= n; u2 ++){
            if(u1 == u2) continue;
            int cnt = 0;
            for(int v: adj[u1]){
                if(ok[u1][v] && ok[u2][v]) cnt ++;
            }
            res += 1ll * cnt * (cnt - 1) / 2;
        }
    }
    cout << res;
    return 0;
}