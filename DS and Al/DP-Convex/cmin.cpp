#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "cmin"
#define maxn 100001
#define inf 1e18
#define mod 1000000007

int n, m, t = 0, id[maxn];
int a[maxn], b[maxn], a2[maxn], b2[maxn], s[maxn];
double x[maxn];
int p[maxn], q[maxn];

bool cmp(int u, int v){
    if(a2[u] != a2[v]) return a2[u] > a2[v];
    return b2[u] > b2[v];
}   

bool ok(int i){
    int u = s[t];
    if(a[u] == a[i]) return 0;
    if(t == 1) return 1;
    double x1 = 1.0 * (b[i] - b[u]) / (a[u] - a[i]);
    u = s[t - 1];
    double x2 = 1.0 * (b[i] - b[u]) / (a[u] - a[i]);
    return (x1 > x2);
}

void init(){
    t = 0;
    for(int i = 1; i <= n; i ++){
        while(t > 0 && !ok(i)){
            t --;
        }
        s[++ t] = i;
    }
    x[0] = -inf;
    p[0] = a[s[1]], q[0] = b[s[1]];
    for(int i = 1; i < t; i ++){
        x[i] = 1.0 * (b[s[i]] - b[s[i + 1]]) / (a[s[i + 1]] - a[s[i]]);
        p[i] = a[s[i + 1]];
        q[i] = b[s[i + 1]];
    }
    x[t] = inf;
}

ll calc(int v){
    int u = upper_bound(x, x + t + 1, v) - x - 1;
    return 1ll * p[u] * v + q[u];
}   

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a2[i] >> b2[i];
        id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    for(int i = 1; i <= n; i ++){
        a[i] = a2[id[i]];
        b[i] = b2[id[i]];
    }
    init();
    cin >> m;
    for(int i = 1; i <= m; i ++){
        int v;
        cin >> v;
        cout << calc(v) << "\n";
    }
    return 0;
}