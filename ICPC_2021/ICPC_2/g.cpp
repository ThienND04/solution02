#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "g"
#define inf 1e9
#define mod 1000000007
#define maxn 500001

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

struct ST
{
    int n;
    vector<int> lazySum, s, a;

    void build(int node, int lf, int rt){
        if(lf == rt){
            s[node] = a[lf];
            return;
        }
        int mid = (lf + rt) / 2;
        build(node * 2, lf, mid);
        build(node * 2 + 1, mid + 1, rt);
    }

    ST(const string& _s){
        n = _s.size();
        lazySum.resize(4 * n);
        s.resize(4 * n);
        a.resize(n);

        n --;
        for (int i = 1; i <= n; i++)
            a[i] = _s[i] - 'A';
        build(1, 1, n);
    }

    void lazyUpdate(int node, int lf, int rt){
        if(lf == rt){
            a[lf] = (a[lf] + lazySum[node]) % 26;
            lazySum[node] = 0;
            return;
        }
        int mid = (lf + rt) / 2;
        lazySum[node * 2] += lazySum[node];
        lazyUpdate(node * 2, lf, mid);
        lazySum[node * 2 + 1] += lazySum[node];
        lazyUpdate(node * 2 + 1, mid + 1, rt);
        lazySum[node] = 0;
    }

    void __update(int node, int lf, int rt, int u, int v, int d){
        if(lf > v || rt < u) return;
        if(lf >= u && rt <= v){
            lazySum[node] += d;
            return;
        }
        int mid = (lf + rt) / 2;
        __update(node * 2, lf, mid, u, v, d);
        __update(node * 2 + 1, mid + 1, rt, u, v, d);
    }

    void update(int lf, int rt, int d){
        __update(1, 1, n, lf, rt, d);
    }
    
    void print(){
        lazyUpdate(1, 1, n);
        for(int i = 1; i <= n; i ++) cout << char(a[i] + 'A');
    }
};


namespace process
{
    string s;
    int k;

    void process()
    {
        cin >> s >> k;
        s = " " + s;
        ST st(s);
        while(k --){
            int n, lf, rt;
            cin >> n >> lf >> rt;
            st.update(lf, rt, n);
        }
        st.print();
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
