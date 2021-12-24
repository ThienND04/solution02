#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "d"
#define maxn 100001
#define reset(a) memset(a, 0, sizeof(a));
#define inf 1000000000
int n, k, vp, vc;
int s[maxn];
bool visd[maxn];
double t[maxn];
vector<pii> adj[maxn];
vector<vector<int>> ed;

bool cmp(double a, double b){
    return a > b;
}

void dfs(int u){
    visd[u] = 1;
    s[u] = 1;
    for(pii e: adj[u]){
        int v = e.first, l = e.second;
        if(! visd[v]){
            dfs(v);
            s[u] += s[v];
            // t[v] = l * (1.0 / vp - 1.0 / vc) * s[v] * (n  - s[v]);
        }
    }
    visd[u] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> k >> vp >> vc;
    ed.reserve(n);
    for(int i = 1; i < n; i ++){
        int u, v, l;
        cin >>  u >> v >> l;
        adj[u].push_back({v, l});
        adj[v].push_back({u, l});
        ed.push_back({u, v, l});
    }
    dfs(1);
    for(int i = 0; i < n - 1; i ++){
        int u = ed[i][0], v = ed[i][1], l = ed[i][2];
        if(s[u] < s[v]) swap(u, v);
        t[i] = l * (1.0 / vp - 1.0 / vc) * s[v] * (n  - s[v]);
    }
    sort(t, t + n - 1, cmp);
    double res = 0;
    for(int i = 0; i < k; i ++) res += t[i];
    cout << fixed << setprecision(2) << res;
    return 0;
}