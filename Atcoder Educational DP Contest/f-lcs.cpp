#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "f-lcs"
#define maxn 3001
#define inf 1000000007
#define mod 998244353

int n, m;
string s, t;
int dp[maxn][maxn];

void trace(){
    string res = "";
    while(n && m){
        if(s[n] == t[m]) {
            res += s[n];
            n --;
            m --;
            continue;
        }
        if(dp[n][m] == dp[n - 1][m]){
            n --;
            continue;
        }
        if(dp[n][m] == dp[n][m - 1]){
            m --;
            continue;
        }
        if(dp[n][m] == dp[n - 1][m - 1]){
            n --;
            m --;
            continue;
        }
    }
    reverse(res.begin(), res.end());
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> s >> t;
    n = s.size(), m = t.size();
    s = " " + s;
    t = " " + t;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(s[i] == t[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }
    // cout << dp[n][m];
    trace();
    return 0;
}