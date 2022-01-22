#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "rlesubstr"
#define inf 1e9
#define mod 111539786
#define maxn 1002

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
    int n = 0;
    string s;
    char ch[maxn];
    int num[maxn], dp[maxn];
    int nt[maxn][26];

    void init(){
        cin >> s;
        n = 0;
        reset(dp);
        for (int i = 0, tmp = 0; i < s.size(); i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                num[n] = tmp;
                tmp = 0;
                ch[++n] = s[i];
            }
            else
            {
                tmp = (tmp * 10 + s[i] - '0') % mod;
            }
            if(i == s.size() - 1) num[n] = tmp;
        }
        // for(int i = 1; i <= n; i ++){
        //     cerr << ch[i] << ": " << num[i] << "\n";
        // }
        // cerr << "-----------------------------\n";
        int last[26];
        fill(last, last + 26, n + 1);
        cerr << 'z' - 'a';
        for(int i = n; i >= 1; i --){
            for(int j = 0; j < 26; j ++){
                nt[i][j] = last[j];
            }
            last[ch[i] - 'a'] = i;
        }
        for(int j = 0; j < 26; j ++){
            nt[0][j] = last[j];
        }
    }

    void solve(){
        init();
        reset(dp);
        for(int j = 0; j < 26; j ++){
            dp[nt[0][j]] = 1;
        }
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < 26; j ++){
                if(j == ch[i] - 'a') continue;
                dp[nt[i][j]] = (dp[nt[i][j]] + 1ll * dp[i] * num[i]) % mod;
            }
            dp[nt[i][ch[i] - 'a']] = (dp[nt[i][ch[i] - 'a']] + dp[i]) % mod;
        }
        int res = 0;
        for(int i = 1; i <= n; i ++){
            res =  (res + 1ll * num[i] * dp[i]) % mod;
        }
        cout << res << "\n";
    }

    void process()
    {
        int q;
        cin >> q;
        while(q --){
            solve();
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
