#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define inf 1000000000
#define task "f"
#define maxn 100003

int n, k;
int t[maxn * 4], a[maxn];
vector<int> vt;

void init(int id, int l, int r){
    if(l == r){
        t[id] = 1;
        return;
    }
    int mid = (l + r) / 2;
    init(id * 2 + 1, l, mid);
    init(id * 2 + 2, mid + 1, r);
    t[id] = max(t[id * 2 + 1], t[id * 2 + 2]);
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
    t[id] = max(t[id * 2 + 1], t[id * 2 + 2]);
}

int get(int id, int l, int r, int u, int v){
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) {
        return t[id];
    }
    int mid = (l + r) / 2;
    int x = get(id * 2 + 1, l, mid, u, v), \
        y = get(id * 2 + 2, mid + 1, r, u, v);
    return max(x, y);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        vt.push_back(a[i]);
    }
    sort(vt.begin(), vt.end());
    vt.resize(unique(vt.begin(), vt.end()) - vt.begin());
    for(int i = 1; i <= n; i ++){
        int p = lower_bound(vt.begin(), vt.end(), a[i]) - vt.begin() + 1;
        int l = upper_bound(vt.begin(), vt.end(), a[i] - k) - vt.begin();
        int r = lower_bound(vt.begin(), vt.end(), a[i] + k) - vt.begin() + 1;
        int d = max(get(0, 1, vt.size(), 1, l), get(0, 1, vt.size(), r, vt.size()) );
        update(0, 1, vt.size(), p, d + 1);
    }
    cout << get(0, 1, vt.size(), 1, vt.size());
    return 0;
}