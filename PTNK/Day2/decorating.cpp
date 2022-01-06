 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "decorating"
#define inf 1e9
#define mod 1000000007
#define maxn 10000001

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
    int n;
    ll val[maxn];

    void query1(int x){
        if(val[x] == x){
            val[x * 2] = x * 2;
            val[x] += val[x * 2];
            val[x * 2 + 1] = x * 2 + 1;
            val[x] += val[x * 2 + 1];
        }
        else{
            query1(x * 2);
            query1(x * 2 + 1);
            // val[x] = x + val[x * 2] + val[x * 2 + 1];
        }
        while(x != 1){
            x /= 2;
            val[x] = x + val[x * 2] + val[x * 2 + 1];
        }
    }

    int query2(int x){
        return val[x];
    }

    void process(){
        cin >> n;
        val[1] = 1;
        while(n --){
            int q, x;
            cin >> q >> x;
            if(q == 1) query1(x);
            else cout << query2(x) << "\n";
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
