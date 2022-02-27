 
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
    int cnt[2][2][31];
    int res = inf;

    void Try(int pos){
        if(pos == n){
            int tmp = 0;
            for(int j = 0; j < m; j ++) {
                tmp += min(cnt[0][0][j], cnt[0][1][j]);
                tmp += min(cnt[1][0][j], cnt[1][1][j]);
            }   
            minimize(res, tmp);
            return;
        }
        for(int j = 0; j < m; j ++) cnt[1][s[pos][j] - '0'][j] ++;
        Try(pos + 1);
        for(int j = 0; j < m; j ++) cnt[1][s[pos][j] - '0'][j] --;

        for(int j = 0; j < m; j ++) cnt[0][s[pos][j] - '0'][j] ++;
        Try(pos + 1);
        for(int j = 0; j < m; j ++) cnt[0][s[pos][j] - '0'][j] --;
    }

    void process(){
        cin >> n;
        for(int i = 0; i < n; i ++) cin >> s[i];
        m = s[0].size();

        reset(cnt);
        Try(0);
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
