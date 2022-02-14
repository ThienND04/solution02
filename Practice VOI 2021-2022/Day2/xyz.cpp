#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "xyz"
#define inf 1000000001
#define mod 1000000007
#define maxn 105

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
    int x, y, z;
};

int n;
Point points[maxn];

namespace subtask1{
    ll res = 1e15;
    void Try(int pos, pii mmX, pii mmY, pii mmZ){
        if(pos == n + 1){
            if(mmX.first == inf || mmY.first == inf || mmZ.first == inf) return;
            ll tmp = 0;
            tmp += mmX.second - mmX.first;
            tmp += mmY.second - mmY.first;
            tmp += mmZ.second - mmZ.first;
            minimize(res, tmp);
            return;
        }
        pii tmpX = {min(mmX.first, points[pos].x), max(mmX.second, points[pos].x)};
        pii tmpY = {min(mmY.first, points[pos].y), max(mmY.second, points[pos].y)};
        pii tmpZ = {min(mmZ.first, points[pos].z), max(mmZ.second, points[pos].z)};

        Try(pos + 1, tmpX, mmY, mmZ);
        Try(pos + 1, mmX, tmpY, mmZ);
        Try(pos + 1, mmX, mmY, tmpZ);
    }

    void subtask1(){
        Try(1, {inf, -inf}, {inf, -inf}, {inf, -inf});
        cout << res;
    }
}

namespace subtask2{
    bool cmpX(const Point& p1, const Point& p2){
        return (p1.x < p2.x);
    }
    bool cmpY(const Point& p1, const Point& p2){
        return (p1.y < p2.y);
    }

    Point pyz[maxn];
    int minZL[maxn], maxZL[maxn];
    int minZR[maxn], maxZR[maxn];

    ll calc(int num){
        sort(pyz + 1, pyz + num + 1, cmpY);
        fill(minZL, minZL + num + 2, inf);
        fill(minZR, minZR + num + 2, inf);
        fill(maxZL, maxZL + num + 2, -inf);
        fill(maxZR, maxZR + num + 2, -inf);

        for(int i = 1; i <= num; i ++){
            minZL[i] = min(minZL[i - 1], pyz[i].z);
            maxZL[i] = max(maxZL[i - 1], pyz[i].z);
        }

        for(int i = num; i >= 1; i --){
            minZR[i] = min(minZR[i + 1], pyz[i].z);
            maxZR[i] = max(maxZR[i + 1], pyz[i].z);
        }

        ll res = 1e15;

        for(int i = 1; i <= num; i ++){
            for(int j = i; j <= num; j ++){
                ll t = pyz[j].y - pyz[i].y;

                if(i == 1 && j == num) continue;
                int minZ = min(minZL[i - 1], minZR[j + 1]);
                int maxZ = max(maxZL[i - 1], maxZR[j + 1]);
                t += maxZ - minZ;
                minimize(res, t);
            }
        }
        return res;
    }

    void subtask2(){
        sort(points + 1, points + n + 1, cmpX);
        ll res = 1e15;

        for(int i = 1; i <= n; i ++){
            for(int j = i; j <= n; j ++){
                int tx = points[j].x - points[i].x;
                int num = 0;
                for(int t = 1; t <= n; t ++){
                    if(t < i || t > j){
                        pyz[++ num] = points[t];
                    }
                }
                if(num == 0) continue;
                minimize(res, tx + calc(num));
            }
        }
        cout << res;
    }
}

namespace process{
    void process(){
        cin >> n;
        for(int i = 1; i <= n; i ++){
            int x, y, z;
            cin >> x >> y >> z;
            points[i] = {x, y, z};
        }
        if(n <= 10) return subtask1::subtask1();
        if(n <= 100) return subtask2::subtask2();
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
