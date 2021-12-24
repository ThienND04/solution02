// Mitsuhina43
#include <bits/stdc++.h>
#define Random(lf, rt) (lf + rand() % (rt - lf + 1))
#define oo 3000000007
#define mod 1000000007
#define PB push_back
#define all(z) z.begin(), z.end()
#define ii pair<int, int>
#define Getbit(z, l) ((z >> l) & 1)
#define sobit(z) __builtin_popcount(z)
#define sz(z) (int) z.size()
#define maxn 100011
#define F first
#define S second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define reset(i, a) memset(i, a, sizeof(i))
#define TASK "h"
using namespace std;
typedef long long ll;
typedef long double ld;

int n, m, cnt, res;
vector<int> t[9000];
int x[111];
int dp[111][9000];
vector<int> ke[9000];

void Try(int pos){
    if(pos > m){
        t[++cnt].assign(x + 1, x + m + 1);
        return;
    }
    x[pos] = 0;
    Try(pos + 1);
    if(x[pos - 1] != 2){
        x[pos] = 1;
        Try(pos + 1);
    }
    if(x[pos - 1] != 1){
        x[pos] = 2;
        Try(pos + 1);
    }
}

void Init(){
    if(m > n) swap(n, m);
}

int Builtin(int i){
    int k = 0;
    FOR(j, 0, m-1)
        k += (t[i][j] != 0);
    return k;
}

bool Check(int tt1, int tt2){
    FOR(i, 0, m-1){
        if(t[tt1][i] == 1){
            if(t[tt2][i] == 2) return 0;
            if(i < m - 1 && t[tt2][i + 1] == 1) return 0;
        }
        if(t[tt1][i] == 2){
            if(t[tt2][i] == 1) return 0;
            if(i > 0 && t[tt2][i - 1] == 2) return 0;
        }
    }
    return 1;
}

void Solve(){
    cnt = 0;
    reset(dp, 0);
    reset(t, 0);
    Try(1);
//    for(int i = 1; i <= cnt; i++){
//        for(int j = 0; j < m; j++) cout << t[i][j] << " ";
//        cout << "\n";
//    }
    FOR(x, 1, cnt) FOR(y, 1, cnt){
        if(Check(x, y)) ke[x].PB(y);
    }
    FOR(i, 1, cnt) dp[1][i] = Builtin(i);
    res = m;
    FOR(i, 2, n){
        FOR(x, 1, cnt){
            dp[i][x] = 0;
            for(int y : ke[x]){
                dp[i][x] = max(dp[i][x], dp[i - 1][y] + Builtin(x));
            }
            res = max(res, dp[i][x]);
        }
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    while(cin >> n >> m){
        Init();
        Solve();
    }
    return 0;
}