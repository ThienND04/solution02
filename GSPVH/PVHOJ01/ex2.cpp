#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "ex2"
#define maxn 11
#define inf 1000000007
#define mod 998244353

int n, maxSquid, r, maxDelta;
int p[maxn];
int cnt[101][100001], sum[101][100001];

void Add(int& x1, int x2){
    x1 += x2;
    if(x1 >= mod) x1 -= mod;
}

void Sub(int& x1, int x2){
    x1 -= x2;
    if(x1 < 0) x1 += mod;
}


void init(){
    cin >> n >> maxSquid >> r >> maxDelta;
    for(int i = 1; i <= n; i ++) cin >> p[i];
    for(int i = 0; i <= r * maxSquid; i ++) sum[0][i] = 1;

    for(int i = 1; i <= r; i ++){
        for(int j = 0; j <= r * maxSquid; j ++){
            cnt[i][j] = sum[i - 1][j];
            if(j > maxSquid) Sub(cnt[i][j], sum[i - 1][j - maxSquid - 1]);
            sum[i][j] = cnt[i][j];
            if(j > 0) Add(sum[i][j], sum[i][j - 1]);
        }
    }
}

int cntWay(int minAll, int maxAll){
    int res = 1;
    for(int i = 1; i <= n; i ++){
        int low = max(0, minAll - p[i]);
        int high = min(maxAll - p[i], r * maxSquid);
        if(low > high) return 0;
        int num = sum[r][high];
        if(low > 0) Sub(num, sum[r][low - 1]);
        res = (1ll * res * num) % mod;
    }
    return res;
}

void solve(){
    int minStart = p[1];
    int result = 0;
    for(int i = 1; i <= n; i ++){
        minStart = min(minStart, p[i]);
    }
    for(int i = minStart; i <= minStart + r * maxSquid; i ++){
        int j = i + maxDelta;
        Add(result, cntWay(i, j));
        Sub(result, cntWay(i + 1, j));
    }
    cout << result;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    init();
    solve();
    return 0;
}