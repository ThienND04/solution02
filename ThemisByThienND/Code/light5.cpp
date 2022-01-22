 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "light5"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26
#define SQRT 333

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
    vector<int> adj[maxn], adj2[maxn];
    unordered_map<int, bool>color[maxn];
    int cntSwap[maxn], numBlue[maxn], numRed[maxn];

    void process(){
        reset(cntSwap);
        reset(numBlue);
        reset(numRed);
        cin >> n >> m >> q;
        int cnt = 0;

        while(m --){
            int u, v, c;
            cin >> u >> v >> c;
            color[u][v] = color[v][u] = c;
            adj[u].push_back(v);
            adj[v].push_back(u);

            if(c) {
                numBlue[u] ++;
                numBlue[v] ++;
            }
            else{
                numRed[u] ++;
                numRed[v] ++;
            }

            if(c) cnt ++;
        }

        for(int u = 1; u <= n; u ++){
            if(adj[u].size() >= SQRT){
                for(int v: adj[u]){
                    if(adj[v].size() >= SQRT){
                        adj2[u].push_back(v);
                    }
                }
            }
        }

        while(q --){
            int u;
            cin >> u;

            if(adj[u].size() >= SQRT){
                cntSwap[u] ++;
                swap(numBlue[u], numRed[u]);
                cnt += numBlue[u] - numRed[u];

                for(int v: adj2[u]){
                    color[u][v] = !color[u][v];
                    color[v][u] = !color[v][u];
                    if(color[u][v]){
                        numBlue[u] ++;
                        numRed[u] --;
                        numBlue[v] ++;
                        numRed[v] --;

                        cnt ++;
                    }
                    else{
                        cnt --;

                        numBlue[u] --;
                        numRed[u] ++;
                        numBlue[v] --;
                        numRed[v] ++;
                    }
                }
            }
            else{
                for(int v: adj[u]){
                    color[u][v] = !color[u][v];
                    color[v][u] = !color[v][u];

                    if(adj[v].size() >= SQRT){
                        if(cntSwap[v] & 1){
                            if(color[v][u] == 1) {
                                cnt --;
                                numBlue[v] --;
                                numRed[v] ++;
                            }
                            else {
                                cnt ++;
                                numBlue[v] ++;
                                numRed[v] --;
                            }
                        }
                        else{
                            if(color[v][u] == 1) {
                                cnt ++;
                                numBlue[v] ++;
                                numRed[v] --;
                            }
                            else {
                                cnt --;
                                numBlue[v] --;
                                numRed[v] ++;
                            }
                        }
                    }
                    else{
                        if(color[u][v] == 1) cnt ++;
                        else cnt --;
                    }
                }
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
