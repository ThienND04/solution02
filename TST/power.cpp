#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "power"
#define maxn 11
#define bit(x, i) ((x >> i) & 1)
#define inf 1000000000000000

int x, m;
ll n;

ll POW(ll a, ll b){
    if(b == 1) return a;
    ll c = POW((a * a) % ((x - 1) * m), b / 2);
    if(b % 2 == 1) c = (c * a) % ((x - 1) * m);
    return c;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> x >> n >> m;
    cout << (POW(x, n + 1) - 1) / (x - 1);
    return 0;
}