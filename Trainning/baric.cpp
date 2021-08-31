#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 103
#define task "baric"
#define inf 1000000000

int n, e;
int m[maxn];
int dp[maxn][maxn];
int s[maxn][maxn];

void init(){
    cin >> n >> e;
    for(int i = 1; i <= n; i ++) cin >> m[i];
    for(int i = 0; i <= n; i ++){
        for(int j = i + 1; j <= n + 1; j ++){
            if(i == 0 && j == n + 1) {
                s[i][j] = -1;
                continue;
            }
            if(i == 0) m[i] = m[j];
            else if(j == n + 1) m[j] = m[i];
            int tmp = 0;
            for(int k = i + 1; k < j; k ++){
                tmp += abs(2 * m[k] - (m[i] + m[j]));
            }
            s[i][j] = tmp;
        }
    }
}

void xuat(){
    for(int i = 0; i <= n + 1; i ++){
        if(dp[n + 1][i] >= 0 && dp[n + 1][i] <= e){
            cout << i - 1 << " " << dp[n + 1][i];
            return;
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
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n + 1; i ++){
        for(int j = 0; j < i; j ++){
            for(int k = 0; k <= n; k ++){
                if(dp[j][k] != -1){
                    int tmp = dp[j][k] + s[j][i];
                    if(dp[i][k + 1] == -1) dp[i][k + 1] = tmp;
                    else dp[i][k + 1] = min(dp[i][k + 1], tmp);
                }
            }
        }
    }
    xuat();
    return 0;
}