#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "oilrig"
#define inf 1e9
#define mod 1000000007
#define maxn 3001

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

int n;
int a[maxn], b[maxn], c[maxn];
vector<int> adj[maxn];

namespace subtask1{
    vector<int> child[maxn];

    void Prepare(int u, int par){
        for(int v: adj[u]){
            if(v == par) continue;
            child[u].push_back(v);
            Prepare(v, u);
        }
    }

    int num = 0;
    int ls[maxn], in[maxn];
    ll f[2][maxn];
    int id[21];

    void DFS(int u){
        ls[++ num] = u;
        in[u] = num;

        for(int v: child[u]){
            DFS(v);
        }
        memset(id, -1, sizeof(id));
        int m = child[u].size();
        for(int i = 0; i < m; i ++){
            int v = child[u][i];
            id[v] = i;
        }
        for(int x = 0; x < (1 << m); x ++){
            priority_queue<int> pq;
            ll s1 = 0;
            ll s2 = 0;
            ll tmp = 0;

            for(int i = in[u]; i <= num; i ++){
                int v = ls[i];
                if(id[v] == -1){
                    pq.push(a[v]);
                }
                else if(! bit(x, id[v])){
                    pq.push(a[i]);
                }
                else{
                    s2 += c[i];
                    tmp += b[i] + 1;
                }
            }
            if(tmp <= num - in[u] + 1){
                for(int i = 1; i <= num - in[u] + 1 - tmp; i ++){
                    s1 += pq.top();
                    pq.pop();
                }
            }
            if(tmp <= num - in[u]) maximize(f[1][u], s1 + s2);
        }
        f[0][u] = 0;
        for(int i = 0; i < m; i ++){
            int v = child[u][i];
            f[0][u] += f[0][v];
        }

        for(int x = 1; x < (1 << m); x ++){
            ll s = 0;
            for(int v: child[u]){
                if(bit(x, id[v])) s += f[1][v];
                else s += f[0][v];
            }
            maximize(f[1][u], s);
        }

    }

    void subtask1(){
        reset(f);
        Prepare(1, -1);
        DFS(1);
        cout << f[1][1];
    }
}

namespace process{
    void process(){
        cin >> n;
        for(int i = 1;  i <= n; i ++) cin >> a[i] >> b[i] >> c[i];
        for(int i  = 1; i < n; i ++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(n <= 20) return subtask1::subtask1();
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
