#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "xtreew"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 32
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
    int n;
    vector<pii> adj[maxn];
    int s[maxn];

    void DFS(int u, int par){
        for(pii& e: adj[u]){
            int v = e.first, c = e.second;
            if(v == par) continue;
            s[v] = s[u] ^ c;
            DFS(v, u);
        }
    }

    void process(){
        cin >> n;
        reset(s);
        for(int i = 1; i < n; i ++){
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }
        DFS(1, -1);
        ll res = 0;
        for(int t = 0; t < LOG; t ++){
            int cnt = 0;
            for(int i = 1; i <= n; i ++){
                if(bit(s[i], t)) {
                    res += 1ll * (1 << t) * (i - cnt - 1);
                    cnt ++;
                }
                else{
                    res += 1ll * (1 << t) * cnt;
                }
            }
        }
        cout << res;
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
