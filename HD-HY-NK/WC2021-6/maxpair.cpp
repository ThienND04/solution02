#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "maxpair"
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

int n;
int h[maxn];

namespace subtask1{

    void subtask1(){
        ll res = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = i + 1; j <= n; j ++){
                maximize(res, 1ll * (j - i) * (h[i] + h[j]));
            }
        }
        cout << res;
    }
}

namespace subtask2{
    bool check(){
        for(int i = 2; i <= n; i ++) {
            if(h[i] < h[i - 1]) return 0;
        }
        return 1;
    }
    void subtask2(){
        ll res = 0;
        for(int j = 1; j < n; j ++){
            maximize(res, 1ll * (n - j) * (h[n] + h[j]));
        }
        cout << res;
    }
}


namespace subtask3{
    bool check(){
        return (*max_element(h + 1, h + n + 1) <= 5000);
    }

    int L[5001], R[5001];

    void subtask3(){
        ll res = 0;
        reset(L); reset(R);
        for(int i = 1; i <= n; i ++){
            if(L[h[i]] == 0) L[h[i]] = i;
        }
        for(int i = n; i >= 0; i --){
            if(R[h[i]] == 0) R[h[i]] = i;
        }
        for(int x = 0; x <= 5000; x ++){
            if(L[x] == 0) continue;
            for(int y = 0; y <= 5000; y ++){
                if(R[y] == 0) continue;
                maximize(res, 1ll * (R[y] - L[x]) * (x + y));
            }
        }
        cout << res;
    }
}

namespace subtask4{

    int s[maxn], num = 0;

    void subtask4(){
        int mm = 0;
        for(int i = 1; i < n; i ++){
            if(mm >= h[i]) continue;
            mm = h[i];
            s[++ num] = i;
        }
        
    }
}

namespace process{
    void process(){
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> h[i];
        if(n <= 1000) return subtask1::subtask1();
        if(subtask2::check()) return subtask2::subtask2();
        if(subtask3::check()) return subtask3::subtask3();
        return subtask4::subtask4();
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
