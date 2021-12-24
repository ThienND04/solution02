#include<bits/stdc++.h>

using  namespace std;

typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "exMachines"
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
    
    return 0;
}