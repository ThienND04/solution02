#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "haitumtp"
#define maxn 2208
#define inf 1e18
#define mod 1000000007

int r, c;
int b[maxn][maxn];
ll dp[maxn][maxn];
int x[maxn][5];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> r >> c;
    memset(dp, 99, sizeof(dp));
    for(int i = 0; i < r; i ++){
        for(int j = 0; j < c; j ++) cin >> b[i][j];
    }
    for(int i = 0; i < r; i ++) dp[i][0] = b[i][0];
    for(int i = 0; i < r; i ++){
        x[i][0] = 1;
        for(int t = 1; t <= 4; t ++) x[i][t] = (x[i][t - 1] * i) % r;
    }
    for(int j = 0; j < c - 1; j ++){
        for(int i = 0; i < r; i ++){
            for(int t = 2; t <= 4; t ++){
                int nt = x[i][t];
                dp[nt][j + 1] = min(dp[nt][j + 1], dp[i][j] + b[nt][j + 1]);
            }
        }
    }
    ll res = 1e18;
    for(int i = 0; i < r; i ++) res = min(res, dp[i][c - 1]);
    cout << res;
    return 0;
}