#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "xor"
#define inf 1e9
#define mod 1000000007
#define maxn 64

#define bit(x, i) ((x >> i) & 1)

bool check(ll l, ll r, ll n){
    if(l > r) swap(l, r);
    if(l - 1 < 0) return 1;
    return r / n - (l - 1) / n;
}

bool Try(ll x, int i, ll n){
    // còn i - 1 bit chưa được điền 
    // bit thứ i của x là 0
    if(i == 0) return x % n == 0;

    ll l = x << i;
    ll r = (i > 0? (x + 1) << i: x) - 1;
    return check(l, r, n);
}

ll solve(ll a, ll n){
    ll result = 0;
    ll tmp = 0;
    for(int i = 62; i >= 0; i --){
        result <<= 1;
        if(! Try(tmp * 2 + (bit(a, i) ^ 0), i, n)) {
            tmp = tmp * 2 + (bit(a, i) ^ 1);
            result ++;
        }
        else tmp = tmp * 2 + (bit(a, i) ^ 0);
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll a, n;
    cin >> a >> n;
    cout << solve(a, n);
    return 0;
}