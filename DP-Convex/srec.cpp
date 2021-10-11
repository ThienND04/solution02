#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "srec"
#define maxn 1000001
#define inf 1e18
#define mod 1000000007

struct Rec
{
    ll x, y, a;
};

bool cmp(Rec& r1, Rec& r2){
    return r1.x < r2.x;
}

int n, m = 0, u = 1;
Rec srec[maxn];
ll dp[maxn];
ll p[maxn], q[maxn];
double x[maxn];
ll res = 0;

bool ok(ll p0, ll q0){
    if(p0 == p[m]) return 0;
    if(m == 1) return 1;
    double x0 = 1.0 * (q[m] - q0) / (p0 - p[m]);
    double x1 = 1.0 * (q[m - 1] - q0) / (p0 - p[m - 1]);
    return x0 > x1;
}


void add(ll p0, ll q0){
    if(m && p0 == p[m] && q0 <= q[m]) return;
    while(m && !ok(p0, q0)) m--;
    if(m && p0 == p[m] && q0 >= q[m]) q[m] = q0;
    else{
        p[++ m] = p0;
        q[m] = q0;
    }
    if(m > 1){
        x[m] = 1.0 * (q[m - 1] - q[m]) / (p[m] - p[m - 1]);
    }
}

ll get(int xx){
    if(u > m) u = m;
    while(u <= m && x[u] <= xx) u ++;
    u --;
    return p[u] * xx + q[u];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n;
    x[1] = -inf;
    for(int i = 1; i <= n; i ++) cin >> srec[i].x >> srec[i].y >> srec[i].a;
    sort(srec + 1, srec + n + 1, cmp);
    dp[0] = 0;
    add(0, 0);
    for(int i = 1; i <= n; i ++){
        dp[i] = get(- srec[i].y) + 1ll * srec[i].x * srec[i].y - srec[i].a;
        res = max(res, dp[i]);
        add(1ll * srec[i].x, dp[i]);
    }
    cout << res;
    return 0;
}