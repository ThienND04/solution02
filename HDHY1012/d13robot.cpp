#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "d13robot"
#define inf 1e9
#define mod 1000000007
#define maxn 201

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
    int n, m, a, b, c, d;
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    char turns[] = {'D', 'U', 'R', 'L'};
    int mp[maxn][maxn];
    int dist[maxn][maxn];

    void BFS(){
        memset(dist, 99, sizeof(dist));
        dist[0][0] = 0;
        queue<pii> q;
        q.push({0, 0});
        while(! q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i ++){
                int newX = x + dx[i], newY = y + dy[i];
                if(newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
                if(mp[newX][newY]) continue;
                if(dist[newX][newY] > dist[x][y] + 1){
                    dist[newX][newY] = dist[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }   

    void process()
    {
        cin >> n >> m >> a >> b >> c >> d;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++) cin >> mp[i][j];
        }
        BFS();
        // if(dist[a][b] > n * m || dist[c][d] > n * m){
        //     cout << -1;
        //     return;
        // }
        assert(dist[a][b] <= n * m && dist[c][d] <= n * m);

        string res = "",  s = "";
        while(a || b || c || d){
            if(a == 0 && b == 0) {
                swap(a, c);
                swap(b, d);
            }
            while(a || b){
                for(int i = 0; i < 4; i ++){
                    int newX = a + dx[i], newY = b + dy[i];
                    if(newX < 0 || newX >= n || newY < 0 || newY >= m) continue;
                    if(dist[newX][newY] + 1 == dist[a][b]){
                        s += turns[i];
                        a = newX, b = newY;
                        break;
                    }
                }
            }
            res += s;
            for (char t : s)
            {
                int newX = c, newY = d;
                if (t == 'L')
                    newY--;
                else if (t == 'R')
                    newY++;
                else if (t == 'U')
                    newX--;
                else
                    newX++;
                if (newX < 0 || newX >= n || newY < 0 || newY >= m || mp[newX][newY])
                    continue;
                c = newX, d = newY;
            }
            s = "";
        }
        cout << res.size() << "\n" << res;
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
