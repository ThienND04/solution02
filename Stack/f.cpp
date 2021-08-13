#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "f"
#define maxn 5001
#define inf 100000000000000007

int n, k, l, r, m;
int x[maxn], top = 0, bot = 0;
ll dp[maxn][maxn];
pair<ll, int> dq[maxn * 3];

int delta(int i){
    return 2 * i * (k - i);
}

void init(){
    cin >> n >> k >> l >> r >> m;
    for(int i = 1; i <= n; i ++) cin >> x[i];
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= k; j ++) {
            dp[i][j] = -inf; 
        }
    }
    x[0] = -1000000009;
    for(int i = 1; i <= n; i ++){
        if(x[i] >= l && x[i] <= r) {
            dp[i][1] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();
    for(int j = 2; j <= k; j ++){
        ll dt = delta(j - 1);
        int pre = 1;
        bot = 1;
        top = 0;
        for(int i = 1; i <= n; i ++){
            while(x[i] - x[pre] > r) pre ++;
            while(top >= bot && x[i] - x[dq[bot].second] > r) bot ++;
            for(; x[i] - x[pre] >= l; pre ++){
                ll tmp = dp[pre][j - 1] - dt * x[pre];
                while(top >= bot && tmp >= dq[top].first) top --;
                dq[++ top] = {tmp, pre};
            }
            if(top >= bot) dp[i][j] = dq[bot].first + dt * x[i];
        }
    }
    ll res = 0;
    for(int i = 1; i <= n; i ++) if(m - x[i] >= l && m  - x[i] <= r) res = max(res, dp[i][k]);
    cout << res;
    return 0;
}