#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "colorful"
#define inf 1e9
#define mod 2021
#define maxn 10001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

int n, m;
int color[maxn];
int cnt[maxn][maxbit];
vector<int> adj[maxn];

void DFS(int u, int par){
    cnt[u][0] = 1;
    cnt[u][1 << color[u]] = 1;
    for(int v: adj[u]){
        if(v == par) continue;
        DFS(v, u);
        for(int i = 1; i < (1 << m); i ++){
            int ans = 0;
            for(int j = 0; j < (1 << m); j ++){
                
            }   
        }
    }
}

void init(){
    reset(cnt);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> color[i];
        color[i] --;
    }
    while(m --){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
}

void process(){
    
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