 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "houses"
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
    int a[maxn][maxn], id[maxn * maxn], num = 0;
    bool ok[maxn * maxn];
    int par[maxn * maxn];
    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

    #define ID(i, j) ((i - 1) * m + (j))

    vector<pii> lt[maxn * maxn];

    int root(int u){
        if(par[u] == u) return u;
        return (par[u] = root(par[u]));
    }

    void join(int u, int v){
        u = root(u), v = root(v);
        par[u] = v;
    }

    void xoay(pii& point){
        point = {-point.second, point.first};
    }

    int hash(const vector<pii>& ps){
        const int a = 23453;
        const int b = 12513;
        const int B = 35713;

        int hashCode = 0;

        for(pii tmp: ps){
            hashCode = (1ll * hashCode * B + 1ll * tmp.first * a + 1ll * b * tmp.second) % mod;
        }
        return hashCode;
    }

    void init(){
        reset(id);
        cin >> m >> n;
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++) cin >> a[i][j];
        }
        for(int i = 1; i <= n * m; i ++) par[i] = i;
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++) {
                if(a[i][j] == 0) continue;
                for(int t = 0; t < 4; t ++){
                    int x = i + dx[t], y = j + dy[t];
                    if(x < 1 || x > m || y < 1 || y > n) continue;
                    if(a[x][y] == 1){
                        join(ID(i, j), ID(x, y));
                    }
                }
            }
        }
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++) {
                if(a[i][j] == 0) continue;
                if(! ok[root(ID(i, j))]){
                    ok[root(ID(i, j))] = 1;
                    lt[++ num].push_back({i, j});
                    id[root(ID(i, j))] = num;
                }
                else{
                    lt[id[root(ID(i, j))]].push_back({i, j});
                }
            }
        }
    }

    void latX(pii& tmp){
        tmp.first = -tmp.first;
    }
    void chuanHoa(vector<pii>& ps){
        sort(ps.begin(), ps.end());
        pii tmp = {1 - ps[0].first, 1 - ps[0].second};
        for(int j = 0; j < ps.size(); j ++){
            ps[j].first += tmp.first;
            ps[j].second += tmp.second;
        }
    }

    int getHashCode(vector<pii>& ps){
        int res = INT_MAX;
        for(int i = 0; i < 4; i ++){
            for(pii& tmp: ps) xoay(tmp);
            chuanHoa(ps);
            minimize(res, hash(ps));
        }

        for(int i = 0; i < ps.size(); i ++) {
            pii& tmp = ps[i];
            latX(tmp);
        }

        for(int i = 0; i < 4; i ++){
            for(pii& tmp: ps) xoay(tmp);
            chuanHoa(ps);
            minimize(res, hash(ps));
        }
        return res;
    }

    set<int> st;

    void process(){
        init();
        cerr << num;
        for(int i = 1; i <= num; i ++){
            st.insert(getHashCode(lt[i]));
        }
        cout << st.size();  
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
