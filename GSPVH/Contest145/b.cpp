#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "b"
#define maxn 1000000
#define inf 1000000007
#define mod 998244353

int t, n;
ll l[maxn], r[maxn];
int BIT[maxn];

vector<ll> value;

void update(int x, int i){
    for(; x <= n; x += x & - x){
        BIT[x] += i;
    }
}

int get(int x){
    int res = 0;
    while(x){
        res += BIT[x];
        x -= x & -x;
    }
    return res;
}

void Try(int pos, int cnt, ll val){
    if(pos > 18){
        value.push_back(val);
        return ;
    }
    Try(pos + 1, cnt, val * 10);
    if(cnt == 0) return;
    for(int i = 1; i <= 9; i ++){
        Try(pos + 1, cnt - 1, val * 10 + i);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> t;
    for(int i = 1; i <= t; i ++) cin >> l[i] >> r[i];
    Try(1, 3, 0);
    value.push_back(1e18);
    // cerr << value.size();
    vector<ll> v;
    v.reserve(1000000);
    for(ll i: value) v.push_back(i);
    for(int i = 1; i <= t; i ++){
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    n = v.size();
    for(int i = 1; i <= t; i ++){
        l[i] = lower_bound(v.begin(), v.end(), l[i]) - v.begin() + 1;
        r[i] = lower_bound(v.begin(), v.end(), r[i]) - v.begin() + 1;
    }
    for(int i = 0; i < value.size(); i ++){
        value[i] = lower_bound(v.begin(), v.end(), value[i]) - v.begin() + 1;
        update(value[i], 1);
    }
    for(int i = 1; i <= t; i ++){
        cout << get(r[i]) - get(l[i] - 1) << "\n";
    }
    return 0;
}