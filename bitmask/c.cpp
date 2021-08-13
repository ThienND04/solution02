#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "c"
#define maxn 15
#define bit(x, i) ((x >> i) & 1)
#define inf 1410065407

int n, k;
ll f[1 << maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> k;
    for(int i = 0; i < n; i ++) f[1 << i][i] = 1;
    for(int x = 0; x < 1 << n; x ++){
        for(int i = 0; i < n; i ++){
            if(bit(x, i)) {
                int u = x - (1 << i);
                for(int j = 0; j < n; j ++){
                    if(abs(i - j) > k) continue;
                    if(bit(u, j)) f[x][i] += f[u][j];
                }
            }
        }
    }
    ll res = 0;
    for(int i = 0; i < n; i ++) res += f[(1 << n) - 1][i];
    cout << res;
    return 0;
}