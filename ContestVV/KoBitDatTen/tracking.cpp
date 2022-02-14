 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "tracking"
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

struct Point{
    int x, y;
};

int n;
Point p0;
Point points[maxn];

double dist(Point p1, Point p2){
    int dx = p1.x - p2.x, dy = p1.y - p2.y;
    return sqrt(1ll * dx + 1ll * dy);
}

bool In(Point p1, Point p2){
    double d = dist(p1, p2), d1 = dist(p1, p0), d2 = dist(p2, p0);
    return (d1 + d2 != d);
}

namespace process{
    ll area(Point p1, Point p2, Point p3){
        int dx1 = p2.x - p1.x, dy1 = p2.y - p1.y;
        int dx2 = p3.x - p1.x, dy2 = p3.y - p1.y;

        return abs(1ll * dx1 * dy2 - 1ll * dy1 * dx2) / 2;
    }

    void process(){
        cin >> n;
        cin >> p0.x >> p0.y;

        for(int i = 1; i <= n; i ++) cin >> points[i].x >> points[i].y;

        int res = 0;
        double tmp = 1000000000000000000.5;
        cerr << fixed << setprecision(1) << tmp;

        for(int i = 1; i <= n; i ++){
            for(int j = i + 1; j <= n; j ++){
                for(int t = j + 1; t <= n; t ++){
                    if(In(points[i], points[j])) continue;
                    if(In(points[i], points[t])) continue;
                    if(In(points[t], points[j])) continue;
                    ll s1 = area(p0, points[i], points[j]);
                    ll s2 = area(p0, points[t], points[j]);
                    ll s3 = area(p0, points[i], points[t]);
                    ll s = area(points[t], points[i], points[j]);
                    if(s1 + s2 + s3 == s) res ++;
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
