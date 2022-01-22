 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bai04"
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
    int n;
    int a[maxn];
    ll res = 0;

    void sub1(){
        for(int i = 1; i <= n; i ++){
            int minVal = a[i], maxVal = a[i];
            for(int j = i; j <= n; j ++){
                minimize(minVal, a[j]);
                maximize(maxVal, a[j]);
                if((maxVal - minVal) % 2 == 0) res ++;
            }
        }
        cout << res;
    }

    void sub2(){
        int lastPos1 = 0, lastPos2 = 0, lastPos3 = 0;
        for(int i = 1; i <= n; i ++){
            if(a[i] == 3){
                if(lastPos1 < lastPos2) {
                    res += i - lastPos2;
                    res += lastPos1;
                }
                else{
                    res += i;
                }
                lastPos3 = i;
            }
            else if(a[i] == 1){
                if(lastPos3 < lastPos2){
                    res += i - lastPos2;
                    res += lastPos3;
                }
                else {
                    res += i;
                }
                lastPos1 = i;
            }
            else {
                res += i - max(lastPos3, lastPos1);
                res += min(lastPos1, lastPos3);
                lastPos2 = i;
            }
        }
        cout << res;
    }

    void process(){
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        if(n <= 10000) return sub1();
        return sub2();
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
