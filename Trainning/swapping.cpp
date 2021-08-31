#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 50001
#define task "swapping"
#define inf 1000000000

int n, m, k;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r",  stdin);
        freopen(task ".out", "w", stdout);
    }

    cin >> k >> m >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    int res = inf;
    for(int i = 1; i <= m + 1; i ++){
        sort(a + 1, a + n + 1);
        res = min(res, a[n] - a[1]);
        if(a[n] < k) break;
        a[n] -= k;
        a[1] += k;
    }
    cout << res;
    return 0;
}