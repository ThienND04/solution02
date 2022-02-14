#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "cycletour"
#define inf 1e9
#define mod 1000000007
#define maxn 200001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
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
    int v, d, id;
};

int n, m;
vector<Data> adj[maxn];

namespace subtask1{
    bool visited[21];
    bool ok[1 << 21];

    void DFS(int start, int u, int mask, int cnt){
        if(visited[start] == 1 && u == start){
            if(cnt == 2) ok[mask] = 1;
            return;
        }
        for(Data e: adj[u]){
            int v = e.v, d = e.d, id = e.id;
            if(visited[v]) continue;
            visited[v] = 1;
            if((mask & (1 << (id - 1))) > 0) {
                visited[v] = 0;
                continue;
            }
            DFS(start, v, mask | (1 << (id - 1)), cnt + d);
            visited[v] = 0;
        }
    }

    void subtask1(){
        reset(ok);
        for(int i = 1; i <= n; i ++){
            reset(visited);
            DFS(i, i, 0, 0);
        }
        int res = 0;
        for(int i = 1; i < (1 << m);  i++) {
            //if(ok[i]) cerr << i << " " << ok[i] << "\n";
            if(ok[i]) res ++;
        }
        cout << res;
    }
}

namespace process{
    void process(){
        cin >> n >> m;
        for(int i = 1; i < n; i ++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v, 0, i});
            adj[v].push_back({u, 0, i});
        }
        for(int i = 1; i <= m - n + 1; i ++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back({v, 1, i + n - 1});
            adj[v].push_back({u, 1, i + n - 1});
        }
        if(n <= 20 && m <= 20) return subtask1::subtask1();
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
