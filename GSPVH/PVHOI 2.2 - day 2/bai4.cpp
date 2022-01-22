#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bai4"
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
    int n, m, q;
    int d[maxn][maxn], f[maxn];
    bool special[maxn];

    void IJK(int s){
        priority_queue<pii> qe;
        qe.push({0, s});
        while(! qe.empty()){
            int l = -qe.top().first, u = qe.top().second;
            qe.pop();
            if(d[s][u] != l) continue;
            for(int i = 1; i <= n; i ++){
                if(d[s][u] + d[u][i] < d[s][i]){
                    d[s][i] = d[s][u] + d[u][i];
                    qe.push({- d[s][i], i});
                }
            }
        }
    }

    bool checkSub1(){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(i != j && d[i][j] != 1) return 0;
            }
        }
        return 1;
    }
    void subtask1(){
        while(q --){
            int s, t;
            cin >> s >> t;
            cout << m + (special[s] == 0) + (special[t] == 0) << "\n";
        }
    }

    void subtask2(){
        IJK(f[1]);
        while(q --){
            int s, t;
            cin >> s >> t;
            cout << d[f[1]][s] + d[f[1]][t] << "\n";
        }
    }

    int dp[18][18][1 << 17];

    // void full(){
    //     memset(dp, -1, sizeof(dp));
    //     for(int i = 1; i <= m; i ++) IJK(f[i]);
    //     for(int i = 1; i <= m; i --){
    //         dp[i][i][1 << (i - 1)] = 0;
    //     }
    //     for(int x = 1; x < (1 << m); x ++){
    //         if(__builtin_popcount(x) == 1) continue;
    //         for(int l = 1; l <= m; l ++){
    //             if(! bit(x, l - 1)) continue;
    //             for(int j = 1; j <= m; j ++){
    //                 if(! bit(x, j - 1)) continue;
    //                 for(int k = 1; k <= m; k ++){
    //                     if(k != l && )
    //                 }
    //             }
    //         }
    //     }
    //     while(q --){

    //     }
    // }

    void process(){
        reset(special);
        cin >> n >> m >> q;
        for(int i = 1; i <= m; i ++) {
            cin >> f[i];
            special[f[i]] = 1;
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                cin >> d[i][j];
            }
        }
        if(checkSub1()) return subtask1();
        if(m == 1) return subtask2();
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
