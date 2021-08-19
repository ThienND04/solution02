#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "matrix"
#define maxn 501
#define bit(x, i) ((x >> i) & 1)
#define inf 1000000000000000

int m, n;
int a[maxn][maxn];
ll s[maxn][maxn], sn[maxn];

ll calc(int u, int v){
    ll mi = 0;
    ll res = -inf;
    for(int i = 1; i <= n; i ++){
        ll stmp = s[v][i] - s[u - 1][i];
        sn[i] = sn[i - 1] + stmp;
    }
    for(int i = 1; i <= n; i ++){
        res = max(res, sn[i] - mi);
        mi = min(mi, sn[i]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> m >> n;
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
    }
    memset(s, 0, sizeof(s));
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j++) s[i][j] = s[i - 1][j] + a[i][j];
    }
    ll res = -inf;
    for(int u = 1; u <= m; u ++){
        for(int v = u; v <= m; v ++){
            res = max(res, calc(u, v));
        }
    }
    cout << res;
    return 0;
}