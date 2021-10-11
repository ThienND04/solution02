#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "digits"
#define maxn 5001
#define inf 1e18
// #define mod 1000000007

const int mod = (1e9) + 19972207;

int n, k, p;
string s;
int dp[maxn][201];

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
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int t = 0; t < k; t ++){
            int tmp = 0;
            for(int j = i; j <= n; j ++){
                tmp = tmp * 10 + s[j] - '0';
                tmp %= p;
                if(tmp == 0) Add(dp[j][t + 1], dp[i - 1][t]);
            }
        }
    }
    cout << dp[n][k];
    return 0;
}