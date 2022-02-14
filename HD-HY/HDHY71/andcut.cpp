#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "andcut"
#define inf 1e9
#define mod 1000000007
#define maxn 2001

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
    int m, n, q;
    bool mask[maxn][maxn];

    int Query(int x, int y, int u, int v){
        int res = 0;
        res += (mask[x][y] == 0);
		for(int j = y + 1; j <= v; ++ j) {
			if(mask[x][j] == 0 && mask[x][j] != mask[x][j - 1]) ++ res;
		}
		res += (mask[x][y] == 0);
		for(int i = x + 1; i <= u; ++ i) {
			if(mask[i][y] == 0 && mask[i][y] != mask[i - 1][y]) ++ res;
		}
		res -= (mask[x][y] == 0);
		return res;
    }

    void process(){
        cin >> m >> n >> q;
        int num = 0;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                mask[i][j] = (i & j) > 0;
            }
        }
        while(q --){
            int x, y, u, v;
            cin >> x >> y >> u >> v;
            cout << Query(x ,y, u, v) << "\n";
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