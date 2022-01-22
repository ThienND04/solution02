#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "exam"
#define inf 1e9
#define mod 1000000007
#define maxn 1000001

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
    int a[maxn], b[maxn];
    int need[maxn], remain[maxn];

    bool check(int x){
        for(int i = 1; i <= n; i ++){
            need[i] = a[i];
            remain[i] = b[i];
        }

        int j = 1;
        for(int i = 1; i <= n; i ++){
            while(need[i] > 0){
                while(j <= n && abs(i - j) > x) j ++;
                while(j <= n && remain[j] == 0) j ++;
                if(j > n || abs(i - j) > x) return 0;
                int tmp = min(need[i], remain[j]);
                need[i] -= tmp;
                remain[j] -= tmp;
            }
        }
        return 1;
    }

    void process(){
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        for(int i = 1; i <= n; i ++) cin >> b[i];
        int l = -1, r = n + 1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        if(! check(r)) cout << -1;
        else cout << r;
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
