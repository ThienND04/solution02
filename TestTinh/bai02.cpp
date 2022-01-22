#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bai02"
#define inf 1e9
#define mod 1000000007
#define maxn 2000001

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
    bool isPrime[maxn];

    void init(){
        fill(isPrime, isPrime + maxn, 1);
        isPrime[0] = isPrime[1] = 0;
        for(int i = 2; i < maxn; i ++) {
            if(isPrime[i]){
                for(ll j = 1ll * i * i; j < maxn; j += i){
                    isPrime[j] = 0;
                }
            }
        }
    }

    void process(){
        init();
        // for(int i = 0; i <= 100; i ++){
        //     cerr << i << " : " << isPrime[i] << "\n";
        // }
        cin >> n;
        int maxNum = 0, res = 0;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        for(int i = 1; i <= n; i ++){
            if(isPrime[a[i]]) maximize(maxNum, a[i]);
        }
        while(maxNum){
            res += maxNum % 10;
            maxNum /= 10;
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
