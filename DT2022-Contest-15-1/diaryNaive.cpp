#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "diary"
#define maxn 101
#define bit(x, i) ((x >> i) & 1)
#define inf 10000

int n,k;
int a[maxn], tmp[maxn];
bool vs[maxn];
int res = inf;

void calc(){
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(vs[i]) tmp[i] = 0;
        else tmp[i] = tmp[i - 1] + 1;
        if(tmp[i] != a[i]) cnt ++;
    }
    res = min(res, cnt);
}

void duyet(int p, int sl){
    if(p > n){
        if(sl == k + 1) calc();
        return;
    }
    vs[p] = 1;
    for(int i = p + 1; i <= n + 1; i ++){
        duyet(i, sl + 1);
    }
    vs[p] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(k = 1; k <= n; k ++){
        res = inf;
        duyet(1, 1);
        cout << res << "\n";
    }
    return 0;
}