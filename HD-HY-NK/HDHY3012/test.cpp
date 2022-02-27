#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "test"
#define inf 1e9
#define mod 1000000007
#define maxn 100100

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
    string s;
    int n;
    int d[maxn], dx[maxn];
    stack<int> st[maxn];

    int calc(int lf, int rt){
        int res = 0;
        int num = 0, sl = 0;

        for(int i = lf; i <= rt; i ++){
            if(s[i] == '('){
                maximize(num, 1);
                res = (res + 1ll * num * sl) % mod;
                num = 0;
                sl = calc(i + 1, dx[i] - 1);
                i = dx[i];
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                maximize(num, 1);
                res = (res + 1ll * num * sl) % mod;
                num = 0;
                sl = 1;
            }
            else if(s[i] >= '0' && s[i] <= '9'){
                num = (10ll * num + s[i] - '0') % mod;
            }
        }
        maximize(num, 1);
        res = (res + 1ll * num * sl) % mod;
        return res;
    }

    void process(){
        cin >> s;
        s = " " + s;
        n = s.size() - 1;
        d[0] = 0;
        for(int i = 1; i <= n; i ++){
            if(s[i] == '(') {
                d[i] = d[i - 1] + 1;
                st[d[i]].push(i);
            }
            else if(s[i] == ')'){
                d[i] = d[i - 1] - 1;
                dx[i] = st[d[i] + 1].top();
                dx[dx[i]] = i;
                st[d[i] + 1].pop();
            }
            else d[i] = d[i - 1];
        }
        cout << calc(1, n);
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
