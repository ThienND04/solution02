#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "multiple"
#define inf 1e9
#define mod 1000000007
#define maxn 21

#define bit(x, i) ((x >> i) & 1)

int n;
ll k;
ll a[maxn], resA, resB;

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

// ll sum = 0;

// void duyet(int p, int cnt, ll bcnn){
//     if(bcnn <= 0) return;
//     if(p > n){
//         // viet code vao day
//         if(cnt <= 1) return;
//         if(cnt % 2) sum -= k / bcnn;
//         else sum += k / bcnn;
//         return;
//     }
//     for(int i = p + 1; i <= n + 1; i ++){
//         duyet(i, cnt + 1, lcm(bcnn, a[i]));
//     }
// }

void solA(){
    ll res  = 0;
    for(int x = 1; x < (1 << n); x ++){
        ll bcnn = 1;
        for(int i = 0; i < n; i ++) if(bit(x, i)) bcnn = lcm(bcnn, a[i]);
        if(bcnn <= 0) continue;
        int cnt = __builtin_popcount(x);
        if(cnt % 2 == 0) res -= k / bcnn;
        else res += k / bcnn;
    }
    cout << res << " ";
}

void solB(){
    ll res  = 0;
    for(int x = 1; x < (1 << n); x ++){
        ll bcnn = 1;
        for(int i = 0; i < n; i ++) if(bit(x, i)) bcnn = lcm(bcnn, a[i]);
        if(bcnn <= 0) continue;
        int cnt = __builtin_popcount(x);
        if(cnt % 2 == 0) res -= k / bcnn * cnt;
        else res += k / bcnn * cnt;
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> k;
    // for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 0; i < n; i ++) cin >> a[i];
    a[n + 1] = 1;
    solA();
    solB();
    return 0;
}