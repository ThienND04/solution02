#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "arthur"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

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
    int q;
    int n, w1, w2, w3;
    pii a[maxn];

    bool cmp(pii& p1, pii& p2){
        if(p1.first <= p1.second && p2.first > p2.second) 
            return 1;
        if (p1.first > p1.second && p2.first <= p2.second)
            return 0;
        if(p1.first <= p1.second && p2.first <= p2.second){
            return p1.first <= p2.first;
        }
        else return p1.second >= p2.second;
    }

    void solve(){
        cin >> n >> w1 >> w2 >> w3;
        for(int i = 1; i <= n; i ++) cin >> a[i].first >> a[i].second;
        sort(a + 1, a + n + 1, cmp);
        // for(int i = 1; i <= n; i ++){
        //     cerr << a[i].first << " " << a[i].second << "\n";
        // }
    }

    void process()
    {
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
