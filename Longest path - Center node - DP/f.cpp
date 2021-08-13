#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
#define task "f"
#define maxn 100009
#define reset(a) memset(a, 0, sizeof(a));
#define inf 2000000007

struct data
{
    int l, r;
};

bool cmp(data & a, data & b){
    return a.r < b.r;
}

int giao(data& a, data& b){
    if(a.r <= b.l) return 0;
    return a.r - b.l;
}

int n;
data ed[maxn];
int dp[maxn];
int t[4 * maxn], dmax[4 * maxn];

void update(int id, int l, int r,int p, int x, int y){
    if(l > p || r < p) return;
    if(l == r){
        t[id] = max(t[id], x);
        dmax[id] = max(dmax[id], y);
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2 + 1, l, mid, p, x, y);
    update(id * 2 + 2, mid + 1, r , p, x, y);
    t[id ] = max(t[id * 2 + 1], t[id * 2 + 2]);
    dmax[id] = max(dmax[id * 2 + 1], dmax[id * 2 + 2]);
}

int find(int l, int r, int x){ // b[i] >= x 
    if(l == r) return l;
    int mid = (l + r) / 2;
    if(x <= ed[mid].r) return find(l, mid, x);
    return find(mid + 1, r, x);
}

pii get(int id, int l, int r, int u, int v){
    if(l > v || r < u) return {-inf, 0};
    if(u <= l && r <= v) return {t[id], dmax[id]};
    int mid = (l + r) / 2;
    pii g1 = get(id * 2 + 1, l, mid, u, v);
    pii g2 = get(id * 2 + 2, mid + 1, r, u, v);
    return {max(g1.first, g2.first), max(g1.second, g2.second)};
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        int l, r;
        cin >> l >> r;
        ed[i] = {l, r};
    }
    sort(ed + 1, ed + n + 1, cmp);
    fill(t, t + 4 * maxn, -inf);
    for(int i = 1; i <= n; i ++){
        int k = find(1, n, ed[i].l + 1) - 1;
        int d = get(0, 1, n, 1, k).second;
        int tm = get(0, 1, n, k + 1, i - 1).first;
        dp[i] = max(ed[i].r - ed[i].l + d, ed[i].l + ed[i].r + tm);
        update(0, 1, n, i, dp[i] - 2 * ed[i].r, dp[i]);
    }
    cout << *max_element(dp + 1, dp + n + 1);
    return 0;
}