#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "c"
#define inf 1e9
#define mod 1000000007
#define maxn 5001

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
    int m, n, q;
    int a[8][maxn];

    int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
    // ll dist[8][501];

    // void sub1(){
    //     while(q --){
    //         int x1, y1, x2, y2;
    //         cin >> x1 >> y1 >> x2 >> y2;
    //         memset(dist, 99, sizeof(dist));
    //         dist[x1][y1] = a[x1][y1];
    //         priority_queue<vector<ll>> qe;
    //         qe.push({- dist[x1][y1], x1, y1});
    //         while(! qe.empty()){
    //             ll u = qe.top()[1], v = qe.top()[2], l = -qe.top()[0];
    //             qe.pop();
    //             if(l != dist[u][v]) continue;
    //             for(int i = 0; i < 4; i ++){
    //                 int u1 = u + dx[i], v1 = v + dy[i];
    //                 if(u1 >= 1 && u1 <= m && v1 >= 1 && v1 <= n && l + a[u1][v1] < dist[u1][v1]){
    //                     dist[u1][v1] = l + a[u1][v1];
    //                     qe.push({- dist[u1][v1], u1, v1});
    //                 }
    //             }
    //         }
    //         cout << dist[x2][y2] << "\n";
    //     }
    // }

    int dist[2][maxn][2][maxn];

    void sub2(){
        // cerr << sizeof(dist) / 1024 / 1024;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        }
        memset(dist, 99, sizeof(dist));
        for (int x1 = 0; x1 < m; x1++)
        {
            for (int y1 = 0; y1 < n; y1++)
            {
                dist[x1][y1][x1][y1] = a[x1][y1];
                priority_queue<vector<ll>> qe;
                qe.push({-dist[x1][y1][x1][y1], x1, y1});
                while (!qe.empty())
                {
                    ll u = qe.top()[1], v = qe.top()[2], l = -qe.top()[0];
                    qe.pop();
                    if (l != dist[x1][y1][u][v])
                        continue;
                    for (int i = 0; i < 4; i++)
                    {
                        int u1 = u + dx[i], v1 = v + dy[i];
                        if (u1 >= 0 && u1 < m && v1 >= 0 && v1 < n && l + a[u1][v1] < dist[x1][y1][u1][v1])
                        {
                            dist[x1][y1][u1][v1] = l + a[u1][v1];
                            qe.push({-dist[x1][y1][u1][v1], u1, v1});
                        }
                    }
                }
            }
        }
        cin >> q;
        while (q--)
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1 --;
            x2 --;
            y1 --;
            y2 --;
            cout << dist[x1][y1][x2][y2] << "\n";
        }
    }

    ll DT[8][501][8][501];

    void sub3(){
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        }
        memset(DT, 99, sizeof(DT));
        for(int x1 = 1; x1 <= m; x1 ++){
            for(int y1 = 1; y1 <= n; y1 ++){
                DT[x1][y1][x1][y1] = a[x1][y1];
                priority_queue<vector<ll>> qe;
                qe.push({-DT[x1][y1][x1][y1], x1, y1});
                while (!qe.empty())
                {
                    ll u = qe.top()[1], v = qe.top()[2], l = -qe.top()[0];
                    qe.pop();
                    if (l != DT[x1][y1][u][v])
                        continue;
                    for (int i = 0; i < 4; i++)
                    {
                        int u1 = u + dx[i], v1 = v + dy[i];
                        if (u1 >= 1 && u1 <= m && v1 >= 1 && v1 <= n && l + a[u1][v1] < DT[x1][y1][u1][v1])
                        {
                            DT[x1][y1][u1][v1] = l + a[u1][v1];
                            qe.push({-DT[x1][y1][u1][v1], u1, v1});
                        }
                    }
                }
            }
        }
        cin >> q;
        while(q --){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << DT[x1][y1][x2][y2] << "\n";
        }
    }

    void process()
    {
        cin >> m >> n;
        if(n <= 500) sub3();
        else if (m <= 2)
            sub2();
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
