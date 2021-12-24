#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "trokuti"
#define inf 1e9
#define mod 1000000007
#define maxn 300001
#define delta 0.0000001

int n;
int a[maxn], b[maxn], c[maxn];
ll res = 0;

map<pii, int> mp;

int gcd(int x, int y){
    while(x * y != 0){
        if(x > y) x %= y;
        else y %= x;
    }
    return x + y;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    res = 1ll * n * (n - 1) * (n - 2) / 6;
    for(int i = 1; i <= n; i ++){
        cin >> a[i] >> b[i] >> c[i];
        if(a[i] < 0){
            a[i] = - a[i];
            b[i] = - b[i];
            c[i] = - c[i];
        }
        int tmp = gcd(a[i], abs(b[i]));
        a[i] /= tmp;
        b[i] /= tmp;
        mp[{a[i], b[i]}] ++;
    }
    for(auto e: mp){
        int tmp = e.second;
        if(tmp >= 3) res -= 1ll * tmp * (tmp - 1) * (tmp - 2) / 6;
        if(tmp >= 2) res -= 1ll * tmp * (tmp - 1) / 2 * (n - tmp);
    }
    cout << res % mod;
    return 0;
}