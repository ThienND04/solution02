#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "camelot"
#define inf 1e9
#define mod 1000000007
#define maxn 110

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
    int n, slm = 0, slt = 0;
    string s[maxn];
    pii ma[maxn * maxn];
    int dxt[] = {1, 1, 1, 0, 0, -1, -1, -1}, dyt[] = {1, 0, -1, 1, -1, 1, 0, -1};
    int dxm[] = {1, 1, -1, -1, 2, 2, -2, -2}, dym[] = {2, -2, 2, -2, 1, -1, 1, -1};
    int idm[maxn][maxn], distT[maxn][maxn], distM[1000][maxn][maxn];
    bool visted[maxn][maxn];

    void BFST(int x, int y)
    {
        queue<pii> q;
        distT[x][y] = 0;
        q.push({x, y});
        while (!q.empty())
        {
            int u = q.front().first, v = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int newX = u + dxt[i], newY = v + dyt[i];
                if (newX < 1 || newX > n || newY < 1 || newY > n)
                    continue;
                if (s[newX][newY] == '#')
                    continue;
                if (distT[newX][newY] > distT[u][v] + 1)
                {
                    distT[newX][newY] = distT[u][v] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }

    void BFSM(int x, int y)
    {
        queue<pii> q;
        distM[idm[x][y]][x][y] = 0;
        q.push({x, y});
        while (!q.empty())
        {
            int u = q.front().first, v = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int newX = u + dxm[i], newY = v + dym[i];
                if (newX < 1 || newX > n || newY < 1 || newY > n)
                    continue;
                if (s[newX][newY] == '#')
                    continue;
                if (distM[idm[x][y]][newX][newY] > distM[idm[x][y]][u][v] + 1)
                {
                    distM[idm[x][y]][newX][newY] = distM[idm[x][y]][u][v] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }

    void process()
    {
        memset(distT, 99, sizeof(distT));
        memset(distM, 99, sizeof(distM));
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
            s[i] = ' ' + s[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i][j] == 'T')
                {
                    slt++;
                    BFST(i, j);
                }
                else if (s[i][j] == 'M')
                {
                    idm[i][j] = ++slm;
                    BFSM(i, j);
                }
            }
        }
        assert(slt == 1 && slm >= 1);
        // if(n == 100) cout << slm << " ";
        int ans = inf;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int result = 0;
                int tt = -1;
                for (int u = 1; u <= n; u++)
                {
                    for (int v = 1; v <= n; v++)
                    {
                        if (s[u][v] == 'T')
                        {
                            maximize(result, distT[i][j]);
                            if(tt == -1) tt = distT[i][j] & 1;
                            else if(tt != distT[i][j] % 2) result = inf;
                        }
                        else if (s[u][v] == 'M')
                        {
                            maximize(result, distM[idm[u][v]][i][j]);
                            if(tt == -1) tt = distM[idm[u][v]][i][j] % 2;
                            else if (tt != distM[idm[u][v]][i][j] % 2) result = inf;
                        }
                    }
                }
                minimize(ans, result);
            }
        }
        if (ans <= n * n)
            cout << ans;
        else
            cout << -1;
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