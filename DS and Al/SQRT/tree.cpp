#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 100001
#define task "serega"
#define BLOCK_SIZE 660

#define reset(a) memset(a, 0, sizeof(a))

class Block{
public:
    int size, tot;
    int elements[BLOCK_SIZE + 1], cnt[maxn], values[BLOCK_SIZE + 1];

    Block(){
        size = tot = 0;
        reset(cnt);
    }

    void append(const int& val){
        cnt[val] ++;
        elements[++ size] = val;
        values[++ tot] = val;
    }

    void init(){
        for(int i = 1; i <= tot; i ++){
            cnt[values[i]] = 0;
        }
        tot = size = 0;
    }
};

int numNodes, numEdges, numQueries;
int color[maxn];
vector<int> adj[maxn];

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
    cin >> numNodes >> numQueries;
    for(int i = 1; i <= numNodes; i ++) cin >> color[i];
    for(int i = 1; i < numNodes; i ++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    while (numQueries --)
    {
        
    }
    
    return 0;
}