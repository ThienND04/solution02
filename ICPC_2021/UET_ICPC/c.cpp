#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "c"
#define inf 1e9
#define mod 1000000007
#define maxn 500001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
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
    int n, c, b;
    int z[maxn], a[maxn];

    void process(){
        cin >> n >> c >> b;
        memset(a, -1, sizeof(a));
        for(int i = 1; i <= b; i ++){
            cin >> z[b];
            a[z[b]] = 0;
        }
        int t=  c / 2;
        for(int i = n - 1; i >= 1 && t; i --){
            if(a[i] == -1){
                a[i] = 1;
                -- t; --i;
            }
        }   
        if(c & 1){
            a[1] = 1;
        }
        for(int i = 1; i <= n; i ++){
            if(a[i] == -1) cout << 0;
            else cout << a[i];
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
