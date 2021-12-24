#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "a"
#define maxn 20
#define bit(x, i) ((x >> i) & 1)
#define inf 1410065407

int n, a[maxn][maxn + 1];
ll f[1 << maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i ++){
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
    }
    for(int x = 0; x < 1 << n; x ++){
        int k = __builtin_popcount(x);
        for(int i = 0; i < n;  i++){
            if(bit(x, i)){
                f[x] = max(f[x], f[x - (1 << i)] + a[i][k]);
            }
        }
    }
    cout << f[(1 << n) - 1];
    return 0;
}