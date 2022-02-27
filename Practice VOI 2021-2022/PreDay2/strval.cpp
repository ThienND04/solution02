#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "strval"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

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

int POW(int a, int b){
    if(b == 1) return a;
    int c = POW((1ll * a * a) % mod, b / 2);
    if(b % 2 == 1) c = (1ll * c * a) % mod;
    return c;
}

int n, k;
string s;

namespace subtask1{
    void subtask1(){
        cout << POW(2, n);
    }
}

namespace subtask2{
    map<string, int> cnt;

    void subtask2(){
        for(int x = 0; x < (1 << n); x ++){
            string tmp = "";
            for(int i = 1; i <= n; i ++){
                if(! bit(x, i - 1)) continue;
                tmp += s[i];
            }
            cnt[tmp] ++;
        }
        int res = 0;
        for(auto tmp: cnt){
            //cerr << tmp.first << " " << tmp.second << "\n";
            add(res, POW(tmp.second, k));
        }
        cout << res;
    }
}

namespace process{
    void process(){
        cin >> n >> k >> s;
        s = " " + s;
        if(k == 1) return subtask1::subtask1();
        if(n <= 20) return subtask2::subtask2();
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
