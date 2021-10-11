#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a))
#define task "spell"
#define mod 1000000007
#define mod2 (1ll * mod * mod)
#define X 10000007
#define inf 999999999
#define maxn 1000001

int h[maxn];

class Hash{
private:
    string s;
    vector<ll> hs;
    int n;
public:
    /// base: 1 -> n
    Hash(){

    }
    Hash(string s){
        this-> s = s;
        n = s.size();
        hs.resize(s.size());
        init();
    }
    void init(){
        for(int i = 1; i < n; i ++){
            hs[i] = (hs[i - 1] * X + s[i]) % mod;
        }
    }
    ll get(int l, int r){
        return (hs[r] - hs[l - 1] * h[r - l + 1] + mod2) % mod;
    }
    int size(){
        return n;
    }
};

string s;
string rs;

Hash h1, h2;

int n;
int lr[maxn], q[maxn];
int maxl[maxn][2], maxr[maxn][2];

int dx(int p){  
    return n - p + 1;
}

int calc(int p){
    // cerr << s << "\n" <<  rs;
    int lf = 1, rt = n;
    while(rt - lf > 1){
        int mid = (lf + rt) / 2;
        // string s1 = s.substr(p, mid), s2 = rs.substr(dx(p), mid);
        ll hs1 = h1.get(p, p + mid - 1), hs2 = h2.get(dx(p), dx(p - mid + 1));
        if(hs1 == hs2) lf = mid;
        else rt = mid;
    }
    return lf;
}

void init(){
    cin >> s;
    rs = s;
    n = s.size();
    h[0] = 1;
    for(int i = 1; i <= n; i ++) h[i] = (1ll * h[i - 1] * X) % mod;
    reverse(rs.begin(), rs.end());
    s = ' ' + s;
    rs = ' ' + rs;
    h1 = Hash(s);
    h2 = Hash(rs);
    
    for(int i = 1; i <= n; i ++){
        lr[i] = calc(i);
    }
    int lf = 0, rt = 0;
    for(int i = 1; i <= n; i ++){
        while(lf < rt && min(i - q[lf] + 1, lr[q[lf]]) <= min(i - q[lf + 1] + 1, lr[q[lf + 1]])) lf ++;
        maxl[i][1] = min(i - q[lf], lr[q[lf]]);
        maxl[i][0] = min(i - q[lf] + 1, lr[q[lf]]);
        if(lr[i] > lr[q[rt]]) q[++ rt] = i;
    }
    lf = 0, rt = 0;
    for(int i = n; i >= 1; i --){
        while(lf < rt && min(q[lf] - i + 1, lr[q[lf]]) <= min(q[lf + 1] - i + 1, lr[q[lf + 1]])) lf ++;
        maxr[i][1] = min(q[lf] - i, lr[q[lf]]);
        maxr[i][0] = min(q[lf] - i + 1, lr[q[lf]]);
        if(lr[i] > lr[q[rt]]) q[++ rt] = i;
    }
}

void solve(){
    ll res = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < 2; j ++) {
            maxl[i][j] = max(0, maxl[i][j] * 2 - 1);
            maxr[i][j] = max(0, maxr[i][j] * 2 - 1);
        }
    }
    for(int i = 1; i <= n; i ++){
        ll s1 = 1ll * maxl[i][0] * maxr[i][1];
        ll s2 = 1ll * maxl[i][1] * maxr[i][0];
        ll s3 = 1ll * maxl[i][1] * maxr[i][1];
        res = max(res, s1);
        res = max(res, s2);
        res = max(res, s3);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) {freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    init();
    solve();
    return 0;
}