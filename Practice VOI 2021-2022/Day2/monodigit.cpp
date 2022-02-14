 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "monodigit"
#define inf 1e9
#define mod 1000000007
#define maxn 15

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

int L, n;
int a[maxn];

namespace subtask1{
    void subtask1(){
        ll res = 0;

        for(int i = 1; i <= 9; i ++){
            ll num = 0;
            for(int j = 1; j <= L; j ++){
                num = num * 10 + i;
                int cnt = 0;
                for(int t = 1; t <= n; t ++){
                    if(num % a[t] == 0) cnt ++;
                }
                if(cnt >= 2){
                    maximize(res, num);
                }
            }
        }
        if(res == 0){
            cout << "1 0";
        }
        else{
            int cnt = 0;
            int tmp = res % 10;
            while(res){
                res /= 10;
                cnt ++;
            }
            cout << cnt << " " << tmp;
        }
    }
}

namespace subtask2{
    int num[maxn];

    void subtask2(){
        int res = 0, len = 1;

        for(int i = 1; i <= 9; i ++){
            for(int j = 1; j <= n; j ++){
                num[j] = 0;
            }
            for(int j = 1; j <= L; j ++){
                int cnt = 0;
                for(int t = 1; t <= n; t ++){
                    num[t] = (num[t] * 10 + i) % a[t];
                    if(num[t] == 0) cnt ++;
                }
                if(cnt >= 2){
                    if(j == len && i > res){
                        res = i;
                    }
                    else if(j > len){
                        res = i;
                        len = j;
                    }
                }
            }
        }
        cout << len << " " << res;
    }
}

namespace process{
    void process(){
        cin >> L >> n;
        for(int i = 1; i <= n ; i++) cin >> a[i];
        if(L <= 10) return subtask1::subtask1();
        if(L <= 1000 && *max_element(a + 1, a + n + 1) <= 1000) return subtask2::subtask2();
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
