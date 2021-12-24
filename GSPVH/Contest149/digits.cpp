#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "digits"
#define maxn 50001
#define inf 1e18
// #define mod 1000000007

const int mod = (1e9) + 19972207;

int n, k, p;
string s;
int dp[2][302][30];

void Add(int& x, int y){
    x += y;
    if(x > mod) x -= mod;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n >> k >> p;
    cin >> s;
    s = " " + s;
    dp[1][1][(s[1] - '0') % p] = 1;
    for(int i = 1; i < n; i ++){
        for(int j = 0; j <= k; j ++){
            for(int t = 0; t < p; t ++){
                if(dp[i & 1][j][t] == 0) continue;
                Add(dp[(i + 1) & 1][j][(t * 10 + s[i + 1] - '0') % p], dp[i & 1][j][t]);
                if(j < k && t == 0) Add(dp[(i + 1) & 1][j + 1][(s[i + 1] - '0') % p], dp[i & 1][j][t]);
                dp[i & 1][j][t] = 0;
            }
        }
    }
    cout << dp[n & 1][k][0];
    return 0;
}