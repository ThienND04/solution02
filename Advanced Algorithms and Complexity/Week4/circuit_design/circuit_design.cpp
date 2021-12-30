#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include<stack>

using namespace std;

typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a));

#define maxn 2000001
#define inf 1000000000
#define neg(x) ((x) ^ 1)

int n, m;
vector<int> adj[maxn];
int Num[maxn], Low[maxn], cnt = 0;
bool sol[maxn], sat = 1;

int vertexId[maxn], id = 0;

stack<int> st;

void visit(int u){
    Num[u] = Low[u] = ++ cnt;
    st.push(u);
    for(int v: adj[u]){
        if(Num[v]) {
            Low[u] = min(Low[u], Num[v]);
        }
        else {
            visit(v);
            Low[u] = min(Low[u], Low[v]);
        }
    }
    if(Num[u] == Low[u]){
        ++ id;
        int w = -1;
        do
        {
            w = st.top();
            st.pop();
            if(id == vertexId[w ^ 1]) {
                sat = 0;
                return;
            }
            Num[w] = Low[w] = inf;
            vertexId[w] =  id;
            if(w & 1) sol[w / 2 + 1] = 1;
            else sol[w / 2 + 1] = 0;
        } while (w != u);
    }
}

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
    
    for(int i = 0; i < 2 * n; i ++){
        if(! Num[i]) visit(i);
    }
    if(! sat){
        cout << "UNSATISFIABLE";
    }
    else{
        cout << "SATISFIABLE\n";
        for(int i = 1; i <= n; i ++) {
            if(sol[i]) cout << -i << " ";
            else cout << i << " ";
        }
    }
    return 0;
}
