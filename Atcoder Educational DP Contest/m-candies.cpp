#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "m-candies"
#define maxn 101
#define inf 1000000007
#define mod 1000000007

#define maxk 100001

int n, k;
int a[maxn];
int dp[maxn][maxk];

void add(int& x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    reset(dp);
    dp[0][k] = 1;
    for(int i = 1; i <= n; i ++){
        ll sum = dp[i - 1][0], l = 0, r = 0;
        for(int j = 0; j <= k; j ++){
            while(r < min(a[i] + j, k)) {
                r ++;
                sum += dp[i - 1][r];
            }
            while(l < j) {
                sum -= dp[i - 1][l];
                l ++;
            }
            dp[i][j] = sum % mod;
        }
    }
    cout << dp[n][0];
    return 0;
}