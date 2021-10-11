#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "convol"
#define inf 1e9
#define mod 1000000007
#define maxn 5002

#define B 1000007

#define bit(x, i) ((x >> i) & 1)

int n;
int a[maxn], b[maxn];
ll dp[maxn][maxn];
ll res = -(1e18);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) cin >> b[i];
    dp[n + 1][n + 1] = 0;
    for(int i = n; i >= 1; i --){
        for(int j = n; j >= 1; j --){
            ll tmp = 1ll * a[i] * b[j];
            dp[i][j] = max(tmp, tmp + dp[i + 1][j + 1]);
            res = max(res, dp[i][j]);
        }
    }
    cout << res;
    return 0;
}