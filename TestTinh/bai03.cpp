 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bai03"
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
    int n, m;
    int a[maxn], BIT[maxn];

    void update(int x, int d){
        for(; x < maxn; x += x & -x){
            BIT[x] += d;
        }
    }

    int get(int x){
        int res = 0;
        for(; x > 0; x -= x & -x){
            res += BIT[x];
        }
        return res;
    }

    void process(){
        reset(BIT);
        cin >> n >> m;
        for(int i = 1; i <= n; i ++) cin >> a[i];

        ll res = 0;
        for(int i = 1; i <= n; i ++ ){
            res += get(m - a[i]);
            update(a[i], 1);
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
