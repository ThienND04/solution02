 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "dabstr"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

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
    int n, m;

    string s[maxn];

    int d(const int& a, const int& i){
        int cnt = 0;
        for(int j = 0; j < m; j ++){
            if(bit(a, j) != s[i][j] - '0') cnt ++;
        }
        return cnt;
    }

    void process(){
        cin >> n;
        for(int i = 0; i < n; i ++) cin >> s[i];
        m = s[0].size();

        int res = inf;

        for(int a = 0; a < (1 << m); a ++){
            for(int b = 0; b < (1 << m); b ++){

                int tmp = 0;
                for(int i = 0; i < n; i ++){
                    tmp += min(d(a, i), d(b, i));
                }   
                minimize(res, tmp);
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
