#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "magicians"
#define inf 1e9
#define mod 1000000007
#define maxn 300001

#define bit(x, i) ((x >> i) & 1)

int n, m, t = 1;
int a[maxn], state[81][5], l[5], r[5];
int po3[5];
ll f[maxn][81];
vector<int> pre[81];

ll res = 0;

int get(int x, int i){
    while(i --) x /= 3;
    return x % 3;
}

void init(){
    memset(f, 99, sizeof(f));
    f[0][0] = 0;
    cin >> n >> m; 
    po3[0] = 1;
    for(int i = 1; i <= m; i ++) po3[i] = po3[i - 1] * 3;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 0; i < m; i ++) cin >> l[i] >> r[i];
    t = 1;
    for(int i = 0; i < m; i ++) t *= 3;
    for(int x = 0; x < t; x ++){
        for(int i = 0; i < m; i ++){
            state[x][i] = get(x, i);
        }
    }
    for(int x = 0; x < t; x ++){
        for(int y = 0; y <= x; y ++){
            bool ok = 1;
            for(int j = 0; j < m; j ++){
                int dl = state[x][j] - state[y][j];
                if(dl < 0 || dl > 1) {
                    ok = 0;
                    break;
                }
            }
            if(ok) pre[x].push_back(y);
        }
    }
}

bool In(int i, int lf, int rt){
    return (i >= lf && i <= rt);
}

void calc(int i, int x){
    int sl = m;
    for(int j = 0; j < m; j ++){
        if(state[x][j] == 1 && In(i, l[j], r[j])) {
            sl = j;
            break;
        }
        if(state[x][j] == 1){
            if(i < l[j] || i > r[j]) return;
        }
        else if(state[x][j] == 2){
            if(i <= l[j]) return;
        }
    }
    for(int y: pre[x])  f[i][x] = min(f[i][x], f[i - 1][y]);
    f[i][x] += 1ll * sl * a[i];
}

void solve(){
    memset(f, 99, sizeof(f));
    f[0][0] = 0;
    for(int i = 1; i <= n; i ++){
        for(int x = 0; x < t; x ++){
            calc(i, x);
        }
    }
    ll res = 1e18;
    for(int i = 0; i < t; i ++){
        res = min(res, f[n][i]);
    }
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