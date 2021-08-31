#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 11
#define task "cond"
#define inf 1000000000

ll dp[maxn][maxn];

void init(){
    dp[1][1] = 1;
    for(int i = 2; i <= 10; i ++){
        for(int j = 1; j <= i; j ++){
            dp[i][j] = dp[i - 1][j] * j;
            if(j > 1) dp[i][j] += dp[i - 1][j - 1] * j;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r",  stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    int n;
    while(cin >> n) {
        if(n == -1) break;
        ll res = 0;
        for(int i = 1; i <= n; i ++) res  += dp[n][i];
        cout << res << "\n";
    }
    return 0;
}