#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "c"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

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
    int n, k;

    void process()
    {
        cin >> n >> k;
        int res = 0;
        for(int x = 1; x < n; x ++){
            for(int y = 1; x * y < n; y ++){
                if (x < y) for(int a = x + 1; a * y < n; a ++){
                    if((n - a * y) % x != 0) continue;
                    int c = a - x, d = (n - a * y) / x;
                    int b = d + y;
                    if(a != k && b != k && a * b - c * d == n){
                        res ++;
                        // cerr << a << " " << b << " " << c << " " << d << "\n";
                    }
                }
                else
                    for (int b = y + 1; b * x < n; b++)
                    {
                        if ((n - b * x) % y != 0)
                            continue;
                        int d = b - y, c = (n - b * x) / y;
                        int a = c + x;
                        if (a != k && b != k && a * b - c * d == n)
                        {
                            res++;
                            // cerr << a << " " << b << " " << c << " " << d << "\n";
                        }
                    }
            }
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
