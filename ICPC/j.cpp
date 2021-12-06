#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "j"
#define inf 1e9
#define mod 1000000007
#define maxn 5050

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
    int m, n;
    string s[maxn];
    short top[maxn][maxn], left[maxn][maxn], right[maxn][maxn], bot[maxn][maxn];

    void process(){
        cin >> m >> n;
        reset(top);
        reset(left);
        reset(right);
        reset(bot);
        for(int i = 1; i <= m; i ++){
            cin >> s[i];
            s[i] = " " + s[i];
        }
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                if(s[i][j] == '1'){
                    top[i][j] = top[i - 1][j] + 1;
                    left[i][j] = left[i][j - 1]  + 1;
                }
            }
        }
        for(int i = m; i >= 1; i --){
            for(int j = n; j >= 1; j --){
                if(s[i][j] == '1'){
                    bot[i][j] = bot[i + 1][j] + (s[i][j] == '1');
                    right[i][j] = right[i][j + 1] + (s[i][j] == '1');
                }
            }
        }

        short k = -1;
        pii res;

        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                short nk = top[i][j];
                minimize(nk, left[i][j]);
                minimize(nk, right[i][j]);
                minimize(nk, bot[i][j]);
                pii tmp = {i, j};
                if(k < nk - 1){
                    k = nk - 1;
                    res = {i, j};
                }
                else if(k == nk - 1 && res > tmp){
                    res = tmp;
                } 
            }
        }
        if(k >= 0) {
            cout << k * 4 + 1 << "\n";
            cout << res.first << " " << res.second;
        }
        else cout << -1;
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
