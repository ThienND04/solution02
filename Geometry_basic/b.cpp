#include<bits/stdc++.h>

using  namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "b"
#define inf 1e9
#define maxn 20002

struct pos{
    int x, y;
};

int n, m;
pos a[maxn], b[maxn];

bool cmp(pos& p, pos& q){
    if(p.x != q.x) return p.x < q.x;
    return p.y < q.y;
}

pii Vect(pos& u, pos& v){
    return {v.x - u.x, u.y - v.y};
}

ll CCW(pos& l,pos& mid,pos& r){
    pii u = Vect(l, mid);
    pii v = Vect(mid, r);
    return (1ll * u.first * v.second - 1ll * u.second * v.first);
}

void solve(){
    sort(a + 1, a + n + 1, cmp);
    b[m = 1] = a[1];
    for(int i = 2; i <= n; i ++){
        while(m > 1 && CCW(b[m - 1], b[m], a[i]) <= 0) m --;
        b[++ m] = a[i];
    }
    int chot = m;
    for(int i  = n - 1; i >= 1; i --){
        while(m > chot && CCW(b[m - 1], b[m], a[i]) <= 0) m --;
        b[++ m] = a[i];
    }
    m --;
}

double distance(pos& p, pos& q){
    return sqrt(1ll * (p.x - q.x) * (p.x - q.x) + 1ll * (p.y - q.y) * (p.y - q.y));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    int r;
    cin >> r;
    for(int i = 1; i <= n; i ++) cin >> a[i].x >> a[i].y;
    solve();
    double chuVi = 0;
    for(int i = 1; i <= m; i ++){
        chuVi += distance(b[i], b[i + 1]);
    }
    chuVi += 2 * 3.14159265359 * r;
    cout << fixed << setprecision(3) << chuVi;
    return 0;
}