#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define inf 1000000009
#define mod 1000000007
#define task "d"
#define maxn 100003

int n, m;
int t[maxn * 4], a[maxn];
ll  nhan[4 * maxn], cong[4 * maxn];

void init(int id, int l, int r){
    nhan[id] = 1;
    cong[id] = 0;
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
    nhan[id * 2 + 1] = (nhan[id * 2 + 1] * nhan[id]) % mod;
    cong[id * 2 + 1] = (cong[id * 2 + 1] * nhan[id] + cong[id]) % mod;
    nhan[id * 2 + 2] = (nhan[id * 2 + 2] * nhan[id]) % mod;
    cong[id * 2 + 2] = (cong[id * 2 + 2] * nhan[id] + cong[id]) % mod;
    nhan[id] = 1;
    cong[id] = 0;
}

void update(int id, int l, int r, int u, int v,int s,  int d){
    if(l > v || r < u) return;
    if(u <= l && r <= v){
        nhan[id] = (nhan[id] * s) % mod;
        cong[id] = (cong[id] * s + d) % mod;
        return;
    }
    push(id);
    int mid = (l + r) / 2;
    update(id * 2 + 1, l, mid, u, v, s, d);
    update(id * 2 + 2, mid + 1, r, u, v, s, d);
}

ll get(int id, int l, int r, int p){
    if(l > p || r < p) return inf;
    if(l == r) {
        return (t[id]  * nhan[id] + cong[id]) % mod;
    }
    push(id);
    int mid = (l + r) / 2;
    ll x = get(id * 2 + 1, l, mid, p), \
        y = get(id * 2 + 2, mid + 1, r, p);
    return min(x, y);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    init(0, 1, n);
    cin >> m;
    for(int i = 0; i < m; i ++){
        char t;
        int u, v, d;
        cin >> t;
        if(t == '+'){
            cin >> u >> v >> d;
            update(0, 1, n, u, v, 1, d);
        }
        else if(t == '*'){
            cin >> u >> v >> d;
            update(0, 1, n, u, v, d, 0);
        }
        else {
            cin >> u;
            cout << get(0, 1, n, u) << "\n";
        }
    }
    return 0;
}