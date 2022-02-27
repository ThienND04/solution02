#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "majval"
#define inf 1e9
#define mod 1000000007
#define maxn 500501

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
    int a[maxn];
    int BIT[maxn];

    void init(){
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        vector<int> b(n);
        for(int i = 1; i <= n; i ++) b[i - 1] = a[i];
        sort(b.begin(), b.end());
        for(int i = 1; i <= n; i ++){
            a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        }

        // for(int i = 1; i <= n; i ++) cerr << a[i] << " ";
    }

    void Update(int x, int d){
        while(x < maxn){
            BIT[x] += d;
            x += x & -x;
        }
    }

    int Get(int x){
        int res = 0;
        for(; x > 0; x -= x & -x){
            res += BIT[x];
        }
        return res;
    }

    void process(){
        init();

        ll res = 0;
        for(int x = 1; x <= n; x ++){
            reset(BIT);
            Update(n + 1, 1);
            int cnt = 0;
            for(int i = 1; i <= n; i ++){
                if(a[i] == x) cnt ++;
                res += Get(cnt * 2 - i + n);
                Update(cnt * 2 - i + n + 1, 1);
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
