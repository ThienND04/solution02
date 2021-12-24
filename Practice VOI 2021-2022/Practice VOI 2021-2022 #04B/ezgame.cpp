#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "ezgame"
#define inf 1e9
#define mod 1000000007
#define maxn 5001

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
    int n, m, w, b;
    vector<int> adj[maxn], radj[maxn];
    bool win[maxn][maxn], visited[maxn][maxn];
    int numTurn[maxn][maxn];
    // int tmp = 0;

    void DFS(int u, int v){
        // tmp ++;
        visited[u][v] = 1;
        for(int l: adj[u]){
            if(! visited[l][v]) DFS(l, v);
            if(! win[l][v]) win[u][v] = 1;
        }
        for(int l: radj[v]){
            if(! visited[u][l]) DFS(u, l);
            if(! win[u][l]) win[u][v] = 1;
        }
        if(win[u][v]){
            numTurn[u][v] = inf;
            for(int l: adj[u]){
                if(! win[l][v]) minimize(numTurn[u][v], numTurn[l][v] + 1);
            }
            for(int l: radj[v]){
                if(! win[u][l]) minimize(numTurn[u][v], numTurn[u][l] + 1);
            }
        }
        else {
            for(int l: adj[u]){
                maximize(numTurn[u][v], numTurn[l][v] + 1);
            }
            for(int l: radj[v]){
                maximize(numTurn[u][v], numTurn[u][l] + 1);
            }
        }
    }

    void process(){
        cin >> n >> m >> w >> b;
        reset(visited);
        reset(win);
        reset(numTurn);
        while(m --){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            radj[v].push_back(u);
        }
        DFS(w, b);
        // cerr << tmp;
        cout << numTurn[w][b];
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
