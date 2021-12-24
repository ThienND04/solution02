#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "arithmetic"
#define maxn 3006
#define inf 1000000007
#define mod 998244353

int m, n, t;
int a[maxn][maxn];
int Right[maxn][maxn], Up[maxn][maxn], Down[maxn][maxn];
int tren[maxn][maxn], duoi[maxn][maxn], st[maxn];

void init(){
    cin >> m >> n;
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
    }
    for(int j = 1; j <= n; j ++) Right[m + 1][j] = 0;
    for(int i = 1; i <= m; i ++){
        for(int j = n; j >= 1; j --){
            if(j == n) Right[i][j] = 1;
            else if(j == n - 1) Right[i][j] = 2;
            else {
                if(a[i][j + 1] - a[i][j] == a[i][j + 2] - a[i][j + 1]) Right[i][j] = 1 + Right[i][j + 1];
                else Right[i][j] = 2;
            }
        }
    }
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){
            if(i == 1) Up[i][j] = 1;
            else if(i == 2) Up[i][j] = 2;
            else{
                if(a[i][j] - a[i - 1][j] == a[i - 1][j] - a[i - 2][j]) Up[i][j] = Up[i - 1][j] + 1;
                else Up[i][j] = 2;
            }
        }
    }
    for(int i = m; i >= 1; i --){
        for(int j = 1; j <= n; j ++){
            if(i == m) Down[i][j] = 1;
            else if(i == m - 1) Down[i][j] = 2;
            else{
                if(a[i + 1][j] - a[i][j] == a[i + 2][j] - a[i + 1][j]) Down[i][j] = Down[i + 1][j] + 1;
                else Down[i][j] = 2;
            }
        }
    }
}

void initTrenDuoi(){
    for(int j = 1; j <= n; j ++){
        int sz = 0;
        st[++ sz] = 0;
        for(int i = 1; i <= m; i ++){
            while(Right[st[sz]][j] >= Right[i][j]) sz --;
            tren[i][j] = st[sz];
            st[++ sz] = i;
        }
    }
    for(int j = 1; j <= n; j ++){
        int sz = 0;
        st[++ sz] = m + 1;
        for(int i = m; i >= 1; i --){
            while(Right[st[sz]][j] >= Right[i][j]) sz --;
            duoi[i][j] = st[sz];
            st[++ sz] = i;
        }
    }
}

void solve(){
    int res = 0;
    // tinh 1 cot
    for(int j = 1; j <= n; j ++){
        for(int i = 1; i <= m; i ++){
            int tr = Up[i][j];
            int du = Down[i][j];
            if(i == m){
                res = max(res, tr);
                continue;
            }
            else if(i == 1){
                res = max(res, du);
                continue;
            }
            if(a[i][j] - a[i - 1][j] == a[i + 1][j] - a[i][j]){
                res = max(res, du + tr - 1);
            }
            else {
                res = max(res, tr);
                res = max(res, du);
            }
        }
    }
    for(int j = 1; j < n; j ++) {
        for(int i = 1; i <= m; i ++){
            if(Right[i][j] < 2) continue;
            int tr = min(i - tren[i][j], Up[i][j]);
            tr = min(tr, min(i - tren[i][j + 1], Up[i][j + 1]));
            int du = min(duoi[i][j] - i, Down[i][j]);
            du = min(du, min(duoi[i][j + 1] - i, Down[i][j + 1]));
            if(i == 1){
                res = max(res, Right[i][j] * du);
                continue;
            }
            else if(i == m){
                res = max(res, Right[i][j] * tr);
                continue;
            }
            if(a[i][j] - a[i - 1][j] == a[i + 1][j] - a[i][j] && \
                a[i][j + 1] - a[i - 1][j + 1] == a[i + 1][j + 1] - a[i][j + 1]){
                    res = max(res, Right[i][j] * (tr + du - 1));
            }
            else{
                res = max(res, Right[i][j] * tr);
                res = max(res, Right[i][j] * du);
            }
        }
    }
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> t;
    while(t --){
        init();
        initTrenDuoi();
        solve();
    }
    return 0;
}