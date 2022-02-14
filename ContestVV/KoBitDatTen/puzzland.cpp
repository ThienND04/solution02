#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "puzzland"
#define inf 1e9
#define mod 1000000007
#define maxn 26

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

int t, n, m, id[200];
char c[maxn];
bool f[maxn][1 << 20];
vector<int> adj[maxn];

bool cmp(int a, int b){
    return (c[a] < c[b]);
}

string calc(){
    reset(f);
    f[n - 1][1 << (n - 1)] = 1;

    for(int x = 1 << (n - 1); x < (1 << n); x ++){
        for(int i = 0; i < n; i ++){
            if(! f[i][x]) continue;
            for(int j: adj[i]){
                if(bit(x, j)) continue;
                
                f[j][x | (1 << j)] = 1;
            }
        }
    }

    if(! f[0][(1 << n) - 1]) return "IMPOSSIBLE";
    string res = "";
    res += c[0];

    int curNode = 0;
    int curX = (1 << n) - 1;

    for(int i = 0; i < n - 1; i ++){
        for(int j: adj[curNode]){
            if(! bit(curX, j)) continue;
            if(f[j][curX ^ (1 << curNode)]){
                curX ^= (1 << curNode);
                curNode = j;
                res += c[j];
                break;
            }
        }
    }
    return res;
}

namespace process{
    void process(){
        cin >> t;
        while(t --){
            for(int i = 0; i < ALPHABET; i ++) adj[i].clear();

            cin >> n >> m;
            for(int i = 0; i < n; i ++){
                cin >> c[i];
                id[c[i]] = i;
            }
            while(m --){
                char u, v;
                cin >> u >> v;
                adj[id[u]].push_back(id[v]);
                adj[id[v]].push_back(id[u]);
            }

            for(int i = 0; i < n; i ++) {
                sort(adj[i].begin(), adj[i].end(), cmp);
            }
            
            cout << calc() << "\n";
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
