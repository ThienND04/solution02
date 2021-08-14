#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "easytask"
#define maxn 1000001
#define bit(x, i) ((x >> i) & 1)
#define inf 1000000000000000

int n;
int a[maxn];
bool snt[maxn];
ll s[maxn], res = -inf;
vector<int> v;

void sang(){
    for(int i = 2; i <= n; i ++) snt[i] = 1;
    for(int i = 2; i <= sqrt(n); i ++){
        if(snt[i]){
            for(int j  = i * i; j <= n; j += i) snt[j] = 0;
        }
    }
}

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sang();
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        s[i] = s[i - 1] + a[i];
    }
    v.reserve(n);
    for(int i = 1; i <= n; i ++) if(snt[i]) v.push_back(i);
}

void solve(){
    int mi = 0;
    for(int i: v){
        if(! mi || s[mi] - a[mi] > s[i] - a[i]) mi = i;
        res = max(res, s[i] - s[mi] + a[mi]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();
    solve();
    cout << res;
    return 0;
}