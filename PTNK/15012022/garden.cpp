#include <bits/stdc++.h>

using namespace std;

typedef pair<long double, long double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "garden"
#define inf 1e9
#define mod 1000000007
#define maxn 10001
#define double long double

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
    int n;
    vector<int> ke[maxn], adj[maxn];
    map<pii, int> edge, id;
    pdd positive[maxn];
    double area[maxn], total = 0;

    double dist(const pdd& p1, const pdd& p2){
        double dx = p1.first - p2.first,
            dy = p1.second - p2.second;

        return sqrt(dx * dx + dy * dy);
    }

    double calcArea(const pdd& p1, const pdd& p2, const pdd& p3){
        double d1 = dist(p1, p2), d2 = dist(p1, p3), d3 = dist(p2, p3);
        double p = (d1 + d2 + d3) / 2;
        double res = sqrt(p * (p - d1) * (p - d2) * (p - d3));
        return res;
    }

    void init(){
        cin >> n;
        for(int i = 1; i <= n - 3; i ++){
            int u, v;
            cin >> u >> v;
            if(u > v) swap(u, v);
            edge[{u, v}] = 1;
            ke[u].push_back(v);
            ke[v].push_back(u);
        }
        for(int i = 0; i < n; i ++) {
            ke[i].push_back((i + 1) % n);
            ke[i].push_back((i - 1 + n) % n);
        }
        for(int i = 0; i < n - 1; i ++) edge[{i, i + 1}] = 1;
        for(int i = 0; i < n; i ++) sort(ke[i].begin(), ke[i].end());

        double alpha = 2.0 * M_PI / n;
        for(int i = 0; i < n; i ++){
            positive[i].first = cos(alpha * i);
            positive[i].second = sin(alpha * i);
        }
    }

    void initGraph(){
        int num = 0;
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < ke[i].size() - 1; j ++){
                int u = ke[i][j], v = ke[i][j + 1];
                if(u <= i) continue;
                ++ num;
                int c1 = id[{i, u}], c2 = id[{i, v}], c3 = id[{u, v}];
                if(c1 != 0){
                    adj[num].push_back(c1);
                    adj[c1].push_back(num);
                }
                if(c2 != 0){
                    adj[num].push_back(c2);
                    adj[c2].push_back(num);
                }
                if(c3 != 0){
                    adj[num].push_back(c3);
                    adj[c3].push_back(num);
                }
                area[num] = calcArea(positive[i], positive[u], positive[v]);
                total += area[num];
                id[{i, u}] = num;
                id[{i, v}] = num;
                id[{u, v}] = num;
            }
        }
    }

    int par[maxn];
    double s[2][maxn];

    void DFS(int u){
        s[1][u] = area[u];
        for(int v: adj[u]){
            if(par[v]) continue;
            par[v] = u;
            DFS(v);
            s[0][u] += max(s[0][v], s[1][v]);
            for(int v2: adj[v]){
                if(v2 != u){
                    s[1][u] += max(s[0][v2], s[1][v2]);
                }
            }
        }
    }

    void process(){
        // pdd p1 = {0, 0}, p2 = {1, 0}, p3 = {0, 1};
        // cerr << calcArea(p1, p2, p3);
        reset(par);
        reset(s);
        init();
        initGraph();
        par[1] = -1;
        DFS(1);
        cout << fixed << setprecision(6) << max(s[0][1], s[1][1]) / total;
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
