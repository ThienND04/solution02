#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a))
#define task "e"
#define mod 1000000000
#define inf 999999999
#define maxn 100009

int n, k;
int a[maxn], g[11][maxn];

void update(int p, int x, int sl){
    while(x <= n){
        g[p][x] = (g[p][x] + sl) % mod;
        x += x & -x;
    }
}

int get(int p, int x){
    int res = 0;
    while(x){
        res  = (res + g[p][x]) % mod;
        x -= x & -x;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    vector<int>v;
    v.assign(a + 1, a + n + 1);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 1; i <= n; i ++) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }
    for(int i = n; i >= 1; i--){
        for(int p = 1; p <= k; p ++){
            int c = get(p - 1, a[i] - 1);
            update(p, a[i], c);
        }
        update(1, a[i], 1);
    }
    cout << get(k, n);
    return 0;
}