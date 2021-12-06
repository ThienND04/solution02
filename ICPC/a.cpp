#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "a"
#define inf 1e9
#define mod 1000000007
#define maxn 1001

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
    int T, n;
    int c[maxn][maxn], flow[maxn][maxn];
    int res[maxn], par[maxn];

    bool findPath(int s, int t){
        queue<int> q;
        q.push(s);
        while(! q.empty()){
            int u = q.front();
            q.pop();
            for(int i = 1; i <= n; i ++){
                if(c[u][i] - flow[u][i] > 0) {
                    
                }
            }
        }
    }

    int maxFlow(int u, int v){

    }

    void calc(int start){
        for(int j = 1; j <= n; j ++){

        }
    }

    void process(){
        cin >> T;
        for(int t = 1; t <= T; t ++){
            cout << "Case #" << t << "\n";
            cin >> n;
            for(int i = 1; i <= n; i ++){
                for(int j = 1; j <= n; j ++) cin >> c[i][j];
            }
            for(int i = 1; i <= n; i ++){
                reset(res);
                for(int x = 1; x <= n; x ++){
                    for(int y = 1; y <= n; y ++) flow[x][y] = 0;
                }
                calc(i);
                res[i] = 0;
                for(int j = 1; j <= n; j ++) cout << res[j] << " ";
                cout << "\n";
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
