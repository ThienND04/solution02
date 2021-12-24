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
int p[maxn], res = 0;

int POW(int num1, int num2){
    //return num1 ** num2;
    int result = 1;
    for(int i = 0; i <= num2; i ++){
        result = (1ll * num1) % mod;
    }
    return result;
}

void init(){
    cin >> n >> maxSquid >> r >> maxDelta;
    for(int i = 1; i <= n; i ++) cin >> p[i];
}

void subtask1(){
    cout << POW(maxSquid + 1, r);
    exit(0);
}

bool check(){
    for(int i = 1; i <= n; i ++){
        for(int j = i + 1; j <= n; j ++){
            if(abs(p[i] - p[j]) > maxDelta) return 0;
        }
    }
    return 1;
}

void Try(int pp, int ll){
    if(ll == r){
        res += check();
        return; 
    }
    if(pp == n + 1){
        Try(1, ll + 1);
        return;
    }
    for(int i = 0; i <= maxSquid; i ++){
        p[pp] += i;
        Try(pp + 1, ll);
        p[pp] -= i;
    }
}

void solve(){
    if(n == 1) subtask1();
    Try(1, 0);
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    init();
    solve();
    return 0;
}