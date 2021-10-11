#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "pie"
#define inf 1e9
#define mod 1000000007
#define maxn 301
#define delta 0.0000001

#define bit(x, i) ((x >> i) & 1)

int n, m;
int c[maxn][maxn];
ll dp[maxn][maxn], s = 0;

void solve(){
    memset(dp, 99, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++){
        s = 0;
        for(int j = 0; j <= m; j ++){
            s += c[i][j];
            for(int t = 0; t <= n - j; t ++) {
                if(t + j < i) continue;
                ll tmp = dp[i - 1][t] + s + j * j;
                dp[i][t + j] = min(dp[i][t + j], tmp);
            }
        }
    }
    cout << dp[n][n];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++) cin >> c[i][j];
        sort(c[i] + 1, c[i] + m + 1);
    }
    solve();
    return 0;
}