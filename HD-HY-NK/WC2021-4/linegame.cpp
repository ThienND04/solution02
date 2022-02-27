#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "linegame"
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

struct line{
    ll a, b, c;

    bool inLine(const pii& p) const {
        return a * p.first + b * p.second + c == 0;
    }
    
    bool operator<(const line& other) const {
        return a < other.a;
    }
};

namespace process{
    int k;
    int n, p;
    pii points[maxn];

    line creatLine(const pii& point1, const pii& point2){
        int x1 = point1.first, x2 = point2.first;
        int y1 = point1.second, y2 = point2.second;
        ll a = y1 - y2, b = x2 - x1;
        ll c = -a * x1 - b * y1;
        return {a, b, c};
    }

    bool check(const line& l1){
        int cnt = 0;
        for(int i = 1; i <= n ; i++){
            if(l1.inLine(points[i])) cnt ++;
        }
        return 100.0 * cnt / n >= 1.0 * p;
    }


    bool solve(){
        cin >> n >> p;
        for(int i = 1; i <= n; i ++) cin >> points[i].first >> points[i].second;
        map<line, bool> mp;
        for(int i = 0; i < 500; i ++){
            int u = rand() % n + 1;
            int v = rand() % n + 1;
            if(u == v) continue;
            line tmp = creatLine(points[u], points[v]);
            if(mp[tmp] == 1) continue;
            mp[tmp] = 1;
            if(check(tmp)) return 1;
        }
        return 0;
    }

    void process(){
        cin >> k;
        while(k --){
            if(solve()) cout << "possible\n";
            else cout << "impossible\n";
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
