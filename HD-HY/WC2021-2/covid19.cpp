#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "covid19"
#define inf 1e9
#define mod 1000000007
#define maxn 40

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
    int n, m;
    int cnt = 0;
    int a[maxn], b[maxn];

    void init(){
        cin >> n >> m;
        int tmp = 0;
        reset(a);
        reset(b);

        for(int i = 2; i * i <= n; i ++){
            if(n % i == 0){
                if(m % i != 0) {
                    while(n % i == 0) {
                        n /= i;
                        cnt ++;
                    }
                }
                else {
                    ++ tmp;
                    while(n % i == 0) {
                        n /= i;
                        a[tmp] ++;
                    }
                    while(m % i == 0){
                        m /= i;
                        b[tmp] ++;
                    }
                }
            }
        }
        if(n != 1){
            if(m % n != 0) cnt ++;
            else {
                tmp ++;
                a[tmp] = 1;
                while(m % n == 0){
                    b[tmp] ++;
                    m /= n;
                }
            }
        }
        assert(m == 1);
        n = tmp;
    }

    bool check(int maxMul){
        for(int i = 1; i <= n; i ++){
            if(a[i] * (1 << maxMul) < b[i]) return 0;
        }
        return 1;
    }

    void process(){
        init();
        // for(int i = 1; i <= n; i ++) cerr << a[i] << " ";
        // cerr << "\n";
        // for(int i = 1; i <= n; i ++) cerr << b[i] << " ";

        int maxMul = 0;

        while(! check(maxMul)){
            maxMul ++;
        }

        // cerr << maxMul;

        for(int i = maxMul; i >= 1; i --){
            for(int j = 1; j <= n; j ++){
                while(a[j] > 1 && (a[j] - 1) * (1 << i) >= b[j]) {
                    a[j] --;
                    cnt ++;
                }
            }
            for(int j = 1; j <= n; j ++) a[j] <<= 1;
            cnt ++;
        }
        for(int j = 1; j <= n; j ++) cnt += a[j] - b[j];
        cout << cnt;
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
