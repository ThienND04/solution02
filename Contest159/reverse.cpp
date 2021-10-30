#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 100001
#define task "reverse"
#define BLOCK_SIZE 100001

// #define inf 1e18

#define inBlock(pos) ((pos - 1) / BLOCK_SIZE + 1)

#define reset(a) memset(a, 0, sizeof(a))

int n;
string s[2][maxn];
int e[maxn];
ll dp[2][maxn];

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> e[i];
    }
    for(int i = 1; i <= n; i ++) {
        cin >> s[0][i];
        s[1][i] = s[0][i];
        reverse(s[1][i].begin(), s[1][i].end());
    }
}

ll solve(){
    memset(dp, 99, sizeof(dp));
    dp[0][1] = 0;
    dp[1][1] = e[1];
    for(int i = 2; i <= n; i ++){
        if(s[0][i - 1] <= s[1][i]) dp[1][i] = min(dp[1][i], dp[0][i - 1] + e[i]);
        if(s[1][i - 1] <= s[1][i]) dp[1][i] = min(dp[1][i], dp[1][i - 1] + e[i]);
        if(s[0][i - 1] <= s[0][i]) dp[0][i] = min(dp[0][i], dp[0][i - 1]);
        if(s[1][i - 1] <= s[0][i]) dp[0][i] = min(dp[0][i], dp[1][i - 1]);
    }
    ll result = min(dp[0][n], dp[1][n]);
    if(result == dp[0][0]) return -1;
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    cout << solve();
    return 0;
}