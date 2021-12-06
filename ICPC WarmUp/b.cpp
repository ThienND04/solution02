#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "b"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

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
    pii pos[maxn];

    int dist(pii& p1, pii& p2){
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    }

    void process(){
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> pos[i].first >> pos[i].second;
        double minDist = inf;
        pii res;
        for(int i = 1; i <= n; i ++){
            double s = 0;
            for(int j = 1; j <= n; j ++){
                if(i == j) continue;
                s += dist(pos[i], pos[j]);
            }
            s /= n - 1;
            if(s < minDist) {
                res = pos[i];
                minDist = s;
            }
            else if(s == minDist) minimize(res, pos[i]);
        }
        cout << res.first << " " << res.second;
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
