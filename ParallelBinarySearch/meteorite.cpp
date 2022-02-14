#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "meteorite"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

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

struct rain{
    int l, r, c;
};

namespace process{
    int m, n, k;
    int p[maxn], w[maxn], L[maxn], R[maxn];
    vector<int> child[maxn];
    rain days[maxn];

    vector<int> gr[maxn];

    BIT cnt;

    void solve(){
        cnt = BIT(m + 1);
        reset(L);
        for(int i = 1; i <= n; i ++) R[i] = k + 1;

        for(int loop = log2(k) + 3; loop >= 0; loop --){
            cnt.Reset();
            for(int i = 1; i <= n; i ++){
                if(R[i] - L[i] > 1) gr[(L[i] + R[i]) / 2].push_back(i);
            }
            for(int i = 1; i <= k; i ++){
                int l = days[i].l, r = days[i].r, c = days[i].c;
                if(l > r) {
                    cnt.update(l, m, c);
                    cnt.update(1, r, c);
                }
                else cnt.update(l, r, c);
                for(int t: gr[i]){
                    ll sum = 0;
                    for(int ch: child[t]){
                        sum += cnt.get(ch);
                    }   
                    if(sum >= w[t]) R[t] = i;
                    else L[t] = i;
                }
                gr[i].clear();
            }
        }
        for(int i = 1; i <= n; i ++){
            if(R[i] == k + 1) cout << -1 << "\n";
            else cout << R[i] << "\n";
        }
    }   

    void process(){
        cin >> n >> m;
        for(int i = 1; i <= m; i ++) {
            cin >> p[i];
            child[p[i]].push_back(i);
        }
        for(int i = 1; i <= n; i ++) cin >> w[i];
        cin >> k;
        for(int i = 1; i <= k; i ++) cin >> days[i].l >> days[i].r >> days[i].c;
        solve();
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
