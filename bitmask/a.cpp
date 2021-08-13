#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "a"
#define maxn 100001
#define bit(x, i) ((x >> i) & 1)
#define inf 1410065407

int n;
int a[maxn][5], f[maxn][18];
int res = -inf;

bool check(int x, int y){
    for(int i = 0; i < 4; i ++){
        if(bit(x, i) && bit(y, i)) return 0;
    }
    for(int i = 0; i < 3; i ++){
        if(bit(x, i) && bit(x, i + 1)) return 0;
        if(bit(y, i) && bit(y, i + 1)) return 0;
    }
    return 1;
}

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < 4; j ++) {
            cin >> a[i][j];
            res = max(res, a[i][j]);
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j < (1 << 4); j ++) f[i][j] = -inf;
    }
    if(res <= 0) {
        cout << res;
        exit(0);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();
    for(int i = 1; i <= n; i ++){
        for(int t1 = 0; t1 < (1 << 4); t1 ++){
            for(int t2 = 0; t2 < (1 << 4); t2 ++){
                if(! check(t1, t2))continue;
                int sum = 0;
                for(int k = 0; k < 4; k ++){
                    if(bit(t1, k)) sum += a[i][k];
                }
                f[i][t1] = max(f[i][t1], f[i - 1][t2] + sum);
            }
        }
    }
    for(int i = 0; i < (1 << 4); i ++) res = max(res, f[n][i]);
    cout << res;
    return 0;
}