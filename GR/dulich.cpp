#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a))
#define task "dulich"
#define inf 999999999
#define maxn 102

int n, m, res = inf;
int w[2 * maxn][2 * maxn], d[2 * maxn], pre[maxn * 2];
bool kt[maxn];

void dijkstra(int s){;
    fill(pre + 1, pre + 2 * n + 1, 1);
    fill(d, d + 2 * n + 1, inf);
    fill(kt + 1, kt + n + 1, 1);
    d[s] = 0;
    kt[s + n] = 0;
    while(1){
        int u = 0;
        for(int i = 1; i <= n; i ++){ // / // / / // / /
            if(d[i] < d[u] && kt[i]) u = i;
        }
        if(u == 0) break;
        kt[u] = 0;
        for(int i = 1; i <= n; i ++){
            if(kt[i] && pre[u] != i){
                if(d[i] > d[u] + w[u][i]){
                    d[i + n] = d[i];
                    d[i] = d[u] + w[u][i];
                    pre[i + n] = pre[i];
                    pre[i] = u;
                }
                else if(d[i + n] > d[u] + w[u][i]){
                    d[i + n ] = d[u] + w[u][i];
                    pre[i] = u;
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++){
        if(i == s) continue;
        res = min(res, d[i] + d[i + n]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= 2 * n;  i++){
        for(int j = 1; j <= 2 * n; j ++ )w[i][j] = inf;
    }
    while( m --){
        int u, v, c;
        cin >> u >> v >> c;
        w[u][v] = min(w[u][v], c);
        w[v][u] = min(w[v][u], c);
    }
    for(int i = 1; i <= n; i ++) {
        dijkstra(i);
    }
    cout << res;
    return 0;
}