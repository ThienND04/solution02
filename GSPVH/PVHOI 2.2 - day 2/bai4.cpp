#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bai4"
#define inf 1e9
#define mod 1000000007
#define maxn 1501

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 18
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
    bool used[maxn];
    int minDist[18][18][1 << LOG];

    void IJK(int s){
        reset(used);
        used[s] = 1;
        while(1){
            int node = -1;
            for(int u = 1; u <= n; u ++) {
                if(! used[u] && (node == -1 || d[s][u] < d[s][node])) node = u;
            }
            if(node < 0) break;
            used[node] = 1;
            for(int v = 1; v <= n; v ++){
                minimize(d[s][v], d[s][node] + d[node][v]);
            }
        }
    }

    void swapDirect(){
        for(int i = 1; i <= n; i ++){
            for(int j = i + 1; j <= n; j ++){
                swap(d[i][j], d[j][i]);
            }
        }
    }

    void prepare(){
        for(int i = 0; i < m; i ++){
            IJK(f[i]);
            
            swapDirect();
            IJK(f[i]);
            swapDirect();
        }
        
        memset(minDist, 99, sizeof(minDist));
        for(int i = 0; i < m; i ++) minDist[i][i][1 << i] = 0;
        for(int mask = 0; mask < (1 << m); mask ++){
            for(int hihi = mask; hihi > 0; hihi -= hihi & -hihi){
                for(int hjhj = mask; hjhj > 0; hjhj -= hjhj & -hjhj){
                    int i = __builtin_ctz(hihi & -hihi);
                    int j = __builtin_ctz(hjhj & -hjhj);
                    if(minDist[i][j][mask] >= inf) continue;

                    for(int hkhk = ((1 << m) - 1) ^ mask; hkhk > 0; hkhk -= hkhk & -hkhk){
                        int k = __builtin_ctz(hkhk & -hkhk);
                        minimize(minDist[i][k][mask | (1 << k)], minDist[i][j][mask] + d[f[j]][f[k]]);
                    }
                }
            }
        }
    }

    void process(){
        // cin >> n >> m >> q;
        scanf("%d%d%d", &n, &m, &q);
        // cerr << n << " " << m << " " << q;
        for(int i = 0; i < m; i ++) {
            // cin >> f[i];
            scanf("%d", &f[i]);
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                // cin >> d[i][j];
                scanf("%d", &d[i][j]);
            }
        }
        prepare();
        while(q --){
            int s, t;
            // cin >> s >> t;
            scanf("%d%d", &s, &t);
            int res = inf;
            for(int i = 0; i < m; i ++){
                for(int j = 0; j < m; j ++){
                    minimize(res, d[s][f[i]] + minDist[i][j][(1 << m) - 1] + d[f[j]][t]);
                }
            }
            // cout << res << " ";
            printf("%d ", res);
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
