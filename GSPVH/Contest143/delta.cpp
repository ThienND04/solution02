#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "delta"
#define maxn 20
#define inf 1000000007
#define mod 998244353

void Add(int& x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

int t, n, delta;
int a[maxn], incrVal[maxn], decrVal[maxn], sz1 = 0, sz2 = 0;
int res = 0;

int bnSearchIncrea(int x){
    int l = 0, r = sz1 + 1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(a[incrVal[mid]] <= x) l = mid;
        else r = mid;
    }
    return incrVal[l];
}

int bnSearchDecrea(int x){
    int l = 0, r = sz2 + 1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(a[decrVal[mid]] >= x) l = mid;
        else r = mid;
    }
    if(l == 0) return 0;
    return decrVal[l];
}

void solve1(){
    decrVal[0] = n + 1;
    for(int i = 1; i <= n; i ++){
        int tmp1 = bnSearchDecrea(a[i] + delta + 1), tmp2 = bnSearchIncrea(a[i] - delta - 1);
        int tmp = max(tmp1, tmp2);
        res += i - tmp;
        while(sz1 && a[incrVal[sz1]] >= a[i]) sz1 --;
        incrVal[++ sz1] = i;
        while(sz2 && a[decrVal[sz2]] <= a[i]) sz2 --;
        decrVal[++ sz2] = i;
    }
    cout << res << " ";
}

void solve2(){
    sort(a + 1, a + n + 1);
    res = 0;
    for(int i = 1; i <= n; i ++){
        int total = 1;
        res ++;
        int maxVal = a[i];
        for(int j = i + 1; j <= n; j ++){
            maxVal = max(maxVal, a[j]);
            if(maxVal - a[i] > delta) break;
            Add(res, total);
            total = (total * 2) % mod;
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> t >> n >> delta;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    a[n + 1] = (1e9) + delta;
    a[0] = - delta;
    solve1();
    solve2();
    return 0;
}