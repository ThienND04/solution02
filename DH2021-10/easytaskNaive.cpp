#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "easytask"
#define maxn 1000001
#define bit(x, i) ((x >> i) & 1)
#define inf 1000000000000000

int n;
int a[maxn];
bool snt[maxn];

void sang(){
    for(int i = 2; i <= n; i ++) snt[i] = 1;
    for(int i = 2; i <= sqrt(n); i ++){
        if(snt[i]){
            for(int j  = i * i; j <= n; j += i) snt[j] = 0;
        }
    }
}

int main(){
    // naive code
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    sang();
    ll res = -inf;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int l = 1; l <= n; l ++){
        if(! snt[l]) continue;
        for(int r = l; r <= n; r ++) {
            if(! snt[r]) continue;
            ll sum = 0;
            for(int k = l; k <= r; k ++) {
                sum += a[k];
            }
            res = max(res, sum);
        }
    }
    cout << res;
    return 0;
}