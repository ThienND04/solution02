#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define inf 1000000000
#define task "e"
#define maxn 200001

int n, m;
int tmin[maxn * 4], tmax[maxn * 4], h[maxn], delta[maxn * 4], pos[maxn];

void init(int id, int l, int r){
    if(l == r){
        tmin[id] = pos[l];
        tmax[id] = pos[l];
        return;
    }
    int mid = (l + r) / 2;
    init(id * 2 + 1, l, mid);
    init(id * 2 + 2, mid + 1, r);
    tmin[id] = min(tmin[id * 2 + 1], tmin[id * 2 + 2]);
    tmax[id] = max(tmax[id * 2 + 1], tmax[id * 2 + 2]);
}

void update(int id, int l, int r, int p){
    if(l > p || r < p) return;
    if(l == r){
        tmin[id] = pos[l];
        tmax[id] = pos[l];
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2 + 1, l, mid, p);
    update(id * 2 + 2, mid + 1, r, p);
    tmin[id] = min(tmin[id * 2 + 1], tmin[id * 2 + 2]);
    tmax[id] = max(tmax[id * 2 + 1], tmax[id * 2 + 2]);
}

int getMin(int id, int l, int r, int u, int v){
    if(l > v || r < u) return inf;
    if(u <= l && r <= v){
        return tmin[id];
    }
    int mid = (l + r) / 2;
    int x = getMin(id * 2 + 1, l , mid, u, v), \
        y = getMin(id * 2 + 2, mid + 1, r, u, v);
    return min(x, y);
}

int getMax(int id, int l, int r, int u, int v){
    if(l > v || r < u) return 0;
    if(u <= l && r <= v){
        return tmax[id];
    }
    int mid = (l + r) / 2;
    int x = getMax(id * 2 + 1, l , mid, u, v), \
        y = getMax(id * 2 + 2, mid + 1, r, u, v);
    return max(x, y);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> h[i];
        pos[h[i]] = i;
    }
    init(0, 1, n);
    for(int i = 0; i < m; i ++){
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            swap(pos[h[a]], pos[h[b]]);
            swap(h[a], h[b]);
            update(0, 1, n, h[a]);
            update(0, 1, n, h[b]);
        }
        else{
            int k = getMax(0, 1, n, a, b) - getMin(0, 1, n, a, b);
            if(k == b - a){
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }
    return 0;
}