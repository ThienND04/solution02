#include<bits/stdc++.h>

using  namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "e"
#define inf 1e9
#define maxn 20002

struct pos{
    int x, y;
};

struct edge{
    pos l, r;
    edge(pos u, pos v){
        if(u.y > v.y)  {
            swap(u, v);
        }
        l = u;
        r = v;
    }
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

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i].x >> a[i].y;
    }
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
    n = m - 1;
    for(int i = 1; i <= n; i ++) a[i] = b[i];
}

ll getAreaX2(pos u1, pos u2, pos u3){
    return abs(1ll * (u2.x - u1.x) * (u2.y + u1.y) + 1ll * (u3.x - u2.x) * (u2.y + u3.y) + 1ll * (u1.x - u3.x) * (u1.y + u3.y));
}

bool inside(pos p){
    int l = 2, r = n;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(CCW(a[1], a[mid], p) > 0) l = mid;
        else r = mid;
    }
    if(l == 2 && CCW(a[1], a[l], p) <= 0) return 0;
    if(r == n && CCW(a[1], a[n], p) >= 0) return 0;
    ll s1 = getAreaX2(a[1], a[l], p);
    ll s2 = getAreaX2(a[1], a[r], p);
    ll s3 = getAreaX2(a[l], a[r], p);
    if(l == 2 && s1 == 0) return 0;
    if(r == n && s2 == 0) return 0;
    if(s3 == 0) return 0;
    ll s = getAreaX2(a[1], a[l], a[r]);
    return (s == s1 + s2 + s3);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    cin >> m;
    while(m --){
        pos p;
        cin >> p.x >> p.y;
        cout << inside(p) << "\n";
    }
    return 0;
}