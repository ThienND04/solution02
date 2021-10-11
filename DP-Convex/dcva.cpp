#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "dcva"
#define maxn 100001
#define inf 1e18
#define mod 1000000007

int n, c, m = 0;
int a[maxn], b[maxn];
int s[maxn];
ll dp[maxn];
double x[maxn];

bool ok(int i){
    int u = s[m];
    if(b[i] == b[u]) {
        if(dp[u] >= dp[i]) return 0;
        return 1;
    }
    if(m == 1) return 1;
    double x1 = 1.0 * (dp[u] - dp[i]) / (b[i] - b[u]);
    u = s[m - 1];
    double x2 = 1.0 * (dp[u] - dp[i]) / (b[i] - b[u]);
    return (x1 > x2);
}

void solve(){
    dp[1] = c;
    m = 1;
    int u = 1;
    s[1] = 1;
    x[1] = -inf;
    for(int i = 2; i <= n; i ++){
        while(u <= m && x[u] <= a[i]) u ++;
        u --;
        dp[i] = dp[s[u]] + b[s[u]] * a[i];
        if(b[i] == b[s[m]] && dp[i] >= dp[s[m]]) continue;
        while(m > 1 && !ok(i)) m --;
        if(u > m) u = m;
        if(m == 0) s[++ m] = i;
        else {
            s[++ m] = i;
            x[m] = 1.0 * (dp[s[m - 1]] - dp[s[m]]) / (b[s[m]] - b[s[m - 1]]);
        }
    }
    cout << dp[n];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n >> c;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) cin >> b[i];
    solve();
    return 0;
}