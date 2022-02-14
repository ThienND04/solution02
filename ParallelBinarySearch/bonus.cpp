#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bonus"
#define inf 1e9
#define mod 1000000007
#define maxn 100002

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

int n, q;
ll a[maxn];
int b[maxn], x[maxn], t[maxn];

class BIT{
private:
    int n;
    vector<ll> s;

    void update(int x, int d){
        while(x <= n){
            s[x] += d;
            x += x & -x;
        }
    }

public:
    BIT(){} 
    BIT(int _n): n(_n){
        s.resize(n + 1);
    }

    void update(int l, int r, int d){
        update(l, d);
        update(r + 1, - d);
    }

    ll get(int x){
        ll res = 0;
        while(x){
            res += s[x];
            x -= x & -x;
        }
        return res;
    }

    void Reset(){
        fill(s.begin(), s.end(), 0);
    }
};

namespace subtask3{
    vector<int> child[maxn], gr[maxn];
    //ll money[maxn];

    int L[maxn], R[maxn], s[maxn], pos[maxn];
    int ls[maxn], cnt = 0;
    BIT stt;

    void DFS(int u){
        ls[++ cnt] = u;
        pos[u] = cnt;
        s[u] = 1;

        for(int v: child[u]){
            DFS(v);
            s[u] += s[v];
        }
    }

    void subtask3(){
        stt = BIT(n);
        reset(L);
        for(int i = 2; i <= n; i ++) child[b[i]].push_back(i);
        DFS(1);
        //for(int i = 1; i <= cnt; i ++) {
        //    cerr << ls[i] << " " << pos[ls[i]] << "\n";
        //}
        for(int i = 1; i <= n; i ++){
            R[i] = q + 1;
        }
        for(int loop = log2(q) + 3; loop >= 0; loop --){
            stt.Reset();
            for(int i = 1; i <= n; i ++){
                if(R[i] - L[i] > 1) gr[(L[i] + R[i]) / 2].push_back(i);
            }
            for(int i = 1; i <= q; i ++){
                stt.update(pos[x[i]], pos[x[i]] + s[x[i]] - 1, t[i]);
                for(int k: gr[i]){
                    if(stt.get(pos[k]) >= a[k]) R[k] = i;
                    else L[k] = i;
                }
                gr[i].clear();
            }
            // for(int i = 1; i <= n; i ++) {
            //     cerr << i << ": " << stt.get(pos[i]) << "\n";
            // }
        }
        for(int i = 1; i <= n; i ++){
            if(R[i] == q + 1) cout << -1 << "\n";
            else cout << R[i] << "\n";
        }
    }
}

namespace process{

    void process(){
        cin >> n >> q;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        b[1] = -1;
        for(int i = 2; i <= n; i ++) cin >> b[i];
        for(int i  =1;  i <= q; i ++) cin >> x[i] >> t[i];

        return subtask3::subtask3();
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