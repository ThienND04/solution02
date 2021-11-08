#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "pswap"
#define inf 1e18
#define mod 1000000007
#define maxn 100001

struct BITTREE
{
    int n;
    int cnt[maxn];

    BITTREE(int _n): n(_n){
        for(int i = 0; i <= _n; i ++) cnt[i] = 0;
    }
    void update(int x, int d){
        while(x <= n){
            cnt[x] += d;
            x += x & -x;
        }
    }

    int get(int x){
        int res = 0;
        while(x){
            res += cnt[x];
            x -= x & -x;
        }
        return res;
    }
};


int n;
int p[maxn];

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> p[i];
}

ll process(){
    // if(check()) return 0;
    int maxCur = 0;
    BITTREE BIT(n);
    vector<int> ps;
    for(int i = 1; i <= n; i ++){
        maxCur = max(maxCur, p[i]);
        if(p[i] == maxCur) ps.push_back(i);
    }

    int maxPs = 0;
    int lf = 0, rt = 0;
    for(int i = 2; i <= n; i ++) {
        if(p[i] < p[i - 1]){
            lf = i - 1;
            rt = i;
        }
    }

    for(int u : ps){
        for(int v = u + 1; v < n; v ++){
            BIT.update(p[v], 1);
            if(p[v + 1] > p[u]) continue;
            int tmp = BIT.get(p[u] - 1) - BIT.get(p[v + 1] - 1);
            if(tmp > maxPs){
                maxPs = tmp;
                lf = u, rt = v + 1;
            }
        }
        for(int v = u + 1; v < n; v ++){
            BIT.update(p[v], -1);
        }
    }
    // for(int i: ps) cerr << i << " ";
    // cerr << endl;
    swap(p[lf], p[rt]);
    // cerr << lf << " " << rt << endl;
    // for(int i = 1; i <= n; i ++) cerr << p[i] << " ";
    ll res = 0;
    assert(BIT.get(n) == 0);
    for(int i = n; i >= 1; i --){
        res += BIT.get(p[i] - 1);
        BIT.update(p[i], 1);
    }
    return res + 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    cout << process();
    return 0;
}