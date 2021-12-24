#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "l"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 31
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
    int cnt[LOG][2];
    string s;

    void process(){
        cin >> n;
        reset(cnt);
        for(int i = 1; i <= n; i ++) cin >> a[i];
        cin >> s;
        ll res = 0;
        for(int i = 1; i <= n; i ++){
            res += a[i];
            for(int t = 0; t < LOG; t ++){
                cnt[t][bit(a[i], t)] ++;
            }
        }
        for(char step: s){
            int sub = step - '0';
            for(int t = LOG - 1; t > 0; t --){
                if(cnt[t][sub] != cnt[t - 1][0] + cnt[t - 1][1] - cnt[t][! sub]){
                    if(sub == 1){
                        res -= cnt[t][sub];
                        cnt[t][! sub] += cnt[t][sub];
                        cnt[t][sub] = 0;
                    }
                    else{
                        res -= 
                        cnt[t][sub] = 0;
                    }
                }
            }
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
