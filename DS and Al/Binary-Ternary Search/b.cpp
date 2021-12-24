#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "b"
#define maxn 100001

int n, w, h;
int a[maxn], b[maxn];

bool check(double k){
    double s = 0, s2 = h;
    for(int i = 1; i <= n; i ++){
        s += a[i] * k;
        if(s > w) return 0;
        if(b[i] != b[i + 1] || a[i + 1] * k + s > w){
            s = 0;
            s2 -= b[i] * k;
        }
    }
    return s2 >= 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> w >> h;
    for(int i =  1; i <= n; i ++) cin >> a[i] >> b[i];
    double alpha = 0.0000001;
    double l = 0, r = 1000000000;
    while(r - l > alpha){
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(6) << l;
    return 0;
}