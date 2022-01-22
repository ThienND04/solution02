#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "pence"
#define inf 2000000007
#define mod 2000000007
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
    int color[maxn];
    vector<pii> adj[maxn];
    priority_queue<pair<int, pii>> pq;

    void init(){
        string tmp;
        cin >> n >> m >> k;
        cin >> tmp;
        tmp = " " + tmp;
        for(int i = 1; i <= n; i ++) color[i] = (tmp[i] == 'L');
        while(m --){
            int u, v, d;
            cin >> u >> v >> d;
            if(color[u] == color[v]) pq.push({- d, {u, v}});
            adj[u].push_back({d, v});
            adj[v].push_back({d, u});
        }
    }

    void process(){
        init();
        pair<int, pii> res = {-inf, {0, 0}}, bright = {- inf, {0, 0}};
        for(int i = 1; i <= n; i ++){
            if(adj[i].size() <= 1) continue;
            sort(adj[i].begin(), adj[i].end());
            maximize(bright, {-adj[i][0].first - adj[i][1].first, {adj[i][0].second, adj[i][1].second}});
        }
        pq.push(bright);
        res = pq.top();
        cout << - res.first << "\n";
        while(k --){
            int u;
            cin >> u;
            color[u] = 1 - color[u];
            for(pii e: adj[u]){
                int v = e.second, d = e.first;
                if(color[u] == color[v]){
                    pq.push({-d, {u, v}});
                }
            }
            while(! pq.empty() && color[pq.top().second.first] != color[pq.top().second.second]) pq.pop();
            if(pq.empty()) res = bright;
            else res = pq.top();
            cout << - res.first << "\n";
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
