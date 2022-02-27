#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "light5"
#define inf 1e9
#define mod 1000000007
#define maxn 5001

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
    int n, m, q;
    vector<int> adj[maxn];
    bool color[maxn][maxn];

    void process(){
        cin >> n >> m >> q;
        int cnt = 0;

        while(m --){
            int u, v, c;
            cin >> u >> v >> c;
            color[u][v] = color[v][u] = c;
            adj[u].push_back(v);
            adj[v].push_back(u);

            if(c) cnt ++;
        }
        while(q --){
            int u;
            cin >> u;
            for(int v: adj[u]){
                color[u][v] = ! color[u][v];
                color[v][u] = ! color[v][u];
                if(color[u][v]) cnt ++;
                else cnt --;
            }
            cout << cnt << " ";
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
