#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "d"
#define maxn 100001
#define inf 1e18

int n;
int x[maxn], v[maxn];

double get(double t){
    double m1 = 0, m2 = inf;
    for(int i = 1; i <= n; i ++){
        double d = x[i] + v[i] * t;
        m1 = max(m1, d);
        m2 = min(m2, d);
    }
    return m1 - m2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> x[i] >> v[i];
    double l = 0, r = 1e7;
    double delta = 1e-10;
    for(int i = 0; i <= 450; i ++){
        double x1 = (r + 2 * l) / 3;
        double x2 = (2 * r + l) / 3;
        double d1 = get(x1), d2 = get(x2);
        if(d1 < d2 + delta) r = x2;
        else l = x1;
    }
    cout << fixed << setprecision(6) << l << " " << get(l);
    return 0;
}