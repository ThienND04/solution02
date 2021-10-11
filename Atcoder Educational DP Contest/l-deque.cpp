#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "l-deque"
#define maxn 3001
#define inf 1000000007
#define mod 1000000007

int n;
int a[maxn];
ll dp[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++){
        dp[i][i] = a[i];
    }
    for(int d = 2; d <= n; d ++){
        for(int l = 1; l + d - 1 <= n; l ++){
            int r = l + d - 1;
            dp[l][r] = max(a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
        }
    }
    cout << dp[1][n];
    return 0;
}