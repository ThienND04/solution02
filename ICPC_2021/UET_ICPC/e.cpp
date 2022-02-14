#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "e"
#define inf 1e9
#define mod 1000000007
#define maxn 200001

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

namespace process{
    int n;
    int p[maxn], a[maxn];
    ll s[maxn][2];

    vector<int> child[maxn];


    void DFS(int u){
        ll f[2][2];
        f[0][1] = f[1][1] = -(1e18);
        f[0][0] = f[1][0] = 0;

        for(int i = 1; i <= child[u].size(); i ++){
            int v = child[u][i - 1];
            DFS(v);
            maximize(f[1][1], max(f[0][0] + s[v][1], f[0][1] + s[v][0]));
            maximize(f[1][0], max(f[0][0] + s[v][0], f[0][1] + s[v][1]));

            f[0][1] = f[1][1];
            f[0][0] = f[1][0];
        }
        s[u][1] = max(a[u] + f[1][0], f[1][1]);
        s[u][0] = f[1][0];
    }

    void process(){
        cin >> n;
        for(int i = 1; i <= n; i ++){
            cin >> p[i] >> a[i];
        }
        for(int i = 2; i <= n; i ++){
            child[p[i]].push_back(i);
        }
        DFS(1);
        //DFS(4);
        cout << max(s[1][0], s[1][1]);
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
