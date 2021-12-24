#include<bits/stdc++.h>

using  namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "cinema"
#define maxn 900001
#define mod 998244353

int n, m;
int t[maxn];
int pt[maxn], sl[maxn];
int id1 = 0;

int solve(){
    int res = 1;
    for(int i = 1; i < id1; i ++ ) if(pt[i] <= pt[id1]) return 0;
    for(int i = id1 + 1; i <= m; i ++ ) if(pt[i] <= pt[id1]) return 0;
    int l = id1 - 1, r = id1 + 1;
    int last = 1;
    while(l && r <= m){
        if(pt[l] < pt[r]){
            int cnt = pt[l] - last - 1;
            if(cnt < sl[])
        }
        else{

        }
    }   
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    m = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> t[i];
    for(int i = 1; i <= n; i ++){
        if(t[i]) pt[++ m] = t[i];
        else sl[m] ++;
        if(t[i] == 1) id1 = m;
    }
    if(id1) cout << solve();
    else assert(0);
    return 0;
}