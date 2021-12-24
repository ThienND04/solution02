#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a));

#define maxn 2000001

#define neg(x) ((x) ^ 1)

int n, m;
vector<int> adj[maxn];

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin >> n >> m;
    while(m --){
        int u, v;
        cin >> u >> v;
        if(u < 0) u = (-u * 2 - 1) ^ 1;
        else u = u * 2 - 1;
        if(v < 0) v = (-v * 2 - 1) ^ 1;
        else v = v * 2 - 1;
        adj[neg(u)].push_back(v);
        adj[neg(v)].push_back(u);
    }
    
    return 0;
}
