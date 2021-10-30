#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 2020
#define task "jump"
#define BLOCK_SIZE 100001

#define maxc 5

#define mod 998244353
#define inf 2100000000

// #define inf 1e18

#define inBlock(pos) ((pos - 1) / BLOCK_SIZE + 1)

#define reset(a) memset(a, 0, sizeof(a))

#define bit(x, i) ((x >> i) & 1)

int r, c, k;
int a[maxn][4];
int dp[2][16][maxn];
vector<pii> mask;

bool ok(int x){
    for(int i = 1; i < c; i ++){
        if(bit(x, i) && bit(x, i - 1)) return 0;
    }
    return 1;
}

bool ok(int x, int y){
    for(int j = 0; j < c; j ++){
        if(bit(x, j) && bit(y, j)) return 0;
    }
    return 1;
}

void init(){
    cin >> r >> c >> k;
    for(int i = 1; i <= r; i ++){
        for(int j = 0; j < c; j ++){
            cin >> a[i][j];
        }
    }
}

int solve(){
    for(int i = 0; i < (1 << c); i ++){
        for(int j = 0; j < (1 << c); j ++){
            if(ok(i) && ok(j) && ok(i, j)) mask.push_back({i, j});
        }
    }
    for(int j = 0; j < (1 << c); j ++){
        for(int t = 0; t < maxn; t ++) dp[1][j][t] = -inf;
    }
    for(int j = 0; j < (1 << c); j ++){
        for(int t = 1; t < maxn; t ++) dp[0][j][t] = -inf;
    }
    for(int i = 1; i <= r; i ++){
        for(pii p: mask){
            int x = p.first, y = p.second;
            int cnt = __builtin_popcount(x), d = 0;
            for(int j = 0; j < c; j ++){
                if(bit(x, j)) d += a[i][j];
            }
            for(int t = 0; t <= k; t ++){
                dp[i & 1][x][t + cnt] = max(dp[i & 1][x][t + cnt], dp[(i + 1) & 1][y][t] + d);
            }
        }
        for(int j = 0; j < 16; j ++){
            for(int t = 0; t < maxn; t ++) dp[(i + 1) & 1][j][t] = -inf;
        }
    }
    int result = -inf;
    for(int x = 0; x < (1 << c); x ++){
        if(ok(x)) result = max(result, dp[r & 1][x][k]);
    }
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