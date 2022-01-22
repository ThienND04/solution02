#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bai1"
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
    int n, m;
    int e[maxn];
    pii monHoc[maxn];
    ll totalMin[maxn];
    bool mask[maxn];

    bool cmp(pii& p1, pii& p2){
        return p1.first > p2.first;
    }

    vector<int> th[21];

    bool ok23(ll s, int x){
        for(int y: th[x]){
            ll s1 = 0;
            bool t = 1;
            for(int i = 0; i < n; i ++){
                if(bit(y, i)){
                    s1 += e[i + 1];
                    if(s + s1 < 0) t = 0;
                }
            }
            if(t) return 1;
        }
        return 0;
    }

    void subtask23(){
        for(int i = 0; i < (1 << n); i ++){
            int k = __builtin_popcount(i);
            th[k].push_back(i);
        }
        for(int i = 1; i <= m; i ++){
            ll s;
            cin >> s;
            int l = 0, r = n + 1;
            while(r - l > 1){
                int mid = (l + r) / 2;
                if(ok23(s, mid)) l = mid;
                else r = mid;
            }
            cout << l << " ";
        }
    }

    void init(){
        reset(mask); reset(totalMin);
        cin >> n >> m;
        // cerr << n;
        for(int i = 1; i <= n; i ++) {
            cin >> e[i];
            monHoc[i] = {e[i], i};
        }
        sort(monHoc + 1, monHoc + n + 1, cmp);
        for(int i = 1; i <= n; i ++){
            ll s = 0;
            for(int j = 1; j <= i; j ++) mask[monHoc[j].second] = 1;
            for(int j = 1; j <= n; j ++){
                if(mask[j]){
                    s += e[j];
                    minimize(totalMin[i], s);
                }
            }
            for(int j = 1; j <= i; j ++) mask[monHoc[j].second] = 0;
        }
    }

    bool ok(ll s, int x){
        return s + totalMin[x] >= 0;
    }

    void subtask1(){
        for(int i = 1; i <= m; i ++){
            ll s;
            cin >> s;
            int l = 0, r = n + 1;
            while(r - l > 1){
                int mid = (l + r) / 2;
                if(ok(s, mid)) l = mid;
                else r = mid;
            }
            cout << l << " ";
        }
    }

    void process(){
        init();
        if(n <= 20) return subtask23();
        return subtask1();
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
