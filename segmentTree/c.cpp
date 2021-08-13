#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define inf 1000000000
#define task "c"
#define maxn 1000003

int n, m, z;
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

void push(int id){
    delta[id * 2 + 1] += delta[id];
    t[id * 2 + 1] += delta[id];
    delta[id * 2 + 2] += delta[id];
    t[id * 2 + 2] += delta[id];
    delta[id] = 0;
}

void update(int id, int l, int r, int u, int v, int d){
    if(l > v || r < u) return;
    if(u <= l && r <= v){
        t[id] += d;
        delta[id] += d;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2 + 1, l, mid, u, v, d);
    update(id * 2 + 2, mid + 1, r, u, v, d);
    t[id] = min(t[id * 2 + 1], t[id * 2 + 2]) + delta[id];
}

int get(int id, int l, int r, int u, int v){
    if(l > v || r < u) return inf;
    if(u <= l && r <= v) {
        return t[id];
    }
    push(id);
    int mid = (l + r) / 2;
    int x = get(id * 2 + 1, l, mid, u, v), \
        y = get(id * 2 + 2, mid + 1, r, u, v);
    return min(x, y);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> z >> m;
    for(int i = 1; i <= n; i ++){
        a[i] = z;
    }
    init(0, 1, n);
    for(int i = 0; i < m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        int s = get(0, 1, n, u, v - 1);
        if(s >= w) {
            cout << "T\n";
            update(0, 1, n, u, v - 1, -w);
        }
        else cout << "N\n";
    }
    return 0;
}