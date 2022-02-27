 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "even"
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

namespace process{
    int n;
    ll h[maxn];
    ll l[maxn], r[maxn];

    ll getRand(ll MAXOUT = 4e18){
        int t = rand();
        int a = rand(), b = rand();
        return (1ll * t * a + b) % MAXOUT;
    }
    
    void process(){
        cin >> n;
        vector<int> v;
        for(int i = 1; i <= n; i ++) {
            cin >> l[i] >> r[i];
            r[i] ++;
            v.push_back(l[i]);
            v.push_back(r[i]);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for(int i = 1; i <= n; i ++){
            l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin() + 1;
            r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin() + 1;
        }
        for(int i = 1; i <= v.size(); i ++){
            h[i] = getRand();
            assert(h[i] > 0);
        }
        map<ll, int> mp;
        mp[0] = 1;
        ll res = 0, x = 0;
        for(int i = 1; i <= n; i ++){
            x ^= h[l[i]];
            x ^= h[r[i]];
            res += mp[x];
            mp[x] += 1;
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
