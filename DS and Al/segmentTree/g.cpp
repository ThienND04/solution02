#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define inf 1000000000
#define task "g"
#define maxn 200001

struct edge
{
    int l, r, y, t;
};

bool cmp(edge& a, edge& b){
    return a.y < b.y;
}

int n, m;
int t[maxn * 8], len[maxn * 8], delta[maxn * 8];
vector<edge> adj;
vector<int> vt;
ll res = 0;

void push(int id, int l, int r){
    int mid = (l + r) / 2;
    if(delta[id]) t[id] = vt[r - 1] - vt[l - 1];
    else if(l + 1 >= r) t[id] = 0;
    else t[id] = t[id * 2 + 1] + t[id * 2 + 2];
}

void update(int id, int l, int r, int u, int v, int d){
    //if(l > v || r < u) return;
    if(u <= l && r <= v){
        delta[id] += d;
        push(id, l, r);
        return;
    }
    int mid = (l + r) / 2;
    if(u < mid)update(id * 2 + 1, l, mid, u, v, d);
    if(v > mid)update(id * 2 + 2, mid, r, u, v, d);
    push(id, l, r);
}

void nhap(){
    cin >> n;
    int x1, x2, y1, y2;
    for(int i = 0; i < n; i ++){
        cin >> x1 >> x2 >> y1 >> y2;
        adj.push_back({x1, x2, y1, 1});
        adj.push_back({x1, x2, y2, -1});
        vt.push_back(x1);
        vt.push_back(x2);
    }
    sort(vt.begin(), vt.end());
    vt.resize(unique(vt.begin(), vt.end()) - vt.begin());
    for(edge& e: adj){
        e.l = lower_bound(vt.begin(), vt.end(), e.l) - vt.begin() + 1;
        e.r = lower_bound(vt.begin(), vt.end(), e.r) - vt.begin() + 1;
    }
    sort(adj.begin(), adj.end(), cmp);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    nhap();
    for(int i = 0; i < adj.size() - 1; i ++){
        update(0, 1, adj.size(), adj[i].l, adj[i].r, adj[i].t);
        res += 1ll * t[0] * (adj[i + 1].y - adj[i].y);
    }
    cout << res;
    return 0;
}