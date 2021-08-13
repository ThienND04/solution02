#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "f"
#define maxn 101
#define reset(a) memset(a, 0, sizeof(a))

int n, m, k;
int a[maxn], b[maxn], c[maxn], d[maxn];

void init(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= m; i ++) cin >> b[i];
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++) {
            c[(i - 1) * n + j] = a[i] + a[j];
        }
    }
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= m; j ++) {
            d[(i - 1) * m + j] = b[i] + b[j];
        }
    }
}

bool check(int x){

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();

    return 0;
}