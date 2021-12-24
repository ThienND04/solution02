#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "b"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

#define B 10000017
#define B2 1000271

#define bit(x, i) ((x >> i) & 1)

int n;
string s[maxn];
vector<int> Hs[maxn], Hs2[maxn];
int lt[maxn], lt2[maxn], minSize = 1e9;

const ll mod2 = 1ll * mod * mod;

int getXoay(int i, int l, int t){
    int ans = (Hs[i][l + t - 1] - 1ll * Hs[i][l - 1] * lt[t] + mod2) % mod;
    return ans;
}

int getXoay2(int i, int l, int t){
    int ans = (Hs2[i][l + t - 1] - 1ll * Hs2[i][l - 1] * lt2[t] + mod2) % mod;
    return ans;
}

void calc(int i){
    Hs[i].resize(s[i].size());
    Hs[i][0] = 0;
    for(int j = 1; j < s[i].size(); j ++){
        Hs[i][j] = (1ll * Hs[i][j - 1] * B + s[i][j]) % mod;
    }
    Hs2[i].resize(s[i].size());
    Hs2[i][0] = 0;
    for(int j = 1; j < s[i].size(); j ++){
        Hs2[i][j] = (1ll * Hs2[i][j - 1] * B2 + s[i][j]) % mod;
    }
}

bool check(int x){
    map<pii, int> cnt;
    for(int i = 1; i <= n; i ++){
        set<pii> v;
        for(int j = 1; j <= s[i].size() / 2; j ++) {
            int tmp = getXoay(i, j, x);
            int tmp2 = getXoay2(i, j, x);
            v.insert({tmp, tmp2});
        }
        for(pii e: v) cnt[e] ++;
    }
    for(auto i: cnt){
        if(i.second == n) return 1;
    }
    return 0;
}

void solve(){
    assert(minSize >= 0);
    int l = 0, r = minSize + 1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    lt[0] = lt2[0] = 1;
    cin >> n;
    for(int i = 1; i < maxn; i ++) {
        lt[i] = (1ll * lt[i - 1] * B) % mod;
        lt2[i] = (1ll * lt2[i - 1] * B2) % mod;
    }
    for(int i = 1; i <= n; i ++){
        cin >> s[i];
        int tmp = s[i].size();
        if(minSize > tmp) {
            minSize = tmp;
        }
        s[i] = " " + s[i] + s[i];
        calc(i);
    }
    for(int i = 1; i <= n; i ++) calc(i);
    solve();
    return 0;
}