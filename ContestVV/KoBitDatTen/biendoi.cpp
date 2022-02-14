#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "biendoi"
#define inf 1e9
#define mod 1000000007
#define maxn 1001

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

int n, m, q;

struct query{
    int type, i, j;
};

query queries[100001];

namespace subtask1{
    bool check(){
        return (n <= 100 && m <= 100 && q <= 100);
    }

    int a[101][101][101];

    void subtask1(){
        reset(a);

        for(int t = 1; t <= q; t ++){
            for(int i = 1; i <= n; i ++){
                for(int j = 1; j <= m; j ++) a[t][i][j] = a[t - 1][i][j];
            }
            int i = queries[t].i, j = queries[t].j;
            if(queries[t].type == 1){
                if(a[t][i][j] == 0) a[t][i][j] = 1;
            }
            else if(queries[t].type == 2){
                if(a[t][i][j] == 1) a[t][i][j] = 0;
            }
            else if(queries[t].type == 3){
                for(j = 1; j <= m; j ++) a[t][i][j] = 1 - a[t][i][j];
            }
            else{
                for(int i1 = 1; i1 <= n; i1 ++){
                    for(int j1 = 1; j1 <= m; j1 ++) a[t][i1][j1] = a[i][i1][j1];
                }
            }

            int res = 0;
            for(i = 1; i <= n; i ++){
                for(j = 1; j <= m; j ++) if(a[t][i][j]) res ++;
            }
            cout << res << "\n";
        }
    }
}

namespace subtask2{
    bool check(){
        for(int i = 1; i <= q; i ++) {
            if(queries[i].type == 4) return 0;
        }
        return 1;
    }

    int a[maxn][maxn];

    void subtask2(){
        int res = 0;
        for(int t = 1; t <= q; t ++){
            int i = queries[t].i, j = queries[t].j;
            if(queries[t].type == 1){
                if(a[i][j] == 0) {
                    a[i][j] = 1;
                    res ++;
                }
            }
            else if(queries[t].type == 2){
                if(a[i][j] == 1) {
                    a[i][j] = 0;
                    res --;
                }
            }
            else if(queries[t].type == 3){
                for(j = 1; j <= m; j ++) {
                    a[i][j] = 1 - a[i][j];
                    if(a[i][j] == 1) res ++;
                    else res --;
                }
            }
            cout << res << "\n";
        }
    }
}

namespace process{
    void process(){
        cin >> n >> m >> q;
        for(int i = 1; i <= q; i ++){
            cin >> queries[i].type;
            if(queries[i].type <= 2) {
                cin >> queries[i].i >> queries[i].j;
            }
            else cin >> queries[i].i;
        }
        if(subtask1::check()) return subtask1::subtask1();
        if(subtask2::check()) return subtask2::subtask2();
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
