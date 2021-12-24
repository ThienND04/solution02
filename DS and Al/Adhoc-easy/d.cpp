#include<bits/stdc++.h>

using  namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "d"
#define maxn 1000001

int a, n;
vector<pii> tsnt;

void pt(){
    tsnt.clear();
    for(int i = 2; i <= sqrt(a); i ++){
        int cnt = 0;
        while(a % i == 0){
            cnt ++;
            a /= i;
        }
        if(cnt){
            tsnt.push_back({i, cnt});
        }
    }
    if(a != 1) tsnt.push_back({a, 1});
}

bool check(ll k, int i){
    for(pii e: tsnt){
        int cnt = 0;
        while(i % e.first == 0) {
            i /= e.first;
            cnt ++;
        }
        if((1 + cnt) * k < e.second) return 0;
    }
    return 1;
}

void solve(){
    pt();
    int res = 1e9;
    for(pii e: tsnt){
        ll t = e.first;
        int cnt = 0;
        while(t <= n) {
            cnt += n / t;
            t *= e.first;
        }
        res = min(res, cnt / e.second);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> a;
    solve();
    return 0;
}