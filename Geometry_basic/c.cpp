#include<bits/stdc++.h>

using  namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "c"
#define inf 1e9
#define maxn 10005
#define delta 0.0000001

struct pos{
    int x, y;
};

int n;
pos a[maxn];

pii Vect(pos& u, pos& v){
    return {v.x - u.x, u.y - v.y};
}

bool check(double x){
    double s1 = 0, s2 = 0;
    // calculate s1
    for(int i = 1; i <= n; i ++){
        if(a[i].x <= x && a[i + 1].x <= x){
            s1 += 1ll * (a[i + 1].x - a[i].x) * (a[i].y + a[i + 1].y);
        }
        else if(a[i].x < x && a[i + 1].x > x){
            pii u = Vect(a[i], a[i + 1]);
            swap(u.first, u.second);
            double c = -(1ll * u.first * a[i].x + 1ll * u.second * a[i].y);
            double y = 1ll * (-u.first * x - c) / u.second;
            s1 += 1ll * (x - a[i].x) * (y + a[i].y);
        }
        else if(a[i].x > x && a[i + 1].x < x){
            pii u = Vect(a[i], a[i + 1]);
            swap(u.first, u.second);
            double c = -(1ll * u.first * a[i].x + 1ll * u.second * a[i].y);
            double y = 1ll * (-u.first * x - c) / u.second;
            s1 += 1ll * (a[i + 1].x - x) * (y + a[i + 1].y);
        }
    }
    // calculate s2
    for(int i = 1; i <= n; i ++){
        if(a[i].x >= x && a[i + 1].x >= x){
            s2 += 1ll * (a[i + 1].x - a[i].x) * (a[i].y + a[i + 1].y);
        }
        else if(a[i].x < x && a[i + 1].x > x){
            pii u = Vect(a[i], a[i + 1]);
            swap(u.first, u.second);
            double c = -(1ll * u.first * a[i].x + 1ll * u.second * a[i].y);
            double y = 1.0 * (-u.first * x - c) / u.second;
            s2 += 1ll * (a[i + 1].x - x) * (y + a[i + 1].y);
        }
        else if(a[i].x > x && a[i + 1].x < x){
            pii u = Vect(a[i], a[i + 1]);
            swap(u.first, u.second);
            double c = -(1ll * u.first * a[i].x + 1ll * u.second * a[i].y);
            double y = 1.0 * (-u.first * x - c) / u.second;
            s2 += 1ll * (x - a[i].x) * (y + a[i].y);
        }
    }
    return (s1 <= s2);
}

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i].x >> a[i].y;
    a[n + 1] = a[1];
    ll total = 0;
    for(int i = 1; i <=n; i ++) total += 1ll * (a[i + 1].x - a[i].x) * (a[i].y + a[i + 1].y);
    if(total < 0){
        reverse(a + 2, a + n + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    double l = -10000001, r = 10000001;
    while(r - l > delta){
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << fixed << setprecision(4) << l;
    return 0;
}