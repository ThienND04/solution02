#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "e"
#define inf 1e9
#define mod 1000000007
#define maxn 16

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
    ll n;
    int cnt = 0;
    ll dp[maxn][4][150][150];

    bool isPrime(int m){
        if(m < 2) return 0;
        else if(m > 2){
            if(m % 2 == 0) return 0;
            for(int i = 3; i * i <= m; i ++){
                if(m % i == 0) return 0;
            }
        }
        return 1;
    }
    
    void process()
    {
        cin >> n;
        reset(dp);
        dp[0][0][0][0] = 1;
        int t;
        for(int i = 1; i <= 15 && n > 0; i ++){
            cnt ++;
            t = n % 10;
            n /= 10;
            for(int rem = 0; rem <= 2; rem ++){
                for(int s1 = 0; s1 < 150; s1 ++){
                    for(int s2 = 0; s2 < 150; s2 ++){
                        if(dp[i - 1][rem][s1][s2] == 0) continue;
                        for(int u = 0; u < 10; u ++){
                            int v = 0;
                            v = t - (u + rem);
                            if((v & 1) == 0 && v >= 0 && v <= 18){
                                v /= 2;
                                dp[i][0][s1 + u][s2 + v] += dp[i - 1][rem][s1][s2];
                            }
                            v = t + 10 - (u + rem);
                            if ((v & 1) == 0 && v >= 0 && v <= 18)
                            {
                                v /= 2;
                                dp[i][1][s1 + u][s2 + v] += dp[i - 1][rem][s1][s2];
                            }
                            v = t + 20 - (u + rem);
                            if ((v & 1) == 0 && v >= 0 && v <= 18)
                            {
                                v /= 2;
                                dp[i][2][s1 + u][s2 + v] += dp[i - 1][rem][s1][s2];
                            }
                        }
                    }
                }
            }
        }
        ll res = 0;
        for(int s1 = 0; s1 < 150; s1 ++){
            if(! isPrime(s1)) continue;
            for(int s2 = 0; s2 < 150; s2 ++){
                if(! isPrime(s2)) continue;
                res += dp[cnt][0][s1][s2];
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
