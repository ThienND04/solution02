#include<bits/stdc++.h>

using  namespace std;

typedef pair<int ,int> pii;
typedef long long ll;
#define task "huyNhay"
#define maxn 101
#define inf 1e9

int n, m;
pii s, t;
string mp[maxn];
vector<pii> adj[maxn][maxn];

void init(){
    cin >> m >> n;
    for(int i = 0; i < m; i ++){
        cin >> mp[i];
    }
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            if(mp[i][j] == 'S') s = {i, j};
            else if(mp[i][j] == 'T') t = {i, j};
            if(mp[i][j] == '.') continue;
            for(int k = 1; k <= n; k ++){
                if(k == j || mp[i][k] == '.') continue;
                adj[i][j].push_back({i, k});
            }
            for(int k = 1; k <= m; k ++){
                if(k == i || mp[k][j] == '.') continue;
                adj[i][j].push_back({k, j});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    
    return 0;
}