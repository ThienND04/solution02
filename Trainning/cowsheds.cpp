#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 103
#define task "cowsheds"
#define inf 1000000000

int n, q;
int l[maxn], r[maxn];
int root[maxn];

void init(){
    cin >> n >> q;
    for(int i = 1; i <= n; i ++) root[i] = i;
    for(int i = 1;  i<= q; i ++) cin >> l[i] >> r[i];
}

int find(int u){
    if(u == root[u]) return u;
    return (root[u] = find(root[u]));
}

bool join(int u, int v){
    int x = find(u), y = find(v);
    if(x == y) return 0;
    root[x] = y;
    return 1;
}

void solve(){
    int sl = n;
    for(int i = 1; i <= q; i ++){
        int lf = l[i], rt = r[i];
        while(lf < rt){
            sl -= join(lf ++, rt --);
        }
        cout << sl << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r",  stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    solve();
    return 0;
}