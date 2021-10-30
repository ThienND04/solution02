#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 500500
#define task "min"

int n;
ll k;
ll a[maxn];
int fenwichTree[maxn];
vector<ll> v;

int get(int x){
    int res = 0;
    while(x) {
        res += fenwichTree[x];
        x -= x & -x;
    }
    return res;
}

void update(int x, int val){
    while(x <= n){
        fenwichTree[x] += val;
        x += x & -x;
    }
}

int id(ll key){
    int pos = lower_bound(v.begin(), v.end(), key) - v.begin() + 1;
    if(pos > n)  return n;
    if(v[pos - 1] != key) return pos - 1;
    return pos;
}

ll calc(int left, int right){
    if(left > right) return 0;
    if(left == right) return a[left] * 3 <= k;

    int mid = (left + right) / 2;
    ll curMin = a[mid + 1];
    ll result = 0;
    int cur = mid;
    for(int i = mid + 1; i <= right; i ++){
        curMin = min(curMin, a[i]);
        while(cur >= left && a[cur] >= curMin){
            update(id(a[cur]), 1);
            cur --;
        }
        result += get(id(k - a[i] - curMin));
    }
    cur ++;
    while(cur <= mid){
        update(id(a[cur]), - 1);
        cur ++;
    }
    cur = mid + 1;
    curMin = a[mid];
    for(int i = mid; i >= left; i --){
        curMin = min(curMin, a[i]);
        while(cur <= right && a[cur] > curMin){
            update(id(a[cur]), 1);
            cur ++;
        }
        result += get(id(k - a[i] - curMin));
    }
    cur --;
    while(cur >= mid + 1){
        update(id(a[cur]), -1);
        cur --;
    }
    return result + calc(left, mid) + calc(mid + 1, right);
}

void init(){
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    v.assign(a + 1, a + n + 1);
    sort(v.begin(), v.end());
}

void solve(){
    cout << calc(1, n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    solve();
    return 0;
}