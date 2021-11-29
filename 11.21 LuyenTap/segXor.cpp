#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "segXor"
#define inf 100000000
#define mod 1000000007
#define maxn 100001

#define maxk 10000001

int n, m;
int a[maxn];

ll query(int u, int v){
    ll res = 0;
    for(int l = u; l <= v; l ++){
        int x = 0;
        for(int r = l; r <= v; r ++){
            x ^= a[r];
            res += x;
        }
    }
    return res;
}

void process(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    while(m --){
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 2) cout << query(u, v) << "\n";
        else a[u] = v;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    process();
    return 0;
}