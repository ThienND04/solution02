#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "delayfood"
#define inf 1e9
#define mod 1000000007
#define maxn 1001

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

struct Data{
    int u, t, c;
};

int n, m, p, k;
vector<pii> adj[maxn];
Data don[maxn];
ll dist[maxn][maxn];

namespace impossible{
    bool check(){
        for(int i = 1; i <= k; i ++){
            if(dist[1][don[i].u] == -1) return 1;
        }
        return 0;
    }
}

namespace subtask1{
    ll maxTime[11][11];
    ll t[11];

    ll res = 1e18;

    void Try(int pos, ll curTime){
        if(pos > k){
            ll tmp = 0;
            for(int i = 1; i <= k; i ++){
                maximize(tmp, t[i] - don[i].t);
            }
            minimize(res, tmp);
            return;
        }
        if(pos != -1) curTime += dist[don[pos - 1].u][1];
        for(int j = pos; j <= min(k, pos + p - 1); j ++){
            ll s = max(curTime, maxTime[pos][j]);
            for(int i = pos; i <= j; i ++){
                if(i == pos) s += dist[1][don[i].u];
                else s += dist[don[i - 1].u][don[i].u];
                t[i] = s;
            }
            Try(j + 1, t[j]);
        }
    }

    void subtask1(){
        reset(maxTime);
        for(int i = 1; i <= k;  i++){
            int cur = 0;
            for(int j = i; j <= k;j ++){
                maximize(cur, don[i].t + don[i].c);
                maxTime[i][j] = cur;
            }
        }
        Try(1, 0);
        cout << res;
    }
}

namespace subtask2{
    int maxTime[101][101];
    ll dp[101];

    bool ok(ll x){
        memset(dp, 99, sizeof(dp));
        dp[0] = 0;

        for(int i = 1; i <= k; i ++){
            for(int j = i; j <= min(k, i + p - 1); j ++){
                ll tmp = dp[i - 1];
                if(i != 1) tmp += dist[don[i - 1].u][1];
                maximize(tmp, 1ll * maxTime[i][j]);

                bool okok = 1;

                for(int t = i; t <= j; t ++){
                    if(t == i) tmp += dist[1][don[t].u];
                    else tmp += dist[don[t - 1].u][don[t].u];

                    if(tmp - don[t].t > x) {
                        okok = 0;
                        break;
                    }
                }
                if(! okok) continue;
                minimize(dp[j], tmp);
            }
        }
        return (dp[k] <= 1e18);
    }

    void subtask2(){
        reset(maxTime);

        for(int i = 1; i <= k;  i++){
            int cur = 0;
            for(int j = i; j <= k;j ++){
                maximize(cur, don[i].t + don[i].c);
                maxTime[i][j] = cur;
            }
        }
        ll l = -1, r = 1e18;
        while(r - l > 1){
            ll mid = (l + r) / 2;
            if(ok(mid)) r = mid;
            else l = mid;
        }
        cout << r;
    }
}

namespace process{
    void IJK(int s){
        priority_queue<pair<ll, int>> pq;
        memset(dist[s], -1, sizeof(dist[s]));
        dist[s][s] = 0;
        pq.push({0, s});
        while(! pq.empty()){
            int u = pq.top().second;
            ll l = - pq.top().first;
            pq.pop();
            if(dist[s][u] != l) continue;
            for(pii e: adj[u]){
                int v = e.first, w = e.second;
                if(dist[s][v] == -1 || dist[s][v] > l + w){
                    dist[s][v] = l + w;
                    pq.push({- dist[s][v], v});
                }
            }
        }
    }

    void init(){
        for(int i = 1; i <= n; i ++) IJK(i);
    }

    void process(){
        cin >> n >> m >> p >> k;
        while(m --){
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        init();
//        for(int i = 1; i <= n; i ++){
//            for(int j = 1; j <= n; j ++) cerr << i << " " << j << " : " << dist[i][j] << "\n";
//        }
        for(int i = 1; i<= k; i ++) cin >> don[i].u >> don[i].t >> don[i].c;
        sort(don + 1, don + k + 1, [](Data& dt1, Data& dt2){return dt1.t < dt2.t; });
        //for(int i = 1; i <= k; i ++) cerr << don[i].u << " " << don[i].t << " " << don[i].c << "\n";
        if(impossible::check()) {
            cout << -1;
            return;
        }
        //if(k <= 10) return subtask1::subtask1();
        if(k <= 100) return subtask2::subtask2();
        assert(0);
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