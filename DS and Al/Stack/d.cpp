#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "d"
#define maxn 100009
#define inf 1000000000007

int n, l, r;
int a[maxn];
ll s[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> l >> r;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    s[0] = 0;
    for(int i = 1; i <= n; i ++) s[i] = s[i - 1] + a[i];
    ll res = -inf;
    deque<int> d;
    d.push_back(0);
    for(int i = 1; i <= n; i ++){
        if(i + l > n) continue;
        while(! d.empty() && s[d.back()] >= s[i]) d.pop_back();
        while(! d.empty() && i - d.front() > r - l) d.pop_front();
        d.push_back(i);
        res = max(res, s[i + l] - s[d.front()]);
    }
    cout << res;
    return 0;
}