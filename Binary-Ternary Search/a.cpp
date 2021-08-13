#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "a"
#define maxn 100001

int n, m;
int a[maxn], b[maxn];

bool check(int t){
    int i = 1, j = 1;
    for(int i = 1; i <= n;  i++){
        if(a[i] >= t) continue;
        while(j <= m && a[i] + b[j] < t){
            j ++;
        }
        if(j > m) return 0;
        j ++;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    cin >> m;
    for(int i = 1; i <= m; i ++) cin >> b[i];
    int l = 0, r = 1000000000;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
    return 0;
}