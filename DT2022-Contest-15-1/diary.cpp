#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "diary"
#define maxn 101
#define bit(x, i) ((x >> i) & 1)
#define inf 10000

int n;
int a[maxn];
int dp[maxn][maxn][maxn];
int mi[maxn][maxn]; // a[i] = 0

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++){
        for(int j = 0;  j <= n; j ++) mi[i][j] = inf;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= n; j ++) {
            for(int k = 1; k <= n; k ++) dp[i][j][k] = inf;
        }
    }
    mi[1][1] = (a[1] != 0);
    dp[1][0][1] = (a[1] != 0);
}

void solve(){
    for(int i = 2; i <= n; i ++){
        for(int j = 0; j < i; j ++){
            int add = (a[i] != j);
            for(int k = 1; k <= n; k ++){
                if(j == 0){
                    dp[i][j][k] = mi[i - 1][k - 1] + add;
                }
                else{
                    dp[i][j][k] = dp[i - 1][j - 1][k] + add;
                }
                mi[i][k] = min(mi[i][k], dp[i][j][k]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();
    solve();
    for(int k = 1; k <= n; k ++) cout << mi[n][k] << "\n";
    return 0;
}