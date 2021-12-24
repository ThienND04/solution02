#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a))
#define task "SNT"
#define inf 999999999
#define maxn 100009

int n;
int s[maxn], a[maxn];

void update(int x, int v){
    while(x <= n){
        s[x] += v;
        x += x & -x;
    }
}

int get(int x){
    int res = 0;
    while(x){
        res += s[x];
        x -= x & -x;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    vector<int>v;
    v.assign(a + 1, a + n + 1);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 1; i <= n; i ++) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }
    ll res = 0;
    for(int i = n; i >= 1; i --){
        res += get(a[i] - 1);
        update(a[i], 1);
    }
    cout << res;
    return 0;
}