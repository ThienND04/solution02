#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "i-coins"
#define maxn 3000
#define inf 1000000007
#define mod 1000000007

int n;
double p[maxn];
double dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> p[i];
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= i - 1; j ++){
            dp[i][j + 1] += dp[i - 1][j] * p[i];
            dp[i][j] += dp[i - 1][j] * (1 - p[i]);
        }
    }
    double res = 0;
    for(int i = n / 2 + 1; i <= n; i ++){
        res += dp[n][i];
    }
    cout << fixed << setprecision(10) << res;
    return 0;
}