#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "e-knapsack2"
#define maxn 101
#define inf 1000000007
#define mod 998244353

int n, W;
int w[maxn], v[maxn];
ll dp[maxn][100001];

void minimize(ll& x, ll y){
    if(x == -1) x = y;
    else x = min(x, y);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n >> W;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++) cin >> w[i] >> v[i];
    for(int i = 1;i <= n; i ++){
        for(int j = 0; j < 100001; j ++){
            dp[i][j] = dp[i - 1][j];
        }
        for(int j = v[i]; j < 100001; j ++){
            if(dp[i - 1][j - v[i]] != -1){
                ll tmp = dp[i - 1][j - v[i]] + w[i];
                if(tmp > W) continue;
                minimize(dp[i][j], tmp);
            }
        }
    }
    int res = 0;
    for(int i = 0; i < 100001; i ++){
        if(dp[n][i] != -1 && dp[n][i] <= W) res = i;
    }
    cout << res;
    return 0;
}