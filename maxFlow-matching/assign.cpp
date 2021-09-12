#include<bits/stdc++.h>

using  namespace std;

typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "assign"
#define inf 1e9
#define maxn 100005

int n, m;
vector<int> adj[maxn];
int matchX[maxn], matchY[maxn];
int cur, used[maxn];
int id[maxn];

/*
matchX: x --> y
matchY: y --> x
*/ 

bool DFS(int x){
    if(used[x] == cur) return 0;
    used[x] = cur;
    for(int y: adj[x]){
        if(matchY[y] == 0 || DFS(matchY[y])){
            matchY[y] = x;
            matchX[x] = y;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m;
    int u, v;
    for(int i = 1; i <= n; i ++) id[i] = i;
    srand(clock());
    random_shuffle(id + 1, id + n + 1);
    // for(int i = 1; i <= n; i ++) cerr << id[i] << " ";
    while(cin >> u >> v) adj[u].push_back(v);
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        cur = id[i];
        if(matchX[cur] == 0){
            cnt += DFS(cur);
        }
    }
    cout << cnt << "\n";
    for(int i = 1; i <= m; i ++) cout << matchY[i] << " ";
    return 0;
}