#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "c-vacation"
#define maxn 100001
#define inf 1000000007
#define mod 998244353

int n;
int hp[maxn][3], abc[maxn][3];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n;
    reset(hp);
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < 3; j ++) cin >> abc[i][j];
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < 3; j ++){
            for(int k = 0; k < 3; k ++){
                if(j != k) hp[i][j] = max(hp[i][j], hp[i - 1][k] + abc[i][j]);
            }
        }
    }
    int res = 0;
    for(int i  =0 ;i < 3; i ++) res = max(res, hp[n][i]);
    cout << res;
    return 0;
}