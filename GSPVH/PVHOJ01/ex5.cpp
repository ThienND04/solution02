#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "ex5"
#define maxn 5001
#define inf 1000000007

int n, k, mod, result;
vector<int> adj[maxn];
bool blue[maxn], visited[maxn], yellow[maxn];
int s[maxn];

void add(int& x1, int x2){
    x1 += x2;
    if(x1 >= mod) x1 -= mod;
}

void DFS(int u){
    visited[u] = 1;
    for(int v: adj[u]){
        if(! visited[v]){
            DFS(v);
            if(! blue[u] && s[v] > 0 && s[u] > 0) {
                yellow[u] = 1;
            }
            s[u] += s[v];
        }
    }
    if(blue[u]) s[u] ++;
    if(! blue[u] && s[u] > 0 && k - s[u] > 0) {
        yellow[u] = 1;
    }
}

void duyet(int pos, int num){
    if(num == k){
        reset(s);
        reset(yellow);
        reset(visited);
        DFS(1);
        for(int i = 1; i <= n; i ++) add(result, yellow[i]);
        return;
    }
    for(int i = pos + 1; i <= n; i ++){
        blue[i] = 1;
        duyet(i, num + 1);
        blue[i] = 0;
    }
}

void subtask1(){
    duyet(0, 0);
    cout << result;
    exit(0);
}

void subtask3(){
    result = 0;
    cout << result;
    exit(0);
}

void solve(){
    if(k == 1) subtask3();
    else if(n <= 20) subtask1();
}

void init()
{
    cin >> n >> k >> mod;
    for(int i = 1; i < n; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
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
    solve();
    return 0;
}