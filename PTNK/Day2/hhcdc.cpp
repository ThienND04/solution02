 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "hhcdc"
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

namespace process{
    int n, m;
    pii w[maxn][maxn];
    vector<int> adj[maxn];
    int c[maxn][maxn], pre[maxn];
    ll res = 0;
    bool Get[10001];

    bool findPath(){
        reset(pre);
        queue<int> q;
        pre[1] = -1;
        q.push(1);
        while(! q.empty()){
            int u = q.front();
            q.pop();
            for(int v: adj[u]){
                if(pre[v] == 0 && c[u][v] < w[u][v].first){
                    pre[v] = u;
                    q.push(v);
                }
            }
        }
        return (pre[n] != 0);
    }

    void increFlow(){
        int d = inf;
        int t = n;
        while(t != 1){
            minimize(d, w[pre[t]][t].first - c[pre[t]][t]);
            t = pre[t];
        }
        t = n;
        res += d;
        bool ok = 0;
        while(t != 1){
            c[pre[t]][t] += d;
            c[t][pre[t]] -= d;
            t = pre[t];
        }
    }

    void Trace(){
        reset(pre);
        queue<int> q;
        pre[1] = -1;
        q.push(1);
        while(! q.empty()){
            int u = q.front();
            q.pop();
            for(int v: adj[u]){
                if(pre[v] == 0 && c[u][v] < w[u][v].first){
                    pre[v] = u;
                    q.push(v);
                }
                else if(pre[v] == 0 && c[u][v] == w[u][v].first){
                    Get[w[u][v].second] = 1;
                }
            }
        }

        // pre[n] = -1;
        // q.push(n);
        // while(! q.empty()){
        //     int u = q.front();
        //     q.pop();
        //     for(int v: adj[u]){
        //         if(pre[v] == 0 && c[v][u] < w[v][u].first){
        //             pre[v] = u;
        //             q.push(v);
        //         }
        //         else if(pre[v] == 0 && c[v][u] == w[v][u].first){
        //             Get[w[v][u].second] = 1;
        //         }
        //     }
        // }
    }

    void process(){
        // code fail :((
        cin >> n >> m;
        reset(w);
        reset(c);
        reset(Get);
        // cerr << w[0][0].first << w[0][0].second;
        for(int i = 1; i <= m; i ++){
            int u, v;
            cin >> u >> v;
            cin >> w[u][v].first;
            w[u][v].second = i;
            w[v][u] = w[u][v];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        while(findPath()){
            increFlow();
        }
        cout << res << "\n";
        Trace();
        for(int i = 1; i <= m; i ++) if(Get[i]) cout << i << " ";
        // for(int i = 1; i <= n; i ++) {
        //     for(int j = 1; j <= n; j ++) cerr << c[i][j] << " ";
        //     cerr << "\n";
        // }
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
