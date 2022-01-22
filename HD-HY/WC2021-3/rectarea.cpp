#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "rectarea"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

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

struct edge{
    int l, r, y, t;
};

bool cmp(edge& a, edge& b){
    return a.y < b.y;
}

namespace process{
    int n;
    vector<int> vt;
    vector<edge>adj;

    int t[8 * maxn], delta[8 * maxn];

    void push(int id, int l, int r){
        if(delta[id]) t[id] = vt[r - 1] - vt[l - 1];
        else if(l + 1 >= r) t[id] = 0;
        else t[id] = t[id * 2] + t[id * 2 + 1];
    }

    void update(int id, int l, int r, int u, int v, int d){
        if(u <= l && r <= v){
            delta[id] += d;
            push(id, l, r);
            return;
        }
        int mid = (l + r) / 2;
        // delta[id * 2] += delta[id];
        // delta[id * 2 + 1] += delta[id];
        // delta[id] = 0;
        if(u < mid) update(id * 2, l, mid, u, v, d);
        if(v > mid) update(id * 2 + 1, mid, r, u, v, d);
        push(id, l, r);
    }
    
    void init(){
        cin >> n;
        for(int i = 1; i <= n; i ++){
            int x1, x2, y1, y2;
            cin >> x1 >>  y1 >> x2 >> y2;
            vt.push_back(x1);
            vt.push_back(x2);
            adj.push_back({x1, x2, y1, 1});
            adj.push_back({x1, x2, y2, -1});
        }
        sort(vt.begin(), vt.end());
        // vt.erase(unique(vt.begin(), vt.end()), vt.end());
        vt.resize(unique(vt.begin(), vt.end()) - vt.begin());
        // for(int i : vt) cerr << i << " ";
        for(edge& e: adj){
            e.l = lower_bound(vt.begin(), vt.end(), e.l) - vt.begin() + 1;
            e.r = lower_bound(vt.begin(), vt.end(), e.r) - vt.begin() + 1;
        }
        sort(adj.begin(), adj.end(), cmp);
    }

    void process(){
        init();
        ll res = 0;
        for(int i = 0; i < adj.size() - 1; i ++){
            update(1, 1, adj.size(), adj[i].l, adj[i].r, adj[i].t);
            res += 1ll * t[1] * (adj[i + 1].y - adj[i].y);
        }
        cout << res;
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
