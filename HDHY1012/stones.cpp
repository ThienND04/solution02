#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "stones"
#define inf 1e9
#define mod 1000000007
#define maxn 31

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
    int n;
    vector<pii> m[maxn];
    int a[6 * maxn];
    bool ok[6 * maxn][8 * maxn * maxn];

    #define color(x) ((x - 1) / 6 + 1)

    int total[2 * maxn], ids[2 * maxn];


    void Truy(int s){
        int cnt = 0;
        int u = 6 * n + 1;
        while(color(u) > 1){
            for (int j = (color(u) - 2) * 6 + 1; j <= (color(u) - 1) * 6; j++){
                if(ok[j][s - a[u]]) {
                    total[cnt ++] = a[u];
                    s -= a[u];
                    u = j;
                    break;
                }
            }
        }
        total[cnt] = a[u];
        reverse(total + 1, total + cnt + 1);
        cnt = 0;
        
        for(int i = 1; i <= n; i ++){
            for(int x = 0; x < 4; x ++){
                for(int y = x + 1; y < 4; y ++){
                    if(m[i][x].first + m[i][y].first == total[i]){
                        ids[++ cnt] = m[i][x].second;
                        ids[++ cnt] = m[i][y].second;
                        goto ct;
                    }
                }
            }
            ct: continue;
        }
        sort(ids + 1, ids + cnt + 1);
        for(int i = 1; i <= cnt; i ++) cout << ids[i] << " ";
    }

    void process()
    {
        cin >> n;
        int sum = 0, cnt = 0;
        for(int i = 1; i <= 4 * n; i ++) {
            int w, c;
            cin >> w >> c;
            sum += w;
            m[c].push_back({w, i});
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j < 4; j ++){
                for(int k = j + 1; k < 4; k ++) a[++ cnt] = m[i][j].first + m[i][k].first;
            }
        }
        a[++ cnt] = 0;
        ok[0][0] = 1;
        for(int i = 1; i <= cnt; i ++){
            if(color(i) == 1) {
                ok[i][a[i]] = 1;
            }
            else {
                for(int j = (color(i) - 2) * 6 + 1; j <= (color(i) - 1) * 6; j ++){
                    for(int s = 0; s <= 8 * n * n - a[i]; s ++){
                        if(ok[j][s]) ok[i][s + a[i]] = 1;
                    }
                }
            }
        }
        int result = inf;
        for(int s = 0; s <= 8 * n * n; s ++){
            if(ok[cnt][s]) minimize(result, abs(sum - 2 * s));
        }
        // cerr << result << "\n";
        for(int s = 0; s <= 8 * n * n; s ++){
            if (ok[cnt][s] && abs(sum - 2 * s) == result) {
                return Truy(s);
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
