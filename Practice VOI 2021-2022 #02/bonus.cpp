#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bonus"
#define inf 1e18
#define mod 1000000007
#define maxn 301

// m = 1 
// n = 200

int m, n;
int a[maxn];
ll dp[maxn][maxn][2];
bool ok;

ll res = 0;

void minimize(ll& x, ll y){
    if(x > y) {
        x = y;
        ok = 1;
    }
}

void maximize(ll& x, ll y){
    if(x < y){
        x = y;
        ok = 1;
    }
}

void init(){
    cin >> m >> n;
    for(int i = 1; i<= n; i ++) cin >> a[i];
}

void solve(){
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            if(i == j) continue;
            ll tmp = a[i] + a[j];
            if(tmp < 0) {
                dp[i][j][0] = tmp;
                dp[i][j][1] = -inf;
            }
            else{
                dp[i][j][1] = tmp;
                dp[i][j][0] = inf;
            }
        }
    }
    ok = 1;
    int cnt = 0;
    while(ok){
        ok = 0;
        cnt ++;
        for(int k = 1; k <= n; k ++){
            for(int i = 1; i <= n; i ++){
                if(i == k) continue;
                for(int j = 1; j <= n; j ++){
                    if(j == k) continue;
                    if(abs(j - k) < abs(i - k)){
                        ll tmp;
                        if(dp[k][j][0] != inf) {
                            tmp = dp[k][j][0] + a[i];
                            if(tmp < 0) minimize(dp[i][k][0], tmp);
                            else maximize(dp[i][k][1], tmp);
                            if(dp[k][j][1] == -inf) continue;
                            tmp = dp[k][j][1] + a[i];
                            if(tmp >= 0) maximize(dp[i][k][1], tmp);
                        }
                        else if(dp[k][j][1] != -inf){
                            tmp = dp[k][j][1] + a[i];
                            if(tmp >= 0) maximize(dp[i][k][1], tmp);
                            else minimize(dp[i][k][0], tmp);
                        }
                        if(dp[i][k][0] < inf - 1e15) res = max(res, abs(dp[i][k][0]));
                        if(dp[i][k][1] > - inf + 1e15) res = max(res, abs(dp[i][k][1]));
                    }
                }
            }
        }
        if(! ok) break;
    }
    // cerr << cnt;
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    // cerr << n;
    solve();
    return 0;
}