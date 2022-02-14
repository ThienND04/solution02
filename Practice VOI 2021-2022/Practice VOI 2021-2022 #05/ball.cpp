#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "ball"
#define inf 1e9
#define mod 2021
#define maxn 1001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

#define maxVal(s) (s.empty() ? 0 : *s.rbegin())

template<class T>
void maximize(T& x, T y){
    if(x < y) x = y;
}

int p, m, n, k;
string s[maxn];
int starts[maxn], targets[maxn], cost[maxn][11];

namespace subtask1{

    int f[22][11];

    bool calc(){
        for(int i = 1; i <= n; i ++) f[m + 1][i] = i;

        for(int i = m; i >= 1; i --){
            for(int j = 1; j <= n; j ++){
                if(s[i][j] == '/'){
                    if(j == 1 || s[i][j - 1] == '\\') f[i][j] = -1;
                    else f[i][j] = f[i + 1][j - 1];
                }
                else{
                    if(j == n || s[i][j + 1] == '/') f[i][j] = -1;
                    else f[i][j] = f[i + 1][j + 1];
                }
            }
        }
        for(int i = 1; i <= k; i ++){
            if(f[1][starts[i]] != targets[i]) return 0;
        }
        return 1;
    }

    void subtask1(){
        ll res = 1e18;
        for(int x = 0; x < (1 << (m * n)); x ++){
            ll totalCosts = 0;

            // if(x == 8192){
            //     cerr << x << "\n";
            //     for(int i = 1; i <= m; i ++){
            //         cerr << s[i] << "\n";
            //     }
            // }

            for(int i = 1; i <= m; i ++){
                for(int j = 1; j <= n; j ++){
                    if(bit(x, (i - 1) * n + j - 1)){
                        totalCosts += cost[i][j];
                        if(s[i][j] == '/') s[i][j] = '\\';
                        else if(s[i][j] == '\\') s[i][j] = '/';
                    }
                }
            }

            if(calc()) {
                res = min(res, totalCosts);
            }

            for(int i = 1; i <= m; i ++){
                for(int j = 1; j <= n; j ++){
                    if(bit(x, (i - 1) * n + j - 1)){
                        totalCosts += cost[i][j];
                        if(s[i][j] == '/') s[i][j] = '\\';
                        else if(s[i][j] == '\\') s[i][j] = '/';
                    }
                }
            }
        }
        cout << res;
    }
}

namespace subtask2{
    ll f[2][11][11];

    void subtask2(){
        int cnt = 0;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) f[(p * m + 1) & 1][i][j] = inf;
            f[(p * m + 1) & 1][i][i] = 0;
        }
        for(int i = p * m + 1; i >= 1; i --){
            for(int j = 1; j <= n; j ++){
                int x = (i - 1) % n + 1;
                int t1 = (s[x][j] == '/' ? 0 : cost[x][j]);
                int t2 = (s[x][j] == '\\' ? 0 : cost[x][j]);

                if(j == 1) f[i & 1][j][0] = t1;
                
            }
        }
        
    }
}

void process(){
    cin >> p >> m >> n;
    //cerr << p << " " << m << " " << n << " " << k << "\n";

    for(int i = 1; i <= m; i ++){
        cin >> s[i];
        s[i] = " " + s[i];
        //cerr << s[i] << "\n";
    }
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++) cin >> cost[i][j];
    }
    cin >> k;
    for(int i = 1; i <= k; i ++) cin >> starts[i];
    for(int i = 1; i <= k; i ++) cin >> targets[i];

    if(p == 1 && n * m <= 20) return subtask1::subtask1();
    if(p <= 10 && k <= 1) return subtask2::subtask2();
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
    process();
    return 0;
}