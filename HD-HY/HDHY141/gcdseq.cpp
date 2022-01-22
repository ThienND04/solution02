 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "gcdseq"
#define inf 1e9
#define mod 1000000007
#define maxn 200100

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 20
#define ALPHABET 26

namespace caculate{
    template<class T>
    void add(T& x, T y){
        x += y;
        if(x >= mod) x -= mod;
    }
    template<class T>
    void sub(T& x, T y){
        x -= y;
        if(x < 0) x += mod;
    }
    template<class T>
    void maximize(T& x, T y){
        if(x < y) x = y;
    }
    template<class T>
    void minimize(T& x, T y){
        if(x > y) x = y;
    }
}

using namespace caculate;

struct Data{
    int l, r, c;
};

namespace process{
    int n, m;
    int a[maxn];
    int d[21][maxn], cnt[21];
    Data queries[maxn];
    ll g[maxn][LOG];

    ll lcm(ll x, ll y){
        return 1ll * x * y / __gcd(x, y);
    }

    void initA(){
        reset(d);
        reset(cnt);
        cin >> n >> m;
        for(int i = 1; i <= m; i ++) {
            int l, r, c;
            cin >> l >> r >> c;
            queries[i] = {l, r, c};
            d[c][l] ++;
            d[c][r + 1] --;
        }
        for(int i = 1; i <= n; i ++){
            a[i] = 1;
            for(int j = 1; j <= 20; j ++){
                cnt[j] += d[j][i];
                if(cnt[j]) a[i] = lcm(a[i], j);
            }
        }
    }

    int getGcd(int l, int r){
        int h = r - l + 1;
        ll res = -1;
        for(int i = 0; i < LOG; i ++){
            if(bit(h, i)){
                if(res == -1) res = g[l][i];
                else res = __gcd(res, g[l][i]);
                l += (1 << i);
            }
        }
        return res;
    }

    bool check(){
        for(int i = 1; i <= n; i ++) g[i][0] = a[i];
        for(int j = 1; j < LOG; j ++){
            for(int i = 1; i + (1 << j) - 1 <= n; i ++){
                g[i][j] = __gcd(g[i][j - 1], g[i + (1 << j - 1)][j - 1]);
            }
        }

        for(int i = 1; i <= m; i ++){
            if(getGcd(queries[i].l, queries[i].r) != queries[i].c) return 0;
        }
        return 1;
    }

    void process(){
        initA();
        if(check()){
            for(int i = 1; i <= n; i ++) cout << a[i] << " ";
        }
        else cout << -1;
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
    process::process();
    return 0;
}
