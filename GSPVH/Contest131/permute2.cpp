#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "permute"
#define inf 1e9
#define maxn 400001
#define delta 0.0000001
#define mod 998244353

int t, n, m;
int a[maxn], p[maxn], b[maxn], tmp[maxn], res = 0;
bool check[maxn];

void init(){
    cin >> t >> n;
    m = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(a[i] != -1) check[a[i]] = 1;
    }
    for(int i = 1; i <= n; i ++) {
        if(! check[i]) {
            b[++ m] = i;
        }
    }
    m = 0;
    sort(b + 1, b + m + 1);
    for(int i = 1; i <= n; i ++){
        if(a[i] == -1){
            p[++ m] = i;
        }
    }
}

bool kt(){
    for(int i  = 1; i <= m; i ++){
        if(tmp[i] == p[i]) return 0;
    }
    return 1;
}

void duyet(int no){
    if(no == m){
        res += kt();
        return;
    }
    for(int i = 1; i <= m; i ++){
        if(! check[b[i]]){
            check[b[i]] = 1;
            tmp[no + 1] = b[i];
            duyet(no + 1);
            check[b[i]] = 0;
        }
    }
}

int solve(){
    duyet(0);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    cout << solve();
    return 0;
}