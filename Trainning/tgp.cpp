#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 1000001
#define task "tgp"
#define inf 1000000000
#define bit(x, i) ((x >> i) & 1)

int n;
int dp[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r",  stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    dp[4] = 1;
    dp[5] = 2;
    for(int i = 6; i <= n; i ++){
        dp[i] = dp[i / 3 + i % 3] + 2;
    }
    cout << dp[n];
    return 0;
}