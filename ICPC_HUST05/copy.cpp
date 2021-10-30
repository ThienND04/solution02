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
vector<int> adj[maxn];
int timeCopy[maxn], s[maxn];

void init(){
    cin >> n >> a >> b;
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void preDFS(int u, int par){
    for(int v: adj[u]){
        if(v == par) continue;
    }
}

void process(){
    preDFS(a, -1);
    preDFS(b, -1);
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