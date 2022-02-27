 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "cake4"
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
    int n;
    vector<int> ke[maxn], adj[maxn];
    int par[maxn], f[2][maxn];

    void cut(vector<int>& vt, int pos){
        if(pos == -1) return;
        reverse(vt.begin(), vt.begin() + pos);
        reverse(vt.begin() + pos + 1, vt.end());
        reverse(vt.begin(), vt.end());
    }

    void DFS(int u){
        int pos = -1;
        bool ok = 0;
        for(int v: adj[u]){
            if(par[v]) continue;
            par[v] = u;
            DFS(v);
            f[0][u] += f[1][v];
            if(f[0][v] + 1 <= f[1][v]){
                ok = 1;
                f[1][u] += f[0][v] + 1;
            }
            else{
                f[1][u] += f[1][v];
            }
        }
        if(! ok) f[1][u] ++;
    }

    map<pii, int> id, edge;
    

    void init(){
        reset(par); reset(f);
        cin >> n;
        for(int i = 1; i <= n - 3; i ++){
            int u, v;
            cin >> u >> v;
            if(u > v) swap(u, v);
            edge[{u, v}] = 1;
            ke[u].push_back(v);
            ke[v].push_back(u);
        }
        for(int i = 1; i < n; i ++) edge[{i, i + 1}] = 1;
        for(int i = 1; i <= n; i ++){
            if(i == 1) ke[i].push_back(n);
            else ke[i].push_back(i - 1);
            if(i == n) ke[i].push_back(1);
            else ke[i].push_back(i + 1);
        }
        for(int i = 1; i <= n; i ++) sort(ke[i].begin(), ke[i].end());
    }

    void initGraph(){
        int num = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j < ke[i].size() - 1; j ++){
                int u = ke[i][j], v = ke[i][j + 1];
                if(! edge[{u, v}] || u <= i) continue;
                ++ num;
                int c1 = id[{i, u}], c2 = id[{i, v}], c3 = id[{u, v}];
                if(c1){
                    adj[c1].push_back(num);
                    adj[num].push_back(c1);
                }
                if(c2){
                    adj[c2].push_back(num);
                    adj[num].push_back(c2);
                }
                if(c3){
                    adj[c3].push_back(num);
                    adj[num].push_back(c3);
                }
                id[{i, u}] = num;
                id[{i, v}] = num;
                id[{u, v}] = num;
            }
        }
    }

    void process(){
        init();
        initGraph();
        
        par[1] = -1;
        DFS(1);
        cout << f[1][1];
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
