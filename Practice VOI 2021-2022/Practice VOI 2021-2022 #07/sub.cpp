#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "sub"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26
#define SQRT 333

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

struct query
{
    int id, i, x, y, h;
    void nhap(){
        cin >> id;
        if(id == 1) cin >> i >> x >> y;
        else cin >> h;
    }
};

#define IN_BUCKET(x) (((x - 1) / SQRT) + 1)

namespace process{
    int n, q;
    int a[maxn], b[maxn];
    query qs[maxn];
    ll S, s[maxn];

    bool checkSub1(){
        for(int i = 1; i <= n; i ++){
            if(a[i] != 1) return 0;
        }
        for(int i = 1; i <= q; i ++){
            if(qs[i].id == 1 && qs[i].x != 1) return 0;
        }
        return 1;
    }

    void Trau(){
        for(int i = 1; i <= q; i ++){
            if(qs[i].id == 1){
                a[qs[i].i] = qs[i].x;
                b[qs[i].i] = qs[i].y;
            }
            else{
                ll s1 = 0, s2 = 0, minRes = 1e18;
                for(int j = qs[i].h; j >= 1; j --){
                    s1 += a[j];
                    s2 += b[j];
                    if(s1 >= S && s2 < minRes) minRes = s2;
                }
                if(minRes == 1e18) cout << -1 << "\n";
                else cout << minRes << "\n";
            }
        }
    }

    ll sMax[4 * maxn], lazy[4 * maxn];

    void build(int id, int l, int r){
        lazy[id] = 0;
        if(l == r){
            sMax[id] = s[l];
            return;
        }
        int mid = (l + r) / 2;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        sMax[id] = max(sMax[id * 2], sMax[id * 2 + 1]);
    }

    void lazyUpdate(int id){
        sMax[id * 2] += lazy[id];
        lazy[id * 2] += lazy[id];
        sMax[id * 2 + 1] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
        lazy[id] = 0;
    }

    ll getMax(int id, int l, int r, int u, int v){
        if(l > v || r < u) return -(1e18);
        int mid = (l + r) / 2;
        lazyUpdate(id);
        if(u <= l && r <= v) return sMax[id];
        ll s1 = getMax(id * 2, l, mid, u, v);
        ll s2 = getMax(id * 2 + 1, mid + 1, r, u, v);
        return max(s1, s2);
    }

    void update(int id, int l, int r, int u, int v, int d){
        if(l > v || r < u){
            return;
        }
        if(u <= l && r <= v){
            sMax[id] += d;
            lazy[id] += d;
            return;
        }
        int mid = (l + r) / 2;
        lazyUpdate(id);
        update(id * 2, l, mid, u, v, d);
        update(id * 2 + 1, mid + 1, r, u, v, d);
        sMax[id] = max(sMax[id * 2], sMax[id * 2 + 1]);
    }

    void subtask1(){
        build(1, 1, n);
        for(int i = 1; i <= q; i ++){
            if(qs[i].id == 1){
                update(1, 1, n, qs[i].i, n, qs[i].y - b[qs[i].i]);
                b[qs[i].i] = qs[i].y;
            }
            else{
                ll s1 = getMax(1, 1, n, qs[i].h, qs[i].h);
                ll s2 = max(getMax(1, 1, n, 1, max(qs[i].h - S, 1ll)), 0ll);
                // cerr << s1 << " " << s2 << "\n";
                cout << s1 - s2 << "\n";
            }
        }
    }

    void process(){
        cin >> n >> S;
        reset(s);
        for(int i = 1; i <= n; i ++) cin >> a[i];
        for(int i = 1; i <= n; i ++) {
            cin >> b[i];
            s[i] = s[i - 1] + b[i];
        }
        cin >> q;
        for(int i = 1; i <= q; i ++) qs[i].nhap();
        if(checkSub1()) return subtask1();
        return Trau();
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
