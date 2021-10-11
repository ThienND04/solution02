#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "xquery"
#define inf 1e9
#define mod 1000000007
#define maxn 1000001

#define B 1000007

#define bit(x, i) ((x >> i) & 1)

int q;
map<int, int> cnt;

void Remove(int x){
    if(cnt[x] > 0){
        cnt[x] --;
    }
    if(cnt[x] == 0) cnt.erase(x);
}

void Update(int x){
    map<int, int> cnt2;
    for(pii i: cnt){
        cnt2[(i.first) ^ x] += i.second;
    }
    cnt = cnt2;
}

ll Query(int k){
    ll sum = 0;
    for(pii i: cnt){
        if(k == 0) return sum;
        int tmp = min(k, i.second);
        k -= tmp;
        sum += 1ll * i.first * tmp;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> q;
    while(q --){
        int t, x;
        cin >> t >> x;
        if(t == 0){
            cnt[x] ++;
        }
        else if(t == 1){
            Remove(x);
        }
        else if(t == 2){
            Update(x);
        }
        else cout << Query(x) << "\n";
    }
    return 0;
}