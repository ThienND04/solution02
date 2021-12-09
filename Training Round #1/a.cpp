#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "a"
#define inf 1e9
#define mod 1000000007
#define maxn 111112

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
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

struct line
{
    ll a, b;
    ll get(int x){
        return a * x + b;
    }
};

namespace process{
    int n, s, c;
    int a[maxn], pre[maxn];
    line it[4 * maxn];
    int low[4 * maxn], high[4 * maxn];
    ll dp[maxn];

    ll query(int node, int pos){
        if(low[node] > pos || high[node] < pos) return -1;
        ll res = it[node].get(pos);
        if(low[node] == high[node]) return res;
        maximize(res, query(node * 2, pos));
        maximize(res, query(node * 2 + 1, pos));
        return res;
    }

    void update(int node, int l, int r, line& val){
        if(low[node] > r || high[node] < l) return;
        if(l <= low[node] && r >= high[node]){
            if(it[node].get(low[node]) >= val.get(low[node]) && \
                it[node].get(high[node]) >= val.get(high[node])) return;
            if(it[node].get(low[node]) <= val.get(low[node]) && \
                it[node].get(high[node]) <= val.get(high[node])) {
                    it[node] = val;
                    return;
            }

            int mid = (low[node] + high[node]) / 2;
            if(it[node].get(low[node]) >= val.get(low[node]) && it[node].get(mid) >= val.get(mid)){
                update(node* 2 + 1, l, r, val);
                return;
            } 
            if(it[node].get(low[node]) <= val.get(low[node]) && it[node].get(mid) <= val.get(mid)){
                update(node* 2 + 1, l, r, val);
                it[node] = val;
                return;
            } 
            if(it[node].get(mid) >= val.get(mid) && it[node].get(high[node]) >= val.get(high[node])){
                update(2 * node, l, r, val);
                return;
            }
            if(it[node].get(mid) <= val.get(mid) && it[node].get(high[node]) <= val.get(high[node])){
                update(2 * node, l, r, val);
                it[node] = val;
                return;
            }
            return;
        }
        update(node * 2, l, r, val);
        update(node * 2 + 1, l, r, val);
    }

    void build(int node, int l = 0, int r = maxn - 1){
        it[node] = {-1, -1};
        low[node] = l;
        high[node] = r;
        if(high[node] == low[node]) return;
        int mid = (low[node] + high[node]) / 2;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
    }

    void init(){
        cin >> n >> s >> c;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        build(1);
        dp[0] = dp[1] = s;
        int x = (s - c) / a[1];
        line tmp = {x, s - x * a[1] - 2 * c};
        update(1, 0, maxn - 1, tmp);
    }

    void trace(int day){
        if(! day) return;
        if(dp[day] == dp[day - 1]) {
            pre[day] = 0;
            return trace(day - 1);
        }
        for(int i = day - 1; i >= 1; i --){
            ll x = (dp[i] - c) / a[i];
            if(dp[i] - x * a[i] + a[day] * x - 2 * c == dp[day]){
                pre[day] = -x;
                pre[i] = x;
                return trace(i - 1);
            }
            pre[i] = 0;
        }
    }

    void process(){
        init();
        for(int i = 2; i <= n; i ++){
            dp[i] = query(1, a[i]);
            if(dp[i] < dp[i - 1]) dp[i] = dp[i - 1];
            ll x = (dp[i] - c) / a[i];
            maximize(x, 0ll);
            line tmp = {x, dp[i] - x * a[i] - 2 * c};
            update(1, 0, maxn - 1, tmp);
        }
        cout << dp[n] << "\n";
        trace(n);
        for(int i = 1; i <= n; i ++) {
            cout << pre[i] << " ";
        }
        cout << "\n";
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
