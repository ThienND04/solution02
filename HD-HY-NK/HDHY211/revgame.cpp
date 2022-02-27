#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "revgame"
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
    int m, n;
    int a[maxn][maxn], color[maxn];
    vector<int> sameAdj[maxn], diffAdj[maxn];
    bool diff[maxn][maxn], same[maxn][maxn];

    void init(){
        cin >> m >> n;
        memset(color, -1, sizeof(color));
        reset(same); reset(diff);
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                cin >> a[i][j];
            }
        }
        map<int, int> pre[maxn];
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                int v1 = pre[j][a[i][j]], v2 = pre[n - j + 1][a[i][j]];
                if(v1 == -1 || v2 == -1){
                    cout << -1;
                    exit(0);
                }
                if(v1 != 0){
                    diff[v1][i] = 1;
                    diff[i][v1] = 1;
                }   
                if(v2 != 0){
                    same[i][v2] = 1;
                    same[v2][i] = 1;
                }
            }
            for(int j = 1; j <= n; j ++){
                if(pre[j][a[i][j]] == 0) pre[j][a[i][j]] = i;
                else pre[j][a[i][j]] = -1;
            }
        }
        for(int i = 1; i <= m; i ++){
            sameAdj[i].reserve(m);
            diffAdj[i].reserve(m);
            for(int j = 1; j <= m; j ++){
                if(same[i][j]) sameAdj[i].push_back(j);
                if(diff[i][j]) diffAdj[i].push_back(j);
            }
        }
    }

    void DFS(int u){
        for(int v: sameAdj[u]){
            if(color[v] == -1){
                color[v] = color[u];
                DFS(v);
            }
            else if(color[v] != color[u]){
                cout << -1;
                exit(0);
            }
        }
        for(int v: diffAdj[u]){
            if(color[v] == -1){
                color[v] = 1 - color[u];
                DFS(v);
            }
            else if(color[v] == color[u]){
                cout << -1;
                exit(0);
            }
        }
    }

    void process(){
        init();
        for(int i = 1; i <= m; i ++){
            if(color[i] == -1) {
                color[i] = 0;
                DFS(i);
            }
        }
        int cnt = 0;
        for(int i = 1; i <= m; i ++){
            cnt += color[i];
        }
        cout << cnt << "\n";
        for(int i = 1; i <= m; i ++){
            if(color[i]) cout << i << " ";
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
