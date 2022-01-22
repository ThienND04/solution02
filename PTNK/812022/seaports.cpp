 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "seaports"
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

struct ship
{
    int s, f, port;

    friend bool operator<(const ship& a, const ship& b){
        return (a.f < b.f);
    }
};

struct even{
    // type = 1: (s
    // type = 2: f]

    int type, x;
    ship* sp;

    even(int _type, int _x, ship* _sp){
        type = _type;
        x = _x;
        sp = _sp;
    }
    bool operator< (const even& b){
        if(x != b.x) return x < b.x;
        return (type > b.type);
    }
};

// struct cmp
// {
//     bool operator() (const ship& a, const ship& b){
//     //
//         return a.f <= b.f;
//     }
// };

namespace process{
    int m, n;
    ship a[maxn];
    stack<int> ports;
    vector<even> points;

    void init(){
        cin >> m >> n;
        while(m) {
            ports.push(m);
            m --;
        }
        for(int i = 1; i <= n; i ++){
            cin >> (a[i].s) >> (a[i].f);
            a[i].port = 0;
            points.push_back({1, a[i].s, &a[i]});
            points.push_back({2, a[i].f, &a[i]});
        }
    }

    void process(){
        int res = 0;
        init();
        priority_queue<ship* > pq;
        sort(points.begin(), points.end());
        for(even& p: points){
            if(p.type == 1){
                if(ports.empty()){
                    pq.push(p.sp);
                    ship* tmp = pq.top();
                    pq.pop();
                    p.sp->port = tmp->port;
                    tmp->port = 0;
                }
                else{
                    res ++;
                    p.sp->port = ports.top();
                    ports.pop();
                    pq.push(p.sp);
                }
            }
            else{
                if(p.sp->port) ports.push(p.sp->port);
            }
        }
        cout << res << "\n";
        for(int i = 1; i <= n; i ++) cout << a[i].port << " ";
        // cerr << a[1].port << "\n";
        // pq.push(&a[1]);
        // ship* cur = pq.top();
        // cur->port = 1;
        // cerr << a[1].port << "\n";
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
