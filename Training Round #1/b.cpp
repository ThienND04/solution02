#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "b"
#define inf 1e9
#define mod 1000000007
#define maxn 3030

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

namespace caculate{
    template<class T>
    void add(T& x, T y){
        x += y;
        if(x >= mod) x -= mod;
    }
    template<class T>
    void sub(T& x, T y){
        x -= y;
        if(x < 0) x += mod;
    }
    template<class T>
    void maximize(T& x, T y){
        if(x < y) x = y;
    }
    template<class T>
    void minimize(T& x, T y){
        if(x > y) x = y;
    }
}

using namespace caculate;

namespace process{
    int n;
    string s;
    int dp[maxn][maxn], sum[maxn][maxn];

    void process(){
        cin >> n >> s;
        reset(dp);
        dp[1][1] = sum[1][1] = 1;
        for(int i = 2; i <= n; i ++){
            for(int k = 1; k <= i; k ++){
                if(s[i - 2] == '>'){
                    dp[i][k] = sum[i - 1][k - 1];
                } 
                else {
                    dp[i][k] = sum[i - 1][i - 1];
                    sub(dp[i][k], sum[i - 1][k - 1]);
                    // for(int j = k; j < i; j ++) add(dp[i][k], dp[i - 1][j]);
                }
                sum[i][k] = sum[i][k - 1];
                add(sum[i][k], dp[i][k]);
            }
        }
        int res = 0;
        for(int i = 1; i <= n; i ++) add(res, dp[n][i]);
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
