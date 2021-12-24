#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "f"
#define maxn 1000005
#define inf 1e18
#define reset(a) memset(a, 0, sizeof(a))

int n, m, k;
int a[maxn], b[maxn], c[maxn], d[maxn];
ll su[maxn];

void init(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= m; i ++) cin >> b[i];
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            c[n * (i - 1) + j] = a[i] + a[j];
        }
    }
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= m; j ++){
            d[m * (i - 1) + j] = b[i] + b[j];
        }
    }
    n = n * n;
    m = m * m;
    sort(c +1, c + n + 1);
    sort(d + 1, d + m + 1);
    for(int i = 1; i <= m; i ++) su[i] = su[i - 1] + d[i];
}

bool check(ll x){
    int j = m;
    ll cnt = 0;
    for(int i = 1; i <= n; i ++){
        while(c[i] + d[j] >= x && j) j --;
        cnt += m - j;
    }
    return (cnt >= k);
}

ll calc(ll x){
    ll res = 0;
    for(int i = 1; i <= n; i ++){
        int p = upper_bound(d + 1, d + m + 1, x - c[i]) - d - 1;
        res += su[m] - su[p] + c[i] * (m - p);
        k -= m - p;
    }
    res +=  k * x;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();
    int l = -4000009, r = 4000009;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << calc(l);
    return 0;
}