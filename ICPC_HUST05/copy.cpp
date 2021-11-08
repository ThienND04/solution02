#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "copy"
#define inf 1e9
#define mod 1000000007
#define maxn 300001

#define bit(x, i) ((x >> i) & 1)

int n, a, b;
vector<pii> adj[maxn];
int f[maxn], cutEdge;
vector<int> path, tmp;

void findPath(int u, int par){
    if(! path.empty()) return ;
    if(u == b){
        path = tmp;
        return ;
    }
    for(pii e: adj[u]){
        int v = e.first;
        if(v == par) continue;
        tmp.push_back(e.second);
        findPath(v, u);
        tmp.pop_back();
    }
}


void init(){
    cin >> n >> a >> b;
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
}

int calc(int u, int par){
    int res = 0;
    vector<int> V;
    for(pii e: adj[u]){
        int v = e.first;
        if(v == par) continue;
        if(e.second == cutEdge) continue;
        V.push_back(calc(v, u));
    }
    sort(V.begin(), V.end(), [](int& x, int& y){return x > y; });
    for(int i = 0; i < V.size(); i ++) res = max(res, V[i] + i + 1);
    return res;
}

void process(){
    // tmp.push_back(a);
    findPath(a, -1);
    int l = 0, r = path.size();
    while(r - l > 1){
        int mid = (l + r) / 2;
        cutEdge = path[mid];
        // cerr << cutEdge << endl;
        int res1 = calc(a, -1);
        int res2 = calc(b, -1);
        if(res1 <= res2){
            l = mid;
        }
        else r = mid;
    }
    cutEdge = path[l];
    // cerr << cutEdge << endl;
    // cerr << calc(a, -1) << " " << calc(b, -1);
    int res = max(calc(a, -1), calc(b, -1));
    if(l + 1 < path.size()){
        cutEdge = path[l + 1];
        res = min(res, max(calc(a, -1), calc(b, -1)));
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    process();
    return 0;
}