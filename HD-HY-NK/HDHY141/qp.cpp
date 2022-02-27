#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "qp"
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
    pii x[4], u[4];
    vector<vector<pii>> res1, res2;

    void init(){
        for(int i = 1; i <= 3; i ++){
            cin >> x[i].first; x[i].second = i;
        }
        sort(x + 1, x + 4);
        for(int i = 1; i <= 3; i ++){
            cin >> u[i].first; u[i].second = i;
        }
        sort(u + 1, u + 4);
    }

    void calc(pii pos[], vector<vector<pii>>& vt){
        if(pos[1].first == pos[2].first && pos[2].first == pos[3].first){
            cout << -1;
            exit(0);
        }
        if(pos[1].first == pos[2].first){
            pos[1].first = 2 * pos[3].first - pos[1].first;
            vt.push_back({pos[1], pos[2], pos[3]});
            sort(pos + 1, pos + 4);
        }
        else if(pos[2].first == pos[3].first){
            pos[3].first = 2 * pos[1].first - pos[3].first;
            vt.push_back({pos[1], pos[2], pos[3]});
            sort(pos + 1, pos + 4);
        }
        while(pos[2].first - pos[1].first != pos[3].first - pos[2].first){
            if(pos[2].first - pos[1].first > pos[3].first - pos[2].first){
                pos[3].first = 2 * pos[2].first - pos[3].first;
            }
            else{
                pos[1].first = 2 * pos[2].first - pos[1].first;
            }
            vt.push_back({pos[1], pos[2], pos[3]});
            sort(pos + 1, pos + 4);
        }
    }

    void trace(){
        if(x[2].first - x[1].first != u[2].first - u[1].first || abs(x[1].first - u[1].first) % (2 * (x[2].first - x[1].first)) != 0){
            cout << -1;
            return;
        }
        while(x[1].first < u[1].first){
            x[1].first = 2 * x[3].first - x[1].first;
            res1.push_back({x[1], x[2], x[3]});
            x[2].first = 2 * x[3].first - x[2].first;
            res1.push_back({x[1], x[2], x[3]});
            sort(x + 1, x + 4);
        }
        while(u[1].first < x[1].first){
            u[1].first = 2 * u[3].first - u[1].first;
            res2.push_back({u[1], u[2], u[3]});
            u[2].first = 2 * u[3].first - u[2].first;
            res2.push_back({u[1], u[2], u[3]});
            sort(u + 1, u + 4);
        }
        if(! res2.empty()) res2.pop_back();
        reverse(res2.begin(), res2.end());
        cout << res1.size() + res2.size() << "\n";
        for(vector<pii>& vt: res1){
            sort(vt.begin(), vt.end(), [](pii& a, pii& b){return a.second < b.second; });
            for(pii& p: vt) cout << p.first << " ";
            cout << "\n";
        }
        for(vector<pii>& vt: res2){
            sort(vt.begin(), vt.end(), [](pii& a, pii& b){return a.second < b.second; });
            for(pii& p: vt) cout << p.first << " ";
            cout << "\n";
        }
    }

    void process(){
        init();
        if(u[1].first == x[1].first && u[2].first == x[2].first && u[3].first == x[3].first){
            cout << 0;
            exit(0);
        }
        res2.push_back({u[1], u[2], u[3]});
        calc(x, res1);
        calc(u, res2);
        trace();
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
