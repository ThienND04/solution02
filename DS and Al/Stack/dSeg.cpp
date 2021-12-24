#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "d"
#define maxn 100009
#define inf 1000000000007

int n, l, r;
int a[maxn];
ll s[maxn], st[4 * maxn];

void init(int id, int lf, int rt){
    if(lf == rt){
        st[id] = s[lf];
        return;
    }
    int mid = (lf + rt) / 2;
    init(id * 2 + 1, lf, mid);
    init(id * 2 + 2, mid + 1, rt);
    st[id] = min(st[id * 2 + 1], st[id * 2 + 2]);
}

ll getMin(int id, int lf, int rt, int u, int v){
    if(lf > v || rt < u) return inf;
    if(lf >= u && rt <= v) return st[id];
    int mid = (lf + rt) / 2;
    return min(getMin(id * 2 + 1, lf, mid, u, v), getMin(id * 2 + 2, mid + 1, rt, u, v));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    s[0] = 0;
    for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
    ll res = -inf;
    init(0, 0, n);
    for(int i = l; i <= n; i ++){
        int u = max(0, i - r), v = i - l;
        ll tmp = s[i] - getMin(0, 0, n, u, v);
        res = max(res, tmp);
    }
    cout << res;
    return 0;
}