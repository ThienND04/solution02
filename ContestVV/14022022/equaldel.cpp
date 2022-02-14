#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "equaldel"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

#define maxbit 1024

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

int t, n;
int a[maxn];

namespace subtask1{
    int res = -1;

    void Try1(int pos, int cnt){
        if(pos > n){
            if(res == -1 || res > cnt) res = cnt;
            return;
        }
        for(int i = pos + 1; i <= n; i ++){
            if(a[i] != a[pos]) continue;
            if(i + 1 > n || a[i + 1] > a[pos]){
                Try1(i + 1, cnt + 1);
            }
        }
        if(pos + 1 > n || a[pos + 1] > a[pos]){
            Try1(pos + 1, cnt);
        }
    }

    void Try2(int pos, int cnt){
        if(pos > n){
            if(res == -1 || res > cnt) res = cnt;
            return;
        }
        for(int i = pos + 1; i <= n; i ++){
            if(a[i] != a[pos]) continue;
            if(i + 1 > n || a[i + 1] < a[pos]){
                Try1(i + 1, cnt + 1);
            }
        }
        if(pos + 1 > n || a[pos + 1] < a[pos]){
            Try1(pos + 1, cnt);
        }
    }

    void subtask1(){
        res = -1;
        Try1(1, 0);
        Try2(1, 0);
        cout << res << "\n";
    }
}

namespace subtask2{
    int fl[1005], ft[1005];
    // lf: tang dan
    // ft: giam dan

    void subtask2(){
        memset(fl, -1, sizeof(fl));
        memset(ft, -1, sizeof(ft));

        fl[1] = ft[1] = 0;

        for(int i = 2; i <= n;  i++){
            if(fl[i - 1] != -1 && a[i] > a[i - 1]) {
                if(fl[i] == -1 || fl[i] > fl[i - 1]) fl[i] = fl[i - 1];
            }
            for(int j = 1; j < i; j ++){
                if(fl[j] == -1 || a[j] != a[i]) continue;
                if(i + 1 > n || a[i + 1] > a[j]) {
                    if(fl[i + 1] == -1 || fl[i + 1] > fl[j] + 1) {
                        fl[i + 1] = fl[j] + 1;
                    }
                }
            }
        }
        if(fl[n] != -1) {
            if(fl[n + 1] == -1 || fl[n + 1] > fl[n]) fl[n + 1] = fl[n];
        }

        for(int i = 2; i <= n;  i++){
            if(ft[i - 1] != -1 && a[i] < a[i - 1]) {
                if(ft[i] == -1 || ft[i] > ft[i - 1]) ft[i] = ft[i - 1];
            }
            for(int j = 1; j < i; j ++){
                if(ft[j] == -1 || a[j] != a[i]) continue;
                if(i + 1 > n || a[i + 1] > a[j]) {
                    if(ft[i + 1] == -1 || ft[i + 1] > ft[j] + 1) {
                        ft[i + 1] = ft[j] + 1;
                    }
                }
            }
        }
        if(ft[n] != -1) {
            if(ft[n + 1] == -1 || ft[n + 1] > ft[n]) ft[n + 1] = ft[n];
        }
        cerr << fl[n + 1] << " " << ft[n + 1] << "\n";
        if(fl[n + 1] == -1) cout << ft[n + 1] << "\n";
        else if(ft[n + 1] == -1) cout << fl[n + 1] << "\n";
        else cout << min(fl[n + 1], ft[n + 1]) << "\n";
    }
}

namespace process{
    void process(){
        cin >> t;
        while(t --){
            cin >> n;
            for(int i = 1; i <= n; i ++) cin >> a[i];
            if(n <= 10) subtask1::subtask1();
            else if(n <= 1000) subtask2::subtask2();
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
