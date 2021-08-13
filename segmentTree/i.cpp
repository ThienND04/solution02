#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define inf 1000000000
#define task "i"
#define maxn 100003

int n, m;
int t[maxn * 4], a[maxn], delta[maxn * 4];

void init(int id, int l, int r){
    if(l == r){
        t[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    init(id * 2 + 1, l, mid);
    init(id * 2 + 2, mid + 1, r);
    t[id] = min(t[id * 2 + 1], t[id * 2 + 2]);
}

void update(int id, int l, int r, int p, int d){
    if(l > p || r < p) return;
    if(l == r){
        t[id] = d;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2 + 1, l, mid, p, d);
    update(id * 2 + 2, mid + 1, r, p, d);
    t[id] = min(t[id * 2 + 1], t[id * 2 + 2]) + delta[id];
}

int get(int id, int l, int r, int u, int v){
    if(l > v || r < u) return inf;
    if(u <= l && r <= v) {
        return t[id];
    }
    int mid = (l + r) / 2;
    int x = get(id * 2 + 1, l, mid, u, v), \
        y = get(id * 2 + 2, mid + 1, r, u, v);
    return min(x, y);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    init(0, 1, n);
    cerr << get(0, 1, 4, 1, 4);
    for(int i = 0; i < m; i ++){
       int k, u, v;
       cin >> k >> u >> v;
       if(k == 1) update(0, 1, n, u, v);
       else cout << get(0, 1, n, u, v) << "\n";
    }
    return 0;
}