#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "nxcmct"
#define inf 1e9
#define mod 1000000007
#define maxn 101

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
    
    string res = "no";
    char c[maxn * maxn], sz = 0;
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    char move[] = {'U', 'D', 'R', 'L'};
    int vx, vy, mx, my, px, py, tx, ty;

    void DFS(int i, int j){
        if(i == tx && j == ty){
            if(! vst[px][py]) return;
            if(res == "no"){
                res = "";
                for(int k = 1; k <= sz; k ++) res += c[k];
            }
            else if(res.size() > sz){
                res = "";
                for (int k = 1; k <= sz; k++)
                    res += c[k];
            }
            return;
        }
        for(int k = 0; k < 4; k ++){
            int x = i + dx[k], y = j + dy[k];
            if(x < 1 || x > m || y < 1 || y > n) continue;
            if(vst[x][y]) continue;
            vst[x][y] = 1;
            c[++ sz] = move[k];
            DFS(x, y);
            vst[x][y] = 0;
            sz --;
        }
    }

    void process()
    {
        while(cin >> m >> n >> mx >> my >> px >> py >> tx >> ty >> vx >> vy){
            res = "no";
            sz = 0;
            reset(vst);
            vst[vx][vy] = 1;
            DFS(mx, my);
            cout << res << "\n";
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
