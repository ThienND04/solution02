#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "s-digitsum"
#define maxn 101
#define inf 1000000007
#define mod 1000000007

#define maxk 100001

string k;
int d;
int dp[maxn][101];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> k >> d;
    dp[0][(k[0] - '0') % d] = 1;
    for()
    return 0;
}