#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "commando"
#define maxn 1000001
#define inf 1e18
#define mod 1000000007

int n, a, b, c, m = 0;
int h[maxn], s[maxn];
ll p[maxn], q[maxn];
double x[maxn];
ll dp[maxn];

bool ok(int i){
    ll a0 = -2ll * a * s[i];
    ll b0 = 1ll * a * s[i] * s[i] - 1ll * b * s[i] + c + dp[i];
    if(a0 == p[m]) return 0;
    if(m == 0) return 1;
    double x0 = 1.0 * (q[m] - b0) / (a0 - p[m]);
    double x1 = 1.0 * (q[m - 1] - b0) / (a0 - p[m - 1]);
    return x0 > x1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n >> a >> b >> c;
    for(int i = 1; i <= n; i ++) {
        cin >> h[i];
        s[i] = s[i - 1] + h[i];
    }
    // for(int i = 1; i <= n; i ++) dp[i] = -inf;
    x[0] = -inf;
    dp[0] = 0;
    // p[0] = -2ll * a * s[1];
    // q[0] = a * s[1] * s[1] - b * s[1] + c + dp[0];
    p[0] = -2ll * a * s[0];
    q[0] = a * s[0] * s[0] - b * s[0] + c + dp[0];
    int u = 0;
    for(int i = 1; i <= n; i ++){
        while(u <= m && s[i] >= x[u]) u ++;
        u --;
        if(u < 0) u = 0;
        dp[i] = 1ll * p[u] * s[i] + q[u] + 1ll * a * s[i] * s[i] + 1ll * b * s[i];
        ll a0 = -2ll * a * s[i];
        ll b0 = 1ll * a * s[i] * s[i] - 1ll * b * s[i] + c + dp[i];
        if(a0 == p[m] && b0 <= q[m]) continue;
        while(m && !ok(i)) m --;
        if(u > m) u = m;
        if(m == 0 && a0 == p[0] && b0 > q[0]) q[0] = b0;
        else {
            p[++ m] = a0;
            q[m] = b0;
            x[m] = 1.0 * (q[m - 1] - q[m]) / (p[m] - p[m - 1]);
        }
    }
    cout << dp[n];
    return 0;
}