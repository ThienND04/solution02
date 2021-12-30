#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "b"
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
    int n;
    int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];

    bool ok(){
        int cnt = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(c[i][j] != b[i][j] && cnt)  return 0;
                cnt += (c[i][j] != b[i][j]);
            }
        }
        return 1;
    }

    void query(int t, int x){
        if(t == 1){
            for(int i = 1; i <= n; i ++){
                swap(c[i][x + 1], c[i][x]);
            }
        }
        else{
            for(int i = 1; i <= n; i ++) {
                c[x][i] = (c[x][i] ? 0 : 1);
            }
        }
    }

    pii step[maxn];
    int m = 0;

    bool sol = 0;

    void Try(int numQ){
        if(numQ == 0){
            if(ok()) sol = 1;
            return;
        }
        for(int i = 1; i < n; i ++){
            query(1, i);
            Try(numQ - 1);
            query(1, i);
        }
        for(int i = 1; i <= n; i ++){
            query(2, i);
            Try(numQ - 1);
            query(2, i);
        }
    }

    void Try2(int numQ)
    {
        if (numQ == 0)
        {
            if (ok()){
                for(int i = 1; i <= m; i ++){
                    cout << step[i].first << " " << step[i].second << "\n";
                }
                exit(0);
            }
            return;
        }
        for (int i = 1; i < n; i++)
        {
            query(1, i);
            step[++ m] = {1, i};
            Try2(numQ - 1);
            m --;
            query(1, i);
        }
        for (int i = 1; i <= n; i++)
        {
            query(2, i);
            step[++ m] = {2, i};
            Try2(numQ - 1);
            m --;
            query(2, i);
        }
    }

    void process()
    {
        cin >> n;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                cin >> a[i][j];
                c[i][j] = a[i][j];
            }
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++) cin >> b[i][j];
        }
        int l = 0, r = 8;
        if(ok()){
            cout << 0 << "\n";
            return;
        }
        while(r - l > 1){
            sol = 0;
            int mid = (l + r) / 2;
            Try(mid);
            if(sol) r = mid;
            else l = mid;
        }
        Try(r);
        if(! sol){
            cout << -1;
            return;
        }
        cout << r << "\n";
        Try2(r);
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
