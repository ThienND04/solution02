#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "h-grid1"
#define maxn 1001
#define inf 1000000007
#define mod 1000000007

int h, w;
string mp[maxn];
int dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> h >> w;
    for(int i = 1; i <= h; i ++) {
        cin >> mp[i];
        mp[i] = " " + mp[i];
    }
    reset(dp);
    for(int i = 1; i <= h; i ++){
        for(int j = 1; j <= w; j ++){
            if(mp[i][j] == '#') continue;
            if(i == 1 && j == 1){
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    cout << dp[h][w];
    return 0;
}