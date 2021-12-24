#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "c"
#define maxn 20
#define bit(x, i) ((x >> i) & 1)
#define inf 1410065407

int n;
int a[maxn], b[maxn], fl[maxn], posa[maxn], posb[maxn];
ll f[1 << maxn];

void init(){
    cin >> n;
    for(int i = 0;i < n; i ++) {
        cin >> a[i];
        a[i] --;
        posa[a[i]] = i;
    }
    for(int i = 0;i < n; i ++) {
        cin >> b[i];
        b[i] --;
        posb[b[i]] = i;
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            if(posa[i] < posa[j] && posb[i] < posb[j]) fl[i] += 1 << j;
        }
    }
    for(int i = 0; i < n; i ++) f[1 << i] = 1;
}

bool check(int x, int i){
    return (x & fl[i]) == 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();
    for(int x = 0; x < 1 << n; x ++){
        for(int i = 0; i < n; i ++){
            if(! bit(x, i) && check(x, i)) {
                f[x + (1 << i)] += f[x];
            }
        }
    }
    ll res = f[(1 <<n) - 1];
    cout << res;
    return 0;
}