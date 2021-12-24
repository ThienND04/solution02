#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "n"
#define inf 1e9
#define mod 1000000007
#define maxn 100100

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 27

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
    int n, m;
    string s, t;
    int cnt[ALPHABET];
    int cntS[maxn][ALPHABET], next[maxn][ALPHABET];

    int get(int start, int c){
        return cntS[n][c] - cntS[start - 1][c];
    }

    bool ok(int start){
        // cerr << 1;
        for(int i = 0; i < ALPHABET; i ++){
            if(cnt[i] > get(start, i)) return 0;
        }
        return 1;
    }

    void init(){
        reset(cnt);
        reset(cntS);
        cin >> s >> t;
        n = s.size(), m = t.size();
        s = " " + s;
        t = " " + t;
        for (int i = 1; i <= m; i++)
        {
            cnt[t[i] - 'a']++;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < ALPHABET; j++)
            {
                cntS[i][j] = cntS[i - 1][j] + (s[i] - 'a' == j);
            }
        }

        for(int c = 0; c < ALPHABET; c ++) next[n + 1][c] = n + 1;

        for(int i = n; i >= 1; i --){
            for(int c = 0; c < ALPHABET; c ++){
                next[i][c] = next[i + 1][c];
                if(s[i] == c + 'a') next[i][c] = i;
            }
        }
    }

    void process()
    {
        init();
        if(! ok(1)){
            cout << -1;
            return;
        }
        string res = "";
        int start = 1;
        for(int i = 1; i <= m; i ++){
            for(int c = 0; c < ALPHABET; c ++){
                if(! cnt[c]) continue;
                cnt[c] --;
                if(ok(next[start][c] + 1)){
                    res += char(c + 'a');
                    start = next[start][c] + 1;
                    break;
                }
                cnt[c] ++;
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
