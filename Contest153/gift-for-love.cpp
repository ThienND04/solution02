#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "gift-for-love"
#define inf 1e9
#define mod 1000000007
#define maxn 300300

#define bit(x, i) ((x >> i) & 1)

int subtask, n, m, q, seed, cnt = 0;
vector<int> adj[maxn];
int par[maxn];
int node[2 * maxn];
int hight[maxn];
int lg2[2 * maxn], pow2[20];
int pos[maxn], dp[2 * maxn][20];

int getRandom() {
    seed = (1997LL * seed + 227) % 1000003;
    return seed;
}

#define minHight(u, v) (hight[u] < hight[v]? u: v)

int lca(int l, int r){
    l = pos[l];
    r = pos[r];
    if(l > r) swap(l, r);
    int delta = r - l + 1;
    int pg = pow2[lg2[delta]];
    // if(l - 1 < 0 || r - pg < 0) {
    //     exit(-1);
    // }
    int ans = minHight(dp[l - 1][lg2[delta]], dp[r - pg][lg2[delta]]);
    return ans;
}

int answer(int z, int l, int s){
    if (z == l || l == s || s == z) return 22071997;

    int u = lca(z, l);
    if(lca(s, u) != u) return u;

    int x = lca(z, s);
    int y = lca(l, s);
    return (hight[x] > hight[y] ? x : y);
}

void output(){
    int res = 0;
    cin >> q >> seed;
    for (int i = 1; i <= q; i++) {
        int z = getRandom() % n + 1;
        int l = getRandom() % n + 1;
        int s = getRandom() % n + 1;

        int x  = answer(z, l, s);

        res = ((1LL * res << 30) ^ x) % 998244353;
    }   
    // res = 140294767;
    cout << res << endl;
}

void DFS(int u){
    node[++ cnt] = u;
    pos[u] = cnt;
    for(int v: adj[u]) {
        if(v == par[u]) continue;
        par[v] = u;
        hight[v] = hight[u] + 1;
        DFS(v);
        node[++ cnt] = u;
    }
}

void init(){
    cin >> subtask >> n >> m;
    while(m --) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   
    DFS(1);
    // calculate log2 array 
    int val = 1, ptr = 0;
    pow2[0] = 1;
    for(int i = 1; i <= 19; i ++) pow2[i] = pow2[i - 1] << 1;
    for(int i = 1; i <= cnt; i ++){
        lg2[i] = ptr - 1;
        if(val == i){
            lg2[i] = ptr;
            ptr ++;
            val <<= 1;
        }
    }
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < cnt; i ++){
        dp[i][0] = node[i + 1];
    }
    for(int x = 1; x <= 19; x ++){
        for(int i = 0; i < cnt; i ++){
            if(dp[i][x - 1] != -1 && dp[i + pow2[x - 1]][x - 1] != -1){
                dp[i][x] = minHight(dp[i][x - 1], dp[i + pow2[x - 1]][x - 1]);
            }
            else break;
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
    init();
    output();
    return 0;
}