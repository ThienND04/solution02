#include<iostream>
#include<vector>

using namespace std;

#define maxn 100001

int n, root;
int p[maxn];
int height[maxn];
vector<int> child[maxn];

void DFS(int u){
    height[u] = 1;
    for(int v: child[u]){
        DFS(v);
        height[u] = max(height[u], height[v] + 1);
    }
}   

int main(){
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> p[i];
        if(p[i] == -1) root = i;
        else child[p[i]].push_back(i);
    }
    DFS(root);
    cout << height[root];
}