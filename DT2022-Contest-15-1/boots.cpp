#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "boots"
#define maxn 11
#define bit(x, i) ((x >> i) & 1)
#define inf 1000000000000000

int n, m;
int dep_id[maxn], b_id[maxn];
int depth[maxn], snow[maxn], dist[maxn];
int nt[maxn], pre[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> depth[i];
        dep_id[i] = i;
    }
    for(int i = 1; i <= m; i ++){
        cin >> snow[i] >> dist[i];
        b_id[i] = i;  
    }
    sort(dep_id + 1, dep_id + n + 1, [] (int x, int y){return depth[x] <= depth[y]; });
    sort(b_id + 1, b_id + n + 1, [](int x, int y) {return snow[x] <= snow[y]; });
    return 0;
}