#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bieudo"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

#define maxbit 22

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


int n, h[maxn];
ll p;

namespace subtask1{
    void subtask1(){
        ll res = 0;
        for(int l = 1; l <= n; l ++){
            int minH = inf;
            for(int r = l; r <= n; r ++){
                minimize(minH, h[r]);
                ll x = p / (r - l + 1);
                if(x * (r - l + 1) < p) x ++;
                if(x <= minH) res += minH - x  + 1;
            }
        }
        cout << res;
    }
}

namespace subtask2{
    bool check(){
        return (n <= 100000 && p <= 1e8 && *max_element(h + 1, h + n + 1) <= 1000);
    }

    int t[1001];

    void subtask2(){
        ll res = 0;
        reset(t);
        for(int i = 1; i <= n; i ++){
            for(int x = 1; x <= 1000; x ++){
                if(x > h[i]) t[x] = i;
                int d = p / x;
                if(d * x < p) d ++;
                int tmp = t[x];
                if(tmp >= i) continue;
                if(i - tmp < d) continue;
                res += i - tmp - d + 1;
            }
        }
        cout << res;
    }
}

namespace subtask3{
    bool check(){
        return (p == 1 && *max_element(h + 1, h + n + 1) <= 1e9);
    }

    void subtask3(){
        for(int i = 1; i <= n; i ++){
            
        }
    }
}

namespace process{
    void process(){
        cin >> n >> p;
        for(int i = 1; i <= n;  i++) cin >> h[i];
        if(n <= 3000) return subtask1::subtask1();
        if(subtask2::check()) return subtask2::subtask2();
        if(subtask3::check()) return subtask3::subtask3();
        assert(0);
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