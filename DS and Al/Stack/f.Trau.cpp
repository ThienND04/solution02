#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "f"
#define maxn 5001
#define inf 100000000000000007

int n, k, l, r, m;
int x[maxn];
ll dp[maxn][maxn];

int delta(int i){
    return 2 * i * (k - i);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> k >> l >> r >> m;
    for(int i = 1; i <= n; i ++) cin >> x[i];
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= k; j ++) dp[i][j] = -inf;
    }
    for(int i = 1; i <= n; i ++){
        if(x[i] >= l && x[i] <= r) dp[i][1] = 0;
    }
    for(int j = 2; j <= k; j ++){
        int dt = delta(j - 1);
        for(int i = 1; i <= n; i ++){
            ll tmp = -inf;
            for(int q = 1; q < i; q ++){
                if(x[i] - x[q] >= l && x[i] - x[q] <= r) tmp = max(tmp, dp[q][j - 1] + 1ll * dt * (x[i] - x[q]));
            }
            dp[i][j] = tmp;
        }
    }
    ll res = 0;
    for(int i = 1; i <= n; i ++) if(m - x[i] >= l && m  - x[i] <= r) res = max(res, dp[i][k]);
    cout << res;
    return 0;
}