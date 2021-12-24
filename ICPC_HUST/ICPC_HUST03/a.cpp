#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "a"
#define inf 1e9
#define mod 1000000007
#define maxn 500001

#define bit(x, i) ((x >> i) & 1)

int k, n, m;
int a[maxn], id[maxn];
long long res = 0;

bool cnt[maxn];

bool check(int maxWep){
    long long res2 = 0;
    int m2 = m;
    reset(cnt);
    for(int i = n; i >= n - k + 1; i --){
        res2 += a[id[i]];
        cnt[i] = 1;
        m2 --;
    }
    for(int i = n; i >= 1; i --){
        int tmp = min(m2, (maxWep - cnt[i]));
        res2 += 1ll * tmp * a[id[i]];
        m2 -= tmp;
    }
    if(m2) return 0;
    assert(res2 <= res);
    return (res2 == res);
}

void xuat(int maxWep){
    int m2 = m;
    reset(cnt);
    for(int i = n; i >= n - k + 1; i --){
        cout << id[i] << " ";
        m2 --;
        cnt[i] = 1;
    }
    for(int i = n; i >= 1; i --){
        int tmp = min(m2, (maxWep - cnt[i]));
        m2 -= tmp;
        for(int j = 0; j < tmp; j ++) cout << id[i] << " ";
    }
}

void solve(){
    for(int i = n; i >= n - k + 1; i --){
        res += a[id[i]];
    }
    int l = 0, r = m - k + 1;
    res += 1ll * (m - k) * a[id[n]];
    // cerr << res;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    xuat(r);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        id[i] = i;
    }
    sort(id + 1, id + n + 1, [](int x, int y) {return a[x] < a[y]; });
    solve();
    return 0;
}