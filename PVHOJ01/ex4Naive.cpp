#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "ex4"
#define maxn 3001
#define inf 1000000007
#define mod 998244353 

int subtask;
int n, numRoad;
pii road[maxn];
// vector<int> adj[maxn];
int par[maxn], s[maxn];

void add(int& x1, int x2){
    x1 += x2;
    if(x1 >= mod) x1 -= mod;
}

int root(int u){
    if(par[u] == -1) return u;
    return (par[u] = root(par[u]));
}

void merge(int u, int v){
    u = root(u), v = root(v);
    if(u == v) return;
    s[u] += s[v];
    par[v] = u;
}

void solve2()
{
    for(int i = 1; i <= numRoad; i ++){
        int result = 0;
        int sum = 0;
        for(int j = 1; j <= n; j ++) s[j] = 1;
        memset(par, -1, sizeof(par));
        for(int j = 1; j <= numRoad; j ++){
            if(j == i) continue;
            merge(road[j].first, road[j].second);
        }
        for(int j = 1; j <= n; j ++){
            if(par[j] == -1){
                add(result, (1ll * sum * s[j]) % mod);
                add(sum, s[j]);
            }
        }
        cout << result << " ";
    }
}

void solve1(){
    for(int i = 1; i <= n; i ++){
        int result = 0;
        int sum = 0;
        for(int j = 1; j <= n; j ++) s[j] = 1;
        memset(par, -1, sizeof(par));
        for(int j = 1; j <= numRoad; j ++){
            if(road[j].first == i || road[j].second == i) continue;
            merge(road[j].first, road[j].second);
        }
        for(int j = 1; j <= n; j ++){
            if(j != i && par[j] == -1){
                add(result, (1ll * sum * s[j]) % mod);
                add(sum, s[j]);
            }
        }
        cout << result << " ";
    }
    cout << "\n";
}

void init()
{
    cin >> subtask >> n >> numRoad;
    for(int i = 1; i <= numRoad; i ++){
        cin >> road[i].first >> road[i].second;
        // adj[road[i].first].push_back(road[i].second);
        // adj[road[i].second].push_back(road[i].first);
    }
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
    solve1();
    solve2();
    return 0;
}