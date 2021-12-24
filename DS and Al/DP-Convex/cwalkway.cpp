#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "cwalkway"
#define maxn 1000003
#define inf 1e18
#define mod 1000000007

int n, c, m = 0;
int pos[maxn];
ll p[maxn];
ll q[maxn];
ll dp[maxn];
double x[maxn];

bool ok(int i){
    ll v = -2ll * pos[i + 1];
    ll b = 1ll * pos[i + 1] * pos[i + 1] + dp[i] + c;
    if(b == p[m]) return 0;
    if(m == 0) return 1;
    double x1 = 1.0 * (q[m] - b) / (v - p[m]);
    double x2 = 1.0 * (q[m - 1] - b) / (v - p[m - 1]);
    return x1 > x2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n >> c;
    memset(dp, 99, sizeof(dp));
    for(int i = 1; i <= n; i ++) cin >> pos[i];
    // reverse(pos + 1, pos + n + 1);
    dp[0] = 0;
    p[0] = -2 * pos[1];
    q[0] = 1ll * pos[1] * pos[1] + c;
    x[0] = - inf;
    int u = 0;
    for(int i = 1; i <= n; i ++){
        while(u <= m && pos[i] >= x[u]) u ++;
        u --;
        dp[i] = 1ll * pos[i] * pos[i] + p[u] * pos[i] + q[u];
        while(m && !ok(i)) m --;
        if(u > m) u = m;
        ll v = dp[i] + 1ll * pos[i + 1] * pos[i + 1] + c;
        if(m == 1 && -2ll * pos[i + 1] == p[m] && v < q[m]) q[m] = v;
        else {
            p[++ m] = -2ll * pos[i + 1];
            q[m] = v;
            x[m] = 1.0 * (q[m - 1] - q[m]) / (p[m] - p[m - 1]);
        }
    }
    cout << dp[n];
    return 0;
}