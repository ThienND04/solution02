#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "connect"
#define inf 1e9
#define mod 1000000007
#define maxn 501

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
    int a[maxn][maxn], val[maxn][maxn];
    int res = inf, d[maxn][maxn][2][2], dl[maxn][maxn], dr[maxn][maxn];
    queue<vector<int>> q[9001];
    
    const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

    void init(){
        string _s;
        cin >> m >> n;
        for(int i = 1; i <= m; i ++){
            cin >> _s;
            for(int j = 0; j < n; j ++) a[i][j + 1] = _s[j] - '0';
        }
    }

    void calc(){
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                d[i][j][0][0] = d[i][j][0][1] = inf;
                d[i][j][1][0] = d[i][j][1][1] = inf;
                dl[i][j] = dr[i][j] = inf;
            }
        }

        // for(int i = 0; i <= 9000; i ++){
        //     while(! q[i].empty()) q[i].pop();
        // }

        for(int i = 1; i <= m; i ++) {
            q[val[i][1]].push({i, 1});
            dl[i][1] = val[i][1];
        }

        int gh = min(res, (n + m) * 9 + 1);

        // calc left
        for(int s = 0; s < gh; s ++){
            vector<int> tt;
            while(! q[s].empty()){
                tt = q[s].front();
                q[s].pop();
                int x = tt[0], y = tt[1];
                if(dl[x][y] != s) continue;

                for(int i = 0; i < 4; i ++){
                    int x2 = x + dx[i], y2 = y + dy[i];
                    if(x2 >= 1 && x2 <= m && y2 >= 1 && y2 <= n){
                        if(s + val[x2][y2] < dl[x2][y2]){
                            dl[x2][y2] = s + val[x2][y2];
                            q[dl[x2][y2]].push({x2, y2});
                        }
                    }
                }
            }   
        }
        // calc right
        for(int i = 1; i <= m; i ++) {
            q[val[i][n]].push({i, n});
            dr[i][n] = val[i][n];
        }

        for(int s = 0; s < gh; s ++){
            vector<int> tt;
            while(! q[s].empty()){
                tt = q[s].front();
                q[s].pop();
                int x = tt[0], y = tt[1];
                if(dr[x][y] != s) continue;

                for(int i = 0; i < 4; i ++){
                    int x2 = x + dx[i], y2 = y + dy[i];
                    if(x2 >= 1 && x2 <= m && y2 >= 1 && y2 <= n){
                        if(s + val[x2][y2] < dr[x2][y2]){
                            dr[x2][y2] = s + val[x2][y2];
                            q[dr[x2][y2]].push({x2, y2});
                        }
                    }
                }
            }   
        }

        for(int j = 1; j <= n; j ++){
            d[1][j][0][0] = val[1][j];
            if(d[1][j][0][0] < gh) q[val[1][j]].push({1, j, 0, 0});
            d[1][j][1][0] = dl[1][j];
            if(d[1][j][1][0] < gh) q[d[1][j][1][0]].push({1, j, 1, 0});
            d[1][j][0][1] = dr[1][j];
            if(d[1][j][0][1] < gh) q[d[1][j][0][1]].push({1, j, 0, 1});
            d[1][j][1][1] = dl[1][j] + dr[1][j] - val[1][j];
            if(d[1][j][1][1] < gh) q[d[1][j][1][1]].push({1, j, 1, 1});
        }

        for(int s = 0; s < gh; s ++){
            vector<int> tt;
            while(! q[s].empty()){
                tt = q[s].front();
                q[s].pop();
                if(tt.size() < 4) continue;
                int x = tt[0], y = tt[1], l = tt[2], r = tt[3];
                if(d[x][y][l][r] != s) continue;
                for(int i = 0; i < 4; i ++){
                    int x2 = x + dx[i], y2 = y + dy[i];
                    if(x2 < 1 || x2 > m || y2 < 1 || y2 > n) continue;
                    if(l == 0 && s + dl[x2][y2] < d[x2][y2][1][r]){
                        d[x2][y2][1][r] = s + dl[x2][y2];
                        q[d[x2][y2][1][r]].push({x2, y2, 1, r});
                    }
                    if(r == 0 && s + dr[x2][y2] < d[x2][y2][l][1]){
                        d[x2][y2][l][1] = s + dr[x2][y2];
                        q[d[x2][y2][l][1]].push({x2, y2, l, 1});
                    }
                    if(l == 0 && r == 0 && s + dl[x2][y2] + dr[x2][y2] - val[x2][y2] < d[x2][y2][1][1]){
                        d[x2][y2][1][1] = s + dl[x2][y2] + dr[x2][y2] - val[x2][y2];
                        q[d[x2][y2][1][1]].push({x2, y2, 1, 1});
                    }
                    if(s + val[x2][y2] < d[x2][y2][l][r]){
                        d[x2][y2][l][r] = s + val[x2][y2];
                        q[d[x2][y2][l][r]].push({x2, y2, l, r});
                    }
                }
            }
        }
        for(int i = 1; i <= n; i ++) minimize(res, d[m][i][1][1]);
    }

    void process()
    {
        init();
        
        reset(d); reset(dl); reset(dr);
        for(int s = 0; s <= 9; s ++){
            for(int i = 1; i <= m; i ++){
                for(int j = 1; j <= n; j ++) val[i][j] = abs(a[i][j] - s);
            }
            calc();
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
