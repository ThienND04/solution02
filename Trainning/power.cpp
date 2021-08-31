#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 11
#define task "power"
#define inf 1000000000

ll l, r;

ll POW(ll a, int b){
    if(b == 1) return a;
    if(a > sqrt(r)) return -1;
    ll c = POW(a * a, b / 2);
    if(c == -1) return -1;
    if(b % 2 == 1) c *= a;
    if(c > r) return -1;
    return c;
}

bool check(int k){
    // k != 1
    int lf = 1, rt = 1e7;
    while(rt - lf > 1){
        int mid = (lf + rt) / 2;
        ll p = POW(mid, k);
        if(p == -1)  rt = mid;
        else if(p < l) lf = mid;
        else return 1;
    }
    return 0;
}

int solve(){
    for(int i = 40; i > 1; i --){
        if(check(i)) return i;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r",  stdin);
        freopen(task ".out", "w", stdout);
    }
    int t;
    cin >> t;
    for(int i = 1; i <= t; i ++){
        cin >> l >> r;
        cout << "Case #" << i << ": " << solve() << "\n";
    }
    return 0;
}