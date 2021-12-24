#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 1000001
#define task "paleta"
#define BLOCK_SIZE 100001

#define mod 998244353
#define inf 2100000000

// #define inf 1e18

#define inBlock(pos) ((pos - 1) / BLOCK_SIZE + 1)

#define reset(a) memset(a, 0, sizeof(a))

#define bit(x, i) ((x >> i) & 1)

int subtask;
int n, k, result = 1;
int f[maxn], id[maxn], low[maxn], num = 0;
int powOfKS1[maxn], dp[maxn];
stack<int> st;

void DFS(int u){
    id[u] = low[u] = ++ num;
    st.push(u);
    int v = f[u];
    if(id[v]){
        low[u] = min(low[u], id[v]);
    }
    else{
        DFS(v);
        low[u] = min(low[u], low[v]);
    }
    v = 0;
    if(low[u] == id[u]){
        int sl = 0;
        while(v != u){
            v = st.top();
            st.pop();
            sl ++;
            low[v] = id[v] = inf;
        }
        if(sl == 1){
            if(f[u] == u) result = (1ll * result * k) % mod;
            else result = (1ll * result * (k - 1)) % mod;
        }
        else result = (1ll * result * dp[sl]) % mod;
    }
}

void process(){
    cin >> subtask;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> f[i];
    powOfKS1[0] = 1;
    for(int i = 1; i <= n; i ++){
        powOfKS1[i] = (1ll * powOfKS1[i - 1] * (k - 1)) % mod;
    }
    dp[1] = 0;
    for(int i = 2; i <= n; i ++){
        dp[i] = (1ll * k * powOfKS1[i - 1] - dp[i - 1] + mod) % mod;
    }

    for(int i = 1; i <= n; i ++){
        if(id[i] == 0) DFS(i);
    }
    cout << result;
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
    process();
    return 0;
}