#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "dance"
#define inf 1e18
#define mod 1000000007
#define maxn 100001

#define SQT 320

int n, m;
vector<int> adj[maxn];
vector<int> lsBe, lsTo;

void init(){
    cin >> n >> m;
    while(m --){
        int x, y;
        cin >> x >> y;
        adj[y].push_back(x);
    }
    
    for(int i = 1; i <= n; i ++){
        if(adj[i].size() <= SQT) lsBe.push_back(i);
        else lsTo.push_back(i);
    }
}

void solve(){
    for(int i = 1; i <= n; i ++){
        
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    solve();
    return 0;
}