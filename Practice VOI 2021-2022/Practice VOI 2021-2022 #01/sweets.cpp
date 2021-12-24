#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "sweets"
#define inf 1e9
#define mod 1000000007
#define maxn 111

#define bit(x, i) ((x >> i) & 1)

int n, k;
int a[maxn], avg = 0, s[maxn], res[maxn];
bitset<3338> f[112][3338];
void trace(){
    int x = avg, y = avg;
    for(int i = n; i >= 1; i --){
        if(x - a[i] >= 0 && f[i - 1][x - a[i]][y]) {
            x -= a[i];
            res[i] = 1;
        }
        else if(y - a[i] >= 0 && f[i - 1][x][y - a[i]]){
            y -= a[i];
            res[i] = 2;
        }
        else res[i] = 3;
    }
    for(int i = 1; i <= n; i ++) cout << res[i] << " ";
}

void solve(){
    f[0][0][0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int x = 0; x <= avg; x ++){
            if(x + a[i] <= avg) f[i][x + a[i]] |= f[i - 1][x];
            f[i][x] |= (f[i - 1][x] << a[i]);
            f[i][x] |= f[i - 1][x];
        }
    }
    if(! f[n][avg][avg]) {
        cout << -1;
        return;
    }
    trace();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++){
        avg += a[i];
        s[i] = s[i - 1] + a[i];
    } 
    if(avg % k != 0){
        cout << -1;
        return 0;
    }
    avg /= k;
    solve();
    return 0;
}