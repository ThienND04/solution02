#include <iostream>
#include <vector>
#include <queue>
#include<cstring>

using namespace std;

typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a));

#define maxn 206

int n, m;
bool s[maxn][maxn];
vector<int> adj[maxn];
int matchX[maxn], matchY[maxn];
int used[maxn], cur = 0;

bool DFS(int u){
    if(used[u] == cur) return 0;
    used[u] = cur;
    for(int v: adj[u]){
        if(matchY[v] == 0 || DFS(matchY[v])){
            matchX[u] = v;
            matchY[v] = u;
            return 1;
        }
    }
    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin >> n >> m;
    reset(s);
    reset(matchX);
    reset(matchY);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++) {
            cin >> s[i][j + n];
            if(s[i][j + n]){
                adj[i].push_back(j + n);
                adj[j + n].push_back(i);
            }
        }
    }
    int cnt = 0;
    for(cur = 1; cur <= n; cur ++){
        if(! matchX[cur]) cnt += DFS(cur);
    }
    for(int i = 1; i <= n; i ++){
        cout << (matchX[i] == 0 ? -1 : matchX[i] - n) << " ";
    }
    return 0;
}
