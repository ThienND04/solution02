#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 100001
#define task "candy"
#define inf 1000000000

int n, m;
int a[maxn], b[101];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r",  stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= m; i ++) cin >> b[i];
    int res = 0;
    int j = 1;
    for(int i = 1; i <= m; i ++){
        int sum = 0;
        while(j <= n && sum < b[i]) sum += a[j ++];
        if(sum < b[i]) {
            cout << -1;
            return 0;
        }
        res += abs(sum - b[i]);
    }
    for(; j <= n; j ++) res += a[j];
    cout << res;
    return 0;
}