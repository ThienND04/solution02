#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "school"
#define inf 1e9
#define mod 1000000007
#define maxn 200200

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define SQRT 500
#define ALPHABET 26

#define IN_BL(x) ((x - 1) / SQRT + 1)

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
    int n, m, Q;
    int s[maxn], pos[maxn], res[maxn], blocks[SQRT];
    int dist[maxn]; // dist to n
    vector<int> adj[maxn];

    void IJK(){
        for(int i = 1; i <= n; i ++) dist[i] = inf;
        priority_queue<pii> q;
        q.push({0, n});
        dist[n] = 0;
        while(! q.empty()){
            int u = q.top().second, l = - q.top().first;
            q.pop();
            if(dist[u] != l) continue;
            for(int v: adj[u]){
                if(dist[v] > l + 1){
                    dist[v] = l + 1;
                    q.push({- dist[v], v});
                }
            }
        }
    }

    void recalc(int id){
        blocks[id] = inf;
        for(int i = (id - 1) * SQRT + 1; i <= id * SQRT && i <= n; i ++){
            minimize(blocks[id], pos[i] - 1 + dist[i]);
        }
    }

    int getMin(){
        return *min_element(blocks + 1, blocks + SQRT);
    }

    void process()
    {
        cin >> n >> m >> Q;
        while(m --){
            int u, v;
            cin >> u >> v;
            // adj[u].push_back(v);
            adj[v].push_back(u);
        }
        IJK();
        for(int i = 1; i <= n; i ++) {
            cin >> s[i];
            pos[s[i]] = i;
        }

        for(int i = 1; i < SQRT; i ++) blocks[i] = inf;
        for(int i = 1; i <= n; i ++){
            res[s[i]] = inf;
            minimize(res[s[i]], i - 1 + dist[s[i]]);
            minimize(blocks[IN_BL(s[i])], res[s[i]]);
        }

        while(Q --){
            int u, v;
            cin >> u >> v;
            swap(s[u], s[v]);
            swap(pos[s[u]], pos[s[v]]);
            recalc(IN_BL(s[u]));
            recalc(IN_BL(s[v]));
            cout << getMin() << "\n";
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
