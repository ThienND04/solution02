#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "easymath"
#define inf 1e9
#define mod 1000000007
#define maxn 21

#define bit(x, i) ((x >> i) & 1)

int n;
ll a[maxn], resA, resB;
int l, r;

ll gcd(ll x, ll y){
    // assert(x > 0 && y > 0);
    if(x <= 0) return -1;
    while(x * y){
        if(x > y) x %= y;
        else y %= x;
    }
    return x + y;
}

ll lcm(ll x, ll y){
    if(x <= 0) return -1;
    x /= gcd(x, y);
    ll res = x * y;
    if(res / y == x) return res;
    else return -1;
    return x / gcd(x, y) * y;
}

int dem(ll bcnn){
    if(bcnn <= 0) return 0;
    return r / bcnn - (l - 1) / bcnn;
}

void init(){
    cin >> l >> r;
    int u, v;
    cin >> u >> v;
    n = 5;
    for(int i = 0; i < 5; i ++) a[i] = u + i * v;
}

void solve(){
    init();
    ll res  = 0;
    for(int x = 1; x < (1 << n); x ++){
        ll bcnn = 1;
        for(int i = 0; i < n; i ++) if(bit(x, i)) bcnn = lcm(bcnn, a[i]);
        if(bcnn <= 0) continue;
        int cnt = __builtin_popcount(x);
        if(cnt % 2 == 0) res -= dem(bcnn);
        else res += dem(bcnn);
    }
    cout << r - l + 1 - res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while(t --) solve();
    return 0;
}