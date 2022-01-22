 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "meetingpoint"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

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

namespace process{
    int n, m, k;
    vector<pii> adj[maxn];
    ll p[maxn], q[maxn];

    bool cmp(const pll& a, const pll& b){
        return a.first * b.second > b.first * a.second;
    }

    void IJK(int _s, ll _dist[]){
        for(int i = 1; i <= n; i ++) _dist[i] = 1e18;
        priority_queue<pair<ll, int> > pq;
        _dist[_s] = 0;
        pq.push({0, _s});
        while(! pq.empty()){
            ll l = - pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if(_dist[u] != l) continue;
            for(pii e: adj[u]){
                int v = e.first, w = e.second;
                if(_dist[v] > l + w){
                    _dist[v] = l + w;
                    pq.push({- _dist[v], v});
                }
            }
        }
    }

    vector<pair<double, int>> vt;
    vector<double> ps;
    vector<int> id;
    ll mn[2][maxn];

    void process(){
        cin >> n >> m >> k;
        while(m --){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        IJK(1, p);
        IJK(n, q);
        for(int i = 2; i < n; i ++){
            vt.push_back({1.0 * p[i] / q[i], i});
        }
        sort(vt.begin(), vt.end());
        for(auto p: vt){
            ps.push_back(p.first);
            id.push_back(p.second);
        }

        if(n > 2){
            mn[0][0] = q[id[0]];
            for(int i = 1; i <= n - 3; i ++){
                mn[0][i] = min(mn[0][i - 1], q[id[i]]);
            }
            mn[1][n - 3] = p[id[n - 3]];
            for(int i = n - 4; i >= 0; i --){
                mn[1][i] = min(mn[1][i + 1], p[id[i]]);
            }
        }

        while(k --){
            int x, y;
            cin >> x >> y;
            double tmp = 1.0 * y / x;
            ll res = 1e18;
            int k = lower_bound(ps.begin(), ps.end(), tmp) - ps.begin(); 
            if(k != n - 2) minimize(res, mn[1][k] * x);
            k = upper_bound(ps.begin(), ps.end(), tmp) - ps.begin() - 1;
            if(k >= 0) minimize(res, mn[0][k] * y);
            res = min(res, max(p[1] * x, q[1] * y));
            res = min(res, max(p[n] * x, q[n] * y));
            cout << res << "\n";
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
