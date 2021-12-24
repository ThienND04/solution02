#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "rentland"
#define maxn 100001
#define inf 1e18
#define mod 1000000007

int n, m = 0;
pii a[maxn];
pii d[maxn];
ll dp[maxn], q[maxn];
double x[maxn];
int p[maxn];

bool ok(int i){
    if(d[i].second == p[m]) return 0;
    double x1 = 1.0 * (dp[i] - q[m]) / (p[m] - d[i].second);
    double x2 = 1.0 * (dp[i] - q[m - 1]) / (p[m - 1] - d[i].second);
    return x1 > x2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n;
    for(int i = 1; i <= n ; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++){
        // second giam dan
        while(m && d[m].second <= a[i].second) m --;
        d[++ m] = a[i];
    }
    for(int i = 0; i < m; i ++) {
        d[i].second = d[i + 1].second;
    }
    dp[0] = q[0] = 0;
    x[0] = -inf;
    n = m;
    m = 0;
    p[0] = d[0].second;
    int u = 0;
    for(int i = 1; i <= n; i ++){
        while(u <= m && x[u] <= d[i].first) u ++;
        u --;
        dp[i] = 1ll * d[i].first * p[u] + q[u];
        if(d[i].second == p[m] && dp[i] >= q[m]) continue;
        while(m && !ok(i)) m --;
        if(u > m) u = m;
        if(m == 0 && p[0] == d[i].second) q[0]  = dp[i];
        else {
            p[++ m] = d[i].second;
            q[m] = dp[i];
            x[m] = 1.0 * (q[m - 1] - q[m]) / (p[m] - p[m - 1]);
        }
    }
    cout << dp[n];
    return 0;
}