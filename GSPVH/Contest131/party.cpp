#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "party"
#define inf 1e9
#define maxn 2001
#define delta 0.0000001

int n;
int a[maxn];
int dp[maxn][maxn], p[maxn], nt[maxn][maxn];

vector<int> same[maxn];

void calc(){
    for(int d = 1; d < n; d += 2) {
        for(int l = 1; l + d <= n; l ++){
            int r = l + d;
            if(a[l] == a[l + 1]) dp[l][r] = max(dp[l][r], dp[l + 2][r] + 1);
            else if(a[r - 1] == a[r]) dp[l][r] = max(dp[l][r], dp[l][r - 2] + 1);
            else if(a[l] == a[r]) dp[l][r] = max(dp[l][r], dp[l + 1][r - 1] + 1);
            else{
                for(int i = nt[a[l]][l]; i < same[a[l]].size(); i ++) {
                    int mid = same[a[l]][i];
                    if(mid > r) break;
                    if(mid > l && (mid + l) % 2 != 0) {
                        dp[l][r] = max(dp[l][r], dp[l + 1][mid - 1] + dp[mid + 1][r] + 1);
                    }
                }
                for(int i = nt[a[r]][l]; i < same[a[r]].size(); i ++) {
                    int mid = same[a[r]][i];
                    if(mid >= r) break;
                    if((mid + r) % 2 != 0) {
                        dp[l][r] = max(dp[l][r], dp[l][mid - 1] + dp[mid + 1][r - 1] + 1);
                    }
                }
                dp[l][r] = max(dp[l][r], dp[l + 1][r - 1]);
            }
        }
    }
}

void trace(int l, int r){
    if(l >= r) return;
    if(dp[l][r] == 0 || r - l == 1){
        while(l < r){
            p[ l++ ] = r --;
        }
        return;
    }
    if(a[l] == a[l + 1]) {
        p[l] = l + 1;
        trace(l + 2, r);
        return;
    }
    if(a[r] == a[r - 1]){
        p[r- 1] = r;
        trace(l, r - 2);
        return;
    }
    if(a[l] == a[r] || dp[l][r] == dp[l + 1][r - 1]){
        p[l] = r;
        trace(l + 1, r - 1);
        return;
    }
    for(int i = nt[a[l]][l]; i < same[a[l]].size(); i ++){
        int mid = same[a[l]][i];
        if(mid > r) break;
        if(mid > l && (l + mid) % 2 && dp[l][r] == dp[l + 1][mid - 1] + dp[mid + 1][r] + 1){
            p[l] = mid;
            trace(l + 1, mid - 1);
            trace(mid + 1, r);
            return ;
        }
    }
    for(int i = nt[a[r]][l]; i < same[a[r]].size(); i ++){
        int mid = same[a[r]][i];
        if(mid >= r) break;
        if((r + mid) % 2 && dp[l][r] == dp[l][mid - 1] + dp[mid + 1][r - 1] + 1){
            p[mid] = r;
            trace(l, mid - 1);
            trace(mid + 1, r - 1);
            return ;
        }
    }
    assert(false);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        same[a[i]].push_back(i);
    }
    for(int i = 1; i <= n; i ++){
        for(int l = 1; l <= n; l ++){
            nt[i][l] = lower_bound(same[i].begin(), same[i].end(), l) - same[i].begin();
        }
    }
    calc();
    cout << dp[1][n] << "\n";
    trace(1, n);
    for(int i = 1; i <= n; i ++){
        if(i < p[i]) cout << i << " " << p[i] << "\n";
    }
    return 0;
}