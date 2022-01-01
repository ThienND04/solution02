#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "connect"
#define inf 1e9
#define mod 1000000007
#define maxn 51

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
    string a[maxn];

    bool visited[maxn][maxn];
    const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

    void DFS(int x, int y){
        for(int i = 0; i < 4; i ++){

        }
    }

    void process()
    {
        cin >> m >> n;
        for(int i = 1; i <= m; i ++) {
            cin >> a[i];
            a[i] = " " + a[i];
        }
        for(int s = 0; s <= 9; s ++){
            for(int i = 1; i <= m; i ++){
                for(int j = 1; j <= n; j ++){
                    reset(visited);
                }
            }
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
