#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "buying"
#define maxn 2001
#define bit(x, i) ((x >> i) & 1)
#define inf 1000000000000000

struct data
{
    int x, y, z;
};

int n;
data a[maxn];
ll dp[maxn][2][maxn];

void solve(){
    sort(a + 1, a + n + 1, [] (data& u, data& v) {return u.y - u.x < v.y - v.x; });
    memset(dp, 70, sizeof(dp));
    // for(int i = 0; i <= n; i ++){
    //     for(int t = 0; t < 2; t ++){
    //         for(int nz = 0; nz <= n; nz ++) dp[i][t][nz] = inf;
    //     }
    // }
    cerr << dp[0][0][0];
    dp[0][0][0] = 0;
    for(int i = 0; i < n; i ++){
        for(int t = 0; t < 2; t ++){
            // t = 1: co x
            // t = 0: chi co y || z
            for(int nz = 0; nz <= i; nz ++){
                // --> x
                dp[i + 1][1][nz] = min(dp[i + 1][1][nz], dp[i][t][nz] + a[i + 1].x);
                if(t == 0){
                    // --> y
                    int ny = i - nz;
                    dp[i + 1][0][nz] = min(dp[i + 1][0][nz], dp[i][t][nz] + a[i + 1].y - ny);
                }
                dp[i + 1][t][nz + 1] = min(dp[i + 1][t][nz + 1], dp[i][t][nz] + a[i + 1].z - nz);
            }
        }
    }
    ll res = inf;
    for(int t = 0; t < 2; t ++){
        for(int nz = 0; nz <= n; nz ++) res = min(res, dp[n][t][nz]);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i].x >> a[i].y >> a[i].z;
    solve();
    return 0;
}