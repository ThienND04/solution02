#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "hamming"
#define inf 1e9
#define mod 1000000007
#define maxn 1000001

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
    int subtask;
    ll m, n;
    int la, lb;
    int cntA[maxn][26], cntB[maxn][26];
    string a, b;

    void process(){
        cin >> subtask >> m >> n >> a >> b;
        la = a.size(), lb = b.size();
        int d = __gcd(la, lb);
        a = "0" + a;
        b = "0" + b;
        for(int i = 1; i <= la; i ++){
            cntA[i % d][a[i] - 'a'] ++;
        }
        for(int i = 1; i <= lb; i ++){
            cntB[i % d][b[i] - 'a'] ++;
        }
        ll res = 0;
        for(int i = 0; i < d; i ++){
            for(int j = 0; j < 26; j ++){
                res += 1ll* cntA[i][j] * cntB[i][j];
            }
        }
        res = 1ll * la / d * lb - res;
        res *= 1ll * la * m  / (1ll* la / d * lb);
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
