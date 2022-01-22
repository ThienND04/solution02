#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "nxcmct"
#define inf 1e9
#define mod 1000000007
#define maxn 111

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

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
    int m, n;
    bool vst[maxn][maxn];
    int idIn[maxn][maxn], idOut[maxn][maxn];

    #define IN(x, y) (((x) - 1) * n * 2 + (y) * 2 - 1)
    #define OUT(x, y) (((x) - 1) * n * 2 + (y) * 2)
    
    pii cell(int id){
        id ++;
        id /= 2;
        int y = id % n;
        int x = id / n + 1;
        if(y == 0){
            y = n;
            x --;
        }
        return {x, y};
    }
    
    int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
    char move[] = {'U', 'L', 'D', 'R'};
    int vx, vy, mx, my, px, py, tx, ty;

    vector<pii> adj[2 * maxn * maxn];
    vector<int> f[2 * maxn * maxn];

    void initGraph(){
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                int tmp = IN(i, j);
                adj[tmp].clear();
                f[tmp].clear();
                // if(tmp == 457){
                //     tmp ++;
                //     tmp --;
                // }
                for(int _ = 0; _ < 4; _ ++){
                    int x2 = i + dx[_], y2 = j + dy[_];
                    if(x2 < 1 || x2 > m || y2 < 1 || y2 > n){
                        adj[tmp].push_back({0, 0});
                        f[tmp].push_back(0);
                    }
                    else{
                        adj[tmp].push_back({OUT(x2, y2), 0});
                        f[tmp].push_back(0);
                    }
                }
                adj[tmp].push_back({tmp + 1, 1});
                f[tmp].push_back(0);
            }
        }
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                int tmp = OUT(i, j);
                adj[tmp].clear();
                f[tmp].clear();
                for(int _ = 0; _ < 4; _ ++){
                    int x2 = i + dx[_], y2 = j + dy[_];
                    if(x2 < 1 || x2 > m || y2 < 1 || y2 > n){
                        adj[tmp].push_back({0, 0});
                        f[tmp].push_back(0);
                    }
                    else{
                        adj[tmp].push_back({IN(x2, y2), inf});
                        f[tmp].push_back(0);
                    }
                }
                adj[tmp].push_back({tmp - 1, 0});
                f[tmp].push_back(0);
            }
        }
        adj[IN(px, py)][4].second = 2;
        adj[IN(vx, vy)][4].second = 0;
    }

    int pre[2 * maxn * maxn];

    bool findPath(){
        memset(pre, -1, sizeof(pre));
        queue<int> q;
        q.push(IN(px, py));
        pre[IN(px, py)] = 0;
        while(! q.empty()){
            int u = q.front();
            q.pop();
            for(int i = 0; i < adj[u].size(); i ++){
                int v = adj[u][i].first;
                pii pos = cell(v);
                if(pos.first < 1 || pos.first > m || pos.second < 1 || pos.second > n) continue;
                if(pre[v] != -1) continue;
                if(adj[u][i].second - f[u][i] > 0){
                    pre[v] = u;
                    q.push(v);
                }
            }
        }
        return (pre[OUT(mx, my)] != -1 || pre[OUT(tx, ty)] != -1);
    }

    void increFlow(int& maxFlow){
        int t = OUT(mx, my), s = IN(px, py);
        if(pre[t] == -1) t = OUT(tx, ty);
        int v = t, d = inf;
        while(v != s){
            int u = pre[v];
            for(int i = 0; i < adj[u].size(); i ++){
                if(adj[u][i].first == v){
                    minimize(d, adj[u][i].second - f[u][i]);
                }
            }
            v = u;
        }
        maxFlow += d;
        v = t;
        while(v != s){
            int u = pre[v];
            if(adj[u][4].first == v){
                f[u][4] += d;
                f[v][4] -= d;
            }
            else for(int i = 0; i < 4; i ++){
                if(adj[u][i].first == v){
                    f[u][i] += d;
                    f[v][(i + 2) % 4] -= d;
                }
            }
            v = u;
        }
    }

    int check(string res){
        int x = mx, y = my;
        for(char c: res){
            if(c == 'U'){
                x ++;
            }
            else if(c == 'D') x --;
            else if(c == 'L') y --;
            else if(c == 'R') y ++;
            if(x == vx && y == vy) return -2;
            if(x < 1 || x > m || y < 1 || y > n) return 0;
        }
        if(x != tx || y != ty) return -1;
        return 1;
    }

    void trace(){
        int t = OUT(mx, my), s = IN(px, py);
        string tmp0 = "";
        while(t != s){
            // cerr << cell(t).first << " " << cell(t).second << "\n";
            // if(cell(t).first == 4 && cell(t).second == 1) {
            //     t += 1;
            //     t -= 1;
            // }
            if(t % 2 == 0) t --;
            else for(int i = 0; i < 4; i ++){
                if(f[t][i] == -1){
                    tmp0 += move[i];
                    t = adj[t][i].first;
                    break;
                }
            }
        }
        // sai
        // cerr << check(tmp0) << "\n";
        string tmp = "";
        t = OUT(tx, ty);
        while(t != s){
            if(t % 2 == 0) t --;
            else for(int i = 0; i < 4; i ++){
                if(f[t][i] == -1){
                    tmp += move[(i + 2) % 4];
                    t = adj[t][i].first;
                    break;
                }
            }
        }
        reverse(tmp.begin(), tmp.end());
        cout << tmp0 << tmp << "\n";
        // cerr << check(tmp0 + tmp) << "\n";
    }

    void process()
    {
        //debug

        // n = 4, m = 3;
        // for(int i = 1; i <= m; i ++){
        //     for(int j = 1; j <= n; j ++) cerr << IN(i, j) << " ";
        //     cerr << "\n";
        // }
        // cerr << "-----------\n";
        // for(int i = 1; i <= m; i ++){
        //     for(int j = 1; j <= n; j ++) cerr << OUT(i, j) << " ";
        //     cerr << "\n";
        // }

        // for(int i = 1; i <= 2 * n * m; i ++){
        //     pii p = cell(i);
        //     cerr << p.first << " " << p.second << "\n";
        // }

        while(cin >> m >> n){
            if(m < 1 && n < 1) break;
            cin >> mx >> my >> px >> py >> tx >> ty >> vx >> vy;
            initGraph();
            int maxFlow = 0;
            while(findPath()){
                increFlow(maxFlow);
            }
            if(maxFlow != 2) {
                cout << "no\n";
                continue;
            }
            trace();
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
