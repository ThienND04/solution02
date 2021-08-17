#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "shipper"
#define maxn 100001
#define bit(x, i) ((x >> i) & 1)
#define inf 1000000000

int n, m;
int x[maxn], y[maxn], t[maxn], a[maxn], b[maxn];

int calc(int hang){
    int res = abs(a[hang] - b[hang]);
    for(int i = 1; i <= n; i++){
        res = min(res, abs(a[hang] - x[i]) + abs(b[hang] - y[i]) + t[i]);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> x[i] >> y[i] >> t[i];
    for(int i = 1; i <= m; i ++) cin >> a[i] >> b[i];
    for(int i = 1; i <= m; i ++) cout << calc(i) << "\n";
    return 0;
}