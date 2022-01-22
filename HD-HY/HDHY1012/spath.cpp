#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "spath"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

namespace caculate
{
    template <class T>
    void add(T &x, T y)
    {
        x += y;
        if (x >= mod)
            x -= mod;
    }
    template <class T>
    void sub(T &x, T y)
    {
        x -= y;
        if (x < 0)
            x += mod;
    }
    template <class T>
    void maximize(T &x, T y)
    {
        if (x < y)
            x = y;
    }
    template <class T>
    void minimize(T &x, T y)
    {
        if (x > y)
            x = y;
    }
}

using namespace caculate;


namespace process
{
    int n, m, q, num = 0;
    vector<int> uadj[maxn];
    int level[maxn], tp[maxn];
    int unvisited[maxn], d[maxn];
    int dist[maxn][maxn];

    void prepare(){
        memset(dist, -1, sizeof(dist));
        reset(d);
        for (int i = 0; i < n; i++)
        {
            if (!tp[i])
                continue;
            queue<int> qe;
            qe.push(i);
            dist[tp[i]][i] = 0;
            int cnt = n;
            for (int j = 1; j <= n; j++)
                unvisited[j] = j - 1;
            swap(unvisited[i + 1], unvisited[n]);
            cnt--;

            while (! qe.empty()){
                int u = qe.front();
                qe.pop();
                for(int y: uadj[u]){
                    d[y] = 1;
                }
                for(int j = cnt; j >= 1; j --){
                    int v = unvisited[j];
                    if(! d[v]) {
                        dist[tp[i]][v] = dist[tp[i]][u] + 1;
                        qe.push(v);
                        swap(unvisited[j], unvisited[cnt]);
                        cnt --;
                    }
                }
                for (int y : uadj[u])
                {
                    d[y] = 0;
                }
            }
        }
    }

    void init(){
        cin >> n >> m;
        // assert(n <= 700);
        for (int i = 0; i < n; i++)
            level[i] = n - 1;
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            // assert(find(uadj[u].begin(), uadj[u].end(), v) == uadj[u].end());
            uadj[u].push_back(v);
            level[u]--;
            // assert(find(uadj[v].begin(), uadj[v].end(), u) == uadj[v].end());
            uadj[v].push_back(u);
            level[v]--;
        }
        for (int i = 0; i < n; i++)
        {
            if (level[i] < n / 2)
            {
                tp[i] = ++num;
            }
            else
            {
                tp[i] = 0;
            }
            sort(uadj[i].begin(), uadj[i].end());
        }
    }

    void process()
    {
        init();
        prepare();
        cin >> q;
        while(q --){
            int x, y;
            cin >> x >> y;
            if(level[x] > level[y]) swap(x, y);
            if(level[x] < n / 2){
                cout << dist[tp[x]][y] << "\n";
            }
            else if(x == y){
                cout << 0 << "\n";
            }
            else{
                // assert(0);
                int tmp = lower_bound(uadj[x].begin(), uadj[x].end(), y) - uadj[x].begin();
                if(tmp < uadj[x].size() && uadj[x][tmp] == y) cout << 2 << "\n";
                else cout << 1 << "\n";
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
