#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "kibibits"
#define inf 1e9
#define mod 998244353
#define maxn 102
#define delta 0.0000001

int t, n;
int x[maxn];
int dp[maxn][2][10][10][100001];

void add(int& a, int b){
    a += b;
    if(a > mod) a -= mod;
}

ll solve(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> x[i];
    for(int i = 1; i <= n; i ++) for(int c = 0; c < 10 ; c ++) for(int dv = 0; dv < 10; dv ++){

    }
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> t;
    while(t --) cout << solve() << "\n";
    return 0;
}