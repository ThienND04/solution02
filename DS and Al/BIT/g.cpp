#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a))
#define task "e"
#define mod 30103
#define inf 999999999
#define maxn 701

int n;
int a[maxn], dp[maxn][maxn], t[maxn][2001];

void update(int x, int y, int v){
    for(; x <= n; x += x & -x){
        for(int z = y; z <= 2000; z += z & -z){
            t[x][z] = (t[x][z] + v) % mod;
        }
    }
}

int get(int x, int y){
    int res = 0;
    for(; x; x -= x & -x){
        for(int z = y; z; z -= z & -z){
            res = (res + t[x][z]) % mod;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = n; i > 1; i --){
        for(int j = i - 1; j >= 1; j --){
            int x = a[i] + a[j];
            dp[j][i] = (get(j - 1, 2000) - get(j - 1, x) + 1 + mod) % mod;
            update(j, x, dp[j][i]);
        }
    }
    int res = 0;
    for(int i = 1; i < n; i ++){
        for(int j = i + 1; j <= n; j ++){
            res = (res + dp[i][j] - 1 + mod) % mod;
        }
    }
    cout << res;
    return 0;
}