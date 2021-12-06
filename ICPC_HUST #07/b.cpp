#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "b"
#define inf 1e9
#define mod 1000000007
#define maxn 3000

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
    int n, x;
    int res = 0;
    void process(){
        cin >> n >> x;
        for(int a = 0; a <= n; a ++){
            if(a == x) continue;
            for(int s = 1; s <= a; s ++){
                int c = a - s;
                for(int b = 0; b <= n / s; b ++){
                    if(b == x) continue;
                    if(a * b > n && (a * b - n) % c == 0 && (a * b - n) / c < b) {
                        res ++;
                        // cerr << a << " " << b << " " << c << " " << (a * b - n) / c << endl;   
                    }
                }
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
