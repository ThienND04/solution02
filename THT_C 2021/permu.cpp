#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "permu"
#define maxn 200200
#define inf 1000000007
#define mod 998244353

int m, t, num = 0;
pii lr[maxn];
int gt[maxn];

void multi(int& x1, int x2){
    x1 = (1ll * x1 * x2) % mod;
}

void Add(int& x1, int x2){
    x1 += x2;
    if(x1 >= mod) x1 -= mod;
}

void Sub(int& x1, int x2){
    x1 -= x2;
    if(x1 < 0) x1 += mod;
}

void init(){
    cin >> m >> t;
    for(int i = 1; i <= t; i ++) cin >> lr[i].first >> lr[i].second;
    sort(lr + 1, lr + t + 1);
    int r = 0, newT = 0;
    for(int i = 1; i <= t; i ++){
        if(lr[i].first > r) lr[++ newT] = lr[i];
        else if(lr[i].second > lr[newT].second) lr[newT].second = lr[i].second;
        r = max(r, lr[i].second);
    }
    t = newT;
    for(int i = 1; i <= t; i ++) num += lr[i].second - lr[i].first + 1;
    gt[0] = 1;
    for(int i = 1; i <= m; i ++) gt[i] = (1ll * gt[i - 1] * i) % mod;
}

int POW(int a, int b){
    if(b == 0) return 1;
    int c = POW((1ll * a * a) % mod, b / 2);
    if(b % 2 == 1) multi(c, a);
    return c;
}

int kCn(int n, int k){
    // return n ! / k! / (n - k) !
    int result = gt[n];
    multi(result, POW(gt[k], mod - 2));
    multi(result, POW(gt[n - k], mod - 2));
    return result;
}

void solve(){
    int res = 0;
    // cerr << num << endl;
    for(int i = 0; i <= num; i ++){
        if(i % 2 == 0) Add(res, (1ll * kCn(num, i) * gt[m - i]) % mod);
        else Sub(res, (1ll * kCn(num, i) * gt[m - i]) % mod);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    init();
    solve();
    return 0;
}