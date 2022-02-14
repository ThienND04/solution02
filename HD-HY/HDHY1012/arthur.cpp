#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "arthur"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

namespace caculate
{
    template <class T>
    void add(T &x, T y)
    {
        x += y;
        if (x >= mod)
            x -= mod;
    }
    template <class T>
    void sub(T &x, T y)
    {
        x -= y;
        if (x < 0)
            x += mod;
    }
    template <class T>
    void maximize(T &x, T y)
    {
        if (x < y)
            x = y;
    }
    template <class T>
    void minimize(T &x, T y)
    {
        if (x > y)
            x = y;
    }
}

using namespace caculate;

namespace process
{
    int q, n, m, w1, w2, w3;
    int c[maxn], d[maxn];
    pii a[maxn];

    // a <= b
    bool cmp1(const pii& p1, const pii& p2){
        return p1.first <= p2.first;
    }

    // a > b
    bool cmp2(const pii& p1, const pii& p2){
        return p1.second >= p2.second;
    }

    int johnson(int _ta = 0, int _tb = 0){
        // if(m == 0) return 0;
        int ta = _ta, tb = _tb;
        for(int i = 1; i <= m; i ++){
            ta += a[i].first;
            tb += a[i].second;
            maximize(tb, ta + a[i].second);
        }
        return tb;
    }

    void subtask2(){
        int cnt = 0;
        m = 0;
        for(int i = 1; i <= n; i ++){
            if(c[i] <= d[i]) a[++ cnt] = {c[i], d[i]};
        }
        m = cnt;
        sort(a + 1, a + cnt + 1, cmp1);
        for(int i = 1; i <= n; i ++){
           if(c[i] > d[i]) a[++ m] = {c[i], d[i]};
        }
        if(m - cnt > 1) sort(a + cnt + 2, a + m + 1, cmp2);
        double res = 1.0 * johnson() / 2;
        cout << res << "\n";
    }

    double calc(double S, int tb, int te){
        double res = 0;
        maximize(res, w1 * (S - tb));
        maximize(res, w2 * (te - S));
        maximize(res, w3 * S);
        return res;
    }

    void subtask3(){
        double minP = 1e18;
        for(int i = 1; i <= n; i ++){
            int cnt = 0;
            m = 0;
            for(int j = 1; j <= n; j ++){
                if(i == j) continue;
                if(c[j] <= d[j]) a[++ cnt] = {c[j], d[j]};
            }
            m = cnt;
            sort(a + 1, a + cnt + 1, cmp1);
            for(int j = 1; j <= n; j ++){
                if(j == i) continue;
                if(c[j] > d[j]) a[++ m] = {c[j], d[j]};
            }
            if(m - cnt > 1) sort(a + cnt + 2, a + m + 1, cmp2);

            int tb = c[i] + d[i];
            int te = johnson(c[i], c[i] + d[i]);
            double S = 1.0 * (tb + te) / 2;
            double P = calc(S, tb, te);
            minimize(minP, P);
        }
        cout << minP << "\n";
    }

    void solve(){
        cin >> n >> w1 >> w2 >> w3;
        for(int i = 1; i <= n; i ++) cin >> c[i] >> d[i];
        if(w1 == 0 && w2 == 1 && w3 == 1) return subtask2();
        if(w1 == 1 && w2 == 1 && w3 == 0) return subtask3();
    }

    void process()
    {
        cout << fixed << setprecision(1);
        cin >> q;
        while(q --){
            solve();
        }
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
