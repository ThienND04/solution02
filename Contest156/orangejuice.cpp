#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 2048
#define task "orangejuice"

#define reset(a) memset(a, 0, sizeof(a))

#define BIGMOD (mod > 1e9)

int subtask, n, q, mod;
int a[maxn], finv[maxn], comb[maxn][maxn];

void add(int& x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

#define sum(a, b) (a + b >= mod ? a + b - mod : a + b)

int POW(int x, int k){
    int res = 1;
    int mul = x;
    while(k > 0){
        if(k & 1) res = (1ll * res * mul) % mod;
        mul = (1ll * mul * mul) % mod;
        k >>= 1;
    }  
    return res;
}

void precalc(){
    if(BIGMOD){
        for(int i = 1; i <= n; i ++){
            finv[i] = POW(i, mod - 2);
        }
    }
    else{
        for(int i = 1; i <= mod; i ++){
            comb[i][0] = 1;
            comb[0][i] = 1;
        }
        comb[0][0] = 1;
        for(int i = 1; i <= mod; i ++){
            for(int j = 1; j <= mod; j ++){
                if(i == j) comb[i][j] = 1;
                if(i < j){
                    comb[i][j] = sum(comb[i][j - 1], comb[i - 1][j - 1]);
                }
            }
        }
    }
}

int curComb;

int getComb(int k, int _n){
    if(BIGMOD){
        if(k == 0) return (curComb = 1);
        curComb = (1ll * curComb * (_n - k + 1) % mod) * finv[k] % mod;
        return curComb;
    }
    else return comb[k][_n];
}

void init(){
    cin >> subtask >> n >> q >> mod;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    precalc();
}

int f[maxn][maxn], g[maxn][maxn], cntWay[maxn][maxn];

void prepare(){
    f[0][0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j <= n; j ++){   
            if(f[i - 1][j] == 0) continue;
            for(int k = 0; k <= a[i] && j + k * i <= n; k ++){
                int tmp = getComb(k, a[i]);
                add(f[i][j + k * i], 1ll * f[i - 1][j] * tmp % mod);
            }
        }   
    }
    g[n + 1][0] = 1;
    for(int i = n; i >= 1; i --){
        for(int j = 0; j <= n; j ++){
            if(g[i + 1][j] == 0) continue;
            for(int k = 0; k <= a[i] && j + k * i <= n; k ++){
                int tmp = getComb(k, a[i]);
                add(g[i][j + k * i], 1ll * g[i + 1][j] * tmp % mod);
            }
        }
    }
    memset(cntWay, -1, sizeof(cntWay));
}

int countWay(int pos, int sum){
    if(cntWay[pos][sum] >= 0) return cntWay[pos][sum];
    cntWay[pos][sum] = 0;
    for(int i = 0; i <= sum; i ++) {
        add(cntWay[pos][sum], 1ll * f[pos - 1][i] * g[pos + 1][sum - i] % mod);
    }
    return cntWay[pos][sum];
}

int query(int p, int d, int s){
    int result = 0;
    for(int k = 0; k <= a[p] - d && k * p <= s; k ++){
        int tmp = getComb(k, a[p] - d);
        add(result, 1ll * tmp * countWay(p, s - k * p) % mod);
    }
    return result;
}

void solve(){
    while(q --){
        int p, d, s;
        cin >> p >> d >> s;
        cout << query(p, d, s) << "\n";
    }
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
    reset(f); reset(g);
    init();
    prepare();
    solve();
    return 0;
}