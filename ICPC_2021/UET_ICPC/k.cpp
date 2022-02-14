#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "k"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

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

class BIT{
private: 
    map<int, ll> cnt[maxn];

    void _update(int x, int y, int d){
        for(; x < maxn; x += x & -x){
            for(int z = y; z < maxn; z += z & -z){
                cnt[x][z] += d;
            }
        }
    }

    ll _get(int x, int y){
        ll res = 0;
        for(; x > 0; x -= x & -x){
            for(int z = y; z > 0; z -= z & -z){
                res += cnt[x][z];
            }
        }
        return res;
    }

public:
    ll get(int x, int y, int u, int v){
        return _get(u, v) - _get(x - 1, y) - _get(x, y - 1) + _get(x - 1, y - 1);
    }

    void update(int x, int y, int u, int v, int d){
        _update(x, y, d);
        _update(x, v + 1, -d);
        _update(u + 1, y, -d);
        _update(u + 1, v + 1, d);
    }

};

namespace process{
    int n, m, k, q;
    BIT bitTree;

    void process(){
        cin >> n >> m >> k >> q;
        while(k --)  {
            int x, y;
            cin >> x >> y;
            bitTree.update(x, 1, x, m, 1);
            bitTree.update(1, y, m, y, 1);
        }
        while(q --){
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            int d = max(u - x, v - y) + 1;
            int tmp = bitTree.get(x, y, u, v);
            cerr << d << " " << tmp << "\n";
            if(d <= tmp) cout << "YES\n";
            else cout << "NO\n";
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
