#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "pou2"
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
    pii v[3];
    int d[3];
    vector<pii> res;

    void process(){
        for(int i = 0; i < 3; i++){
            cin >> v[i].first;
            v[i].second = i + 1;
        }
        sort(v, v + 3);
        while(1){
            sort(v, v + 3);
            if(v[0].first == 0) break;
            int mul = v[0].first;
            for(int i = 0; i < 3; i ++) {
                d[i] = v[i].first % mul;
                v[i].first /= mul;
            }

            for(int i = 0; i <= 20; i ++){
                if(v[1].first & (1 << i)){
                    v[1].first -= (1 << i);
                    v[0].first <<= 1;
                    res.push_back({v[1].second, v[0].second});
                }
                else if(v[2].first > (1 << i)){
                    v[2].first -= (1 << i);
                    v[0].first <<= 1;
                    res.push_back({v[2].second, v[0].second});
                }
            }
            v[0].first *= mul;
            v[1].first = v[1].first * mul + d[1];
            v[2].first = v[2].first * mul + d[2];
        }

        cout << res.size() << "\n";
        for(pii p: res){
            cout << p.first << " " << p.second << "\n";
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
