#include<bits/stdc++.h>

using  namespace std;

typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "linePro"
#define inf 1e9
#define maxn 201
#define reset(a) memset(a, 0, sizeof(a))

int n;
int s[maxn][maxn];
int matchX[maxn], matchY[maxn];
int use[maxn];
int cur;

vector<int> adj[maxn];

bool dfs(int u){
    if(use[u] == cur)  return 0;
    use[u] = cur;
    for(int v: adj[u]){
        if(matchY[v] == 0 || dfs(matchY[v])){
            matchY[v] = u;
            matchX[u] = v;
            return 1;
        }
    }
    return 0;
}

bool check(int x){
    reset(use);
    reset(matchX);
    reset(matchY);
    for(int i = 1; i <= n; i ++){
        adj[i].clear();
        for(int j = 1; j <= n; j ++){
            if(s[i][j] >= x) adj[i].push_back(j);
        }
    }
    int cnt = 0;
    for(cur = 1; cur <= n; cur ++){
        if(matchX[cur] == 0) {
            cnt += dfs(cur);
        }
    }
    return (cnt == n);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++) cin >> s[i][j];
    }
    int l = -1, r = 20001;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    check(l);
    cout << l << "\n";
    for(int i = 1; i <= n; i ++) cout << matchX[i] << "\n";
    return 0;
}