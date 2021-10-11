#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "d-knapsack1"
#define maxn 101
#define inf 1000000007
#define mod 998244353

int n, W;
int w[maxn], v[maxn];
ll dp[maxn][100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n >> W;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++) cin >> w[i] >> v[i];
    for(int i = 1;i <= n; i ++){
        for(int j = 0; j <= W; j ++){
            dp[i][j] = dp[i - 1][j];
        }
        for(int j = w[i]; j <= W; j ++){
            if(dp[i - 1][j - w[i]] != -1) {
                ll tmp = dp[i - 1][j - w[i]] + v[i];
                dp[i][j] = max(dp[i][j], tmp);
            }
        }
    }
    ll res = 0;
    for(int i = 0; i <= W; i ++) res = max(res, dp[n][i]);
    cout << res;
    return 0;
}