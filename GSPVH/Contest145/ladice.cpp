#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "ladice"
#define maxn 300001
#define inf 1000000007
#define mod 998244353

int n, l;
int par[maxn];

bool circle[maxn];

int root(int u){
    if(par[u] == u) return u;
    return (par[u] = root(par[u]));
}

string query(int a, int b){
    int u = root(a), v = root(b);
    if(u != v){
        if(! circle[u] && ! circle[v]){
            par[u] = v;
            return "Yes";   
        }
        else if(! circle[u] || ! circle[v]){
            par[u] = v;
            circle[v] = 1;
            return "Yes";
        }
    }
    else{
        if(! circle[u]) {
            circle[u] = 1;
            return "Yes";
        }
    }
    return "No";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n >> l;
    for(int i = 1; i <= l; i ++) par[i] = i;
    for(int i = 1; i <= n; i ++){
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << "\n";
    }
    return 0;
}