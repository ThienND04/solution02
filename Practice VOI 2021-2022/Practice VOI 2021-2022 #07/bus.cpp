#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bus"
#define inf 1e9
#define mod 1000000007
#define maxn 301

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
    int w, h, xs, ys, xt, yt, n;
    int firstTime[maxn][maxn][maxn], f[maxn][maxn][maxn], t[maxn];
    int x1[maxn], y1[maxn], x2[maxn], y2[maxn];
    vector<int> adjBus[maxn][maxn];

    void init(){
        cin >> w >> h >> xs >> ys >> xt >> yt;
        cin >> n;
        x1[0] = y1[0] = x2[0] = y2[0] = 0;

        for(int idBus = 1; idBus <= n; idBus ++){
            int T;
            cin >> x1[idBus] >> y1[idBus] >> x2[idBus] >> y2[idBus] >> T;
            t[idBus] = 2 * (x2[idBus] - x1[idBus] + y2[idBus] - y1[idBus]);
            for(int i = 1; i <= w; i ++){
                for(int j = 1; j <= h; j ++){
                    firstTime[idBus][i][j] = -1;
                    f[idBus][i][j] = inf;
                }
            }
            int time = t[idBus] - T;
            for(int j = y1[idBus]; j < y2[idBus]; j ++){
                time %= t[idBus];
                firstTime[idBus][x1[idBus]][j] = time;
                time ++;
                adjBus[x1[idBus]][j].push_back(idBus);
            }
            for(int i = x1[idBus]; i < x2[idBus]; i ++){
                time %= t[idBus];
                firstTime[idBus][i][y2[idBus]] = time;
                time ++;
                adjBus[i][y2[idBus]].push_back(idBus);
            }
            for(int j = y2[idBus]; j > y1[idBus]; j --){
                time %= t[idBus];
                firstTime[idBus][x2[idBus]][j] = time;
                time ++;
                adjBus[x2[idBus]][j].push_back(idBus);
            }
            for(int i = x2[idBus]; i > x1[idBus]; i --){
                time %= t[idBus];
                firstTime[idBus][i][y1[idBus]] = time;
                time ++;
                adjBus[i][y1[idBus]].push_back(idBus);
            }
        }
    }

    priority_queue<vector<int>> q;

    void IJK(){
        f[0][xs][ys] = 0;
        q.push({0, xs, ys, 0});
        // time, x, y, idBus
        vector<int> tt;
        while(! q.empty()){
            tt = q.top();
            q.pop();
            int l = tt[0], x = tt[1], y = tt[2], id = tt[3];
            if(f[id][x][y] != l) continue;
            // doi xe bus 
            for(int v: adjBus[x][y]){
                int t2 = max(0, (l - firstTime[v][x][y]) / t[v]) * t[v] + firstTime[v][x][y];
                // cerr << t2 << "\n";
                if(t2 < f[v][x][y]) {
                    f[v][x][y] = t2;
                    q.push({- f[v][x][y], x, y, v});
                }
            }
            if(x == x1[id] && y < y2[id]) {
                if(f[id][x][y + 1] > l + 1){
                    f[id][x][y + 1] = l + 1;
                    q.push({- [id][x][y + 1], x, y + 1, id});
                }
            }
            if(x == x2[id] && y > y1[id]){
                if(f[id][x][y - 1] > l + 1){
                    f[id][x][y + 1] = l + 1;
                    q.push({- [id][x][y - 1], x, y - 1, id});
                }
            }
            if(y == y2[id] && x > x1[id]){
                if(f[id][x - 1][y] > l + 1){
                    f[id][x - 1][y] = l + 1;
                    q.push({- [id][x - 1][y], x - 1, y, id});
                }
            }
            if(y == y1[id] && x < x1[id]){
                if(f[id][x + 1][y] > l + 1){
                    f[id][x + 1][y] = l + 1;
                    q.push({- [id][x + 1][y], x + 1, y, id});
                }
            }
        }
    }

    void process(){
        init();
        IJK();
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
