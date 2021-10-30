#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "pnum"
#define maxn 51
#define inf 1000000007

#define bit(x, i) ((x >> i) & 1)

int mod;

int n, k, m;
int p[maxn];
ll POW10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

vector<ll> number;
map<ll, int> cntPrefix, cntSuffix;

bool ok(ll x){
    int digit[10];
    for(int i = 0; i < 10; i ++){
        digit[i] = x % 10;
        x /= 10;
    }
    for(int i = 0; i < (1 << 10); i ++){
        if(i & 1){
            int sum = 0;
            for(int j = 0; j < 10; j ++){
                if(bit(i, j)){
                    sum += digit[j];
                }
            }
            if(sum == 10) return 1;
        }
    }
    return 0;
}

void backtrack(int step, int sum, ll x){
    if(step == 10){
        if(sum == 20 && ok(x)) {
            number.push_back(x);
        }
        return;
    }
    if(sum + 10 - step > 20) return ;
    for(int i = 1; i <= k; i ++) backtrack(step + 1, sum + i, x * 10 + i);
}

ll prefix(ll x, int i){
    return x / POW10[10 - i];
}

ll suffix(ll x, int i){
    return x % POW10[i];
}

void init(){
    cin >> n >> k >> m >> mod;
    for(int i = 1; i <= m; i ++) cin >> p[i];
}

int POW(int x, int y){
    int result = 1;
    for(int i = 0; i < y; i ++){
        result = (1ll * result * x) % mod;
    }
    return result;
}

void solve(){
    backtrack(0, 0, 0);
    assert(m <= 2);
    cerr << number.size() << "\n";
    // cerr << POW(k, n - 10) * number.size();
    if(m == 1){
        cout << (1ll * number.size() * POW(k, n - 10)) % mod;
        return ;
    }

    int com = max(0, p[1] + 10 - p[2]);
    int numFree = n - 20 + com;
    ll res = 0;

    if(com == 0) {
        cout << (1ll * number.size() * number.size() * POW(k, n - 20)) % mod;
        return ;
    }
    cerr << com << endl;

    for(ll x: number){
        cntPrefix[prefix(x, com)] ++;
        cntSuffix[suffix(x, com)] ++;
    }

    for(pii i: cntPrefix){
        res = (res + 1ll * cntSuffix[i.first] * cntPrefix[i.first]) % mod;
    }
    cout << (1ll * res * POW(k, numFree)) % mod;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    init();
    solve();
    return 0;
}
