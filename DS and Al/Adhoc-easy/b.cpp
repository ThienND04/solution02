#include<bits/stdc++.h>

using  namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "b"
#define maxn 1000001

int a;
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

ll solve(){
    pt();
    int b = 1, m = 0;
    for(pii e: tsnt) {
        b *= e.first;
        m = max(m, e.second);
    }
    for(int i = 1; i <= 32; i ++){
        ll k = 1ll * b * i;
        if(k >= m || check(k, i)) return k;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    while(cin >> a){
        cout << solve() << "\n";
    }
    return 0;
}