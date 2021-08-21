#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "boots"
#define maxn 100001
#define bit(x, i) ((x >> i) & 1)
#define inf 1000000000000000

int n, m;
int dep_id[maxn], b_id[maxn];
int depth[maxn], snow[maxn], dist[maxn];
int nt[maxn], pre[maxn];
bool ac[maxn];

void init(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> depth[i];
        dep_id[i] = i;
    }
    for(int i = 1; i <= m; i ++){
        cin >> snow[i] >> dist[i];
        b_id[i] = i;  
    }
    sort(dep_id + 1, dep_id + n + 1, [] (int x, int y){return depth[x] < depth[y]; });
    sort(b_id + 1, b_id + m + 1, [](int x, int y) {return snow[x] < snow[y]; });
    for(int i = 1; i <= n; i ++){
        nt[i] = i + 1;
        pre[i] = i - 1;
    }
}

void solve(){
    int j = n;
    int max_step = 1;
    for(int i = m; i >= 1; i --){
        while(j > 0 && depth[dep_id[j]] > snow[b_id[i]]){
            int cur = dep_id[j --];
            nt[pre[cur]] = nt[cur];
            pre[nt[cur]] = pre[cur];
            max_step = max(max_step, nt[cur] - pre[cur]);
        }
        ac[b_id[i]] = (max_step <= dist[b_id[i]]);
    }
    for(int i = 1; i <= m; i ++) {
        cout << ac[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();
    solve();
    return 0;
}