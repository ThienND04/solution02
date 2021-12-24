#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bonus"
#define inf 1e18
#define mod 1000000007
#define maxn 20

// Naive code: 
// m = 1 
// n <= 10

int m, n;
int a[maxn][maxn];

ll res = -inf;

int pos[maxn];

void init(){
    cin >> m >> n;
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> a[i][j];
        }
    }
}

void calc(int k){
    ll ans = 0;
    for(int i = 1; i <= k; i ++){
        ans += a[1][pos[i]];
    }
    res = max(res, abs(ans));
    // if(res == 22) {
    //     for(int i = 1; i <= k; i ++) cerr << pos[i] << " ";
    //     exit(0);
    // }
}

void Try(int k){
    for(int i = 1; i <= n; i ++){
        if(k <= 1) {
            if(i != pos[k]){
                pos[k + 1] = i;
                Try(k + 1);
            }
        }
        else{
            if(abs(pos[k] - pos[k - 1]) < abs(pos[k] - i)) {
                pos[k + 1] = i;
                Try(k + 1);
            }
        }
    }
    if(k >= 3) calc(k);
}

void solve(){
    pos[0] = 0;
    Try(0);
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    solve();
    return 0;
}