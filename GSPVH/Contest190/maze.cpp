#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "maze"
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
    int r, c;
    string mp[maxn];
    int f[maxn][maxn][1 << 4];
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

    int keyId[maxn], doorId[maxn];

    queue<vector<int>> q;

    #define isKey(ch) (keyId[ch] != -1)
    #define isDoor(ch) (doorId[ch] != -1)

    void process()
    {
        memset(keyId, -1, sizeof(keyId));
        memset(doorId, -1, sizeof(doorId));
        keyId['y'] = 0; doorId['Y'] = 0;
        keyId['r'] = 1; doorId['R'] = 1;
        keyId['g'] = 2; doorId['G'] = 2;
        keyId['b'] = 3; doorId['B'] = 3;

        cin >> r >> c;
        for(int i = 1; i <= r; i ++){
            cin >> mp[i];
            mp[i] = " " + mp[i];
        }
        for(int i = 1; i <= r; i ++){
            for(int j = 1; j <= c; j ++) {
                for(int t = 0; t < (1 << 4); t ++) f[i][j][t] = inf;
                if(mp[i][j] == '*') {
                    f[i][j][0] = 0;
                    q.push({i, j, 0});
                }
            }
        }
        while(! q.empty()){
            int i = q.front()[0], j = q.front()[1], t = q.front()[2];
            q.pop();
            for(int k = 0; k < 4; k ++){
                int x = i + dx[k], y = j + dy[k];
                if(x < 1 || x > r || y < 1 || y > c) continue;
                if(mp[x][y] == '#') continue;
                char s = mp[x][y];
                if(isKey(s)){
                    if(f[x][y][t | (1 << keyId[s])] > f[i][j][t] + 1) {
                        f[x][y][t | (1 << keyId[s])] = f[i][j][t] + 1;
                        q.push({x, y, t | (1 << keyId[s])});
                    }
                }
                else if(isDoor(s) && bit(t, doorId[s])){
                    if (f[x][y][t] > f[i][j][t] + 1)
                    {
                        f[x][y][t] = f[i][j][t] + 1;
                        q.push({x, y, t});
                    }
                }
                else if(s == '.' || s == '*'){
                    if (f[x][y][t] > f[i][j][t] + 1)
                    {
                        f[x][y][t] = f[i][j][t] + 1;
                        q.push({x, y, t});
                    }
                }
                else if(s == 'X'){
                    cout << "Escape possible in " << f[i][j][t] + 1 << " steps.";
                    exit(0);
                }
            }
        }
        cout << "The poor student is trapped!";
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
