#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "stravel"
#define inf 1e9
#define mod 1000000007
#define maxn 3001

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

int n;
string s;
vector<int> adj[maxn];

namespace subtask1{
    int res[maxn];
    bool visited[maxn];

    bool ok(){
        for(int i = 1; i <= n; i ++){
            if(visited[i] == 0) return 0;
        }
        return 1;
    }

    void DFS(int u){
        visited[u] = 1;
        if(ok()){
            res[u] ++;
        }
        for(int v: adj[u]){
            if(! visited[v]) DFS(v);
        }
        visited[u] = 0;
    }

    void subtask1(){
        reset(res); reset(visited);
        for(int i = 1; i <= n; i ++){
            DFS(i);
        }
        for(int i = 1; i <= n; i ++) cout << res[i] << " ";
    }
}

namespace subtask2{
    int f[1 << 21][21];

    void subtask2(){
        reset(f);
        for(int i = 1; i <= n; i ++){
            f[1 << i - 1][i] = 1;
        }
        for(int x = 1; x < (1 << n); x ++){
            for(int u = 1; u <= n; u ++){
                if(! bit(x, u - 1)) continue;
                for(int v : adj[u]){
                    if(bit(x, v - 1)) continue;
                    add(f[x | (1 << v - 1)][v], f[x][u]);
                }
            }
        }
        for(int i = 1; i <= n; i ++) cout << f[(1 << n) - 1][i] << " ";
    }
}

namespace process{
    void process(){
        cin >> n >> s;  
        s = " " + s;
        for(int i = 1; i <= n; i ++){
            if(s[i] == '>'){
                for(int j = i + 1; j <= n; j ++) adj[i].push_back(j);
            }
            else{
                for(int j = 1; j < i; j ++) adj[i].push_back(j);
            }
        }
        if(n <= 10) return subtask1::subtask1();
        if(n <= 20) return subtask2::subtask2();
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
