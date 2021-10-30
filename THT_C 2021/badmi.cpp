#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "badmi"
#define maxn 100100
#define inf 1000000007
#define mod 998244353

int n, m, q;
pii earth[maxn], moon[maxn], people[maxn];


void init(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i ++) cin >> earth[i].first;
    for(int i = 1; i <= n; i ++) cin >> earth[i].second;

    sort(earth + 1, earth + n + 1);

    for(int j = 1; j <= m; j ++) cin >> people[j].first;
    for(int j = 1; j <= m; j ++) cin >> people[j].second;
}

int query(int k){
    for(int i = 1; i <= n; i ++) moon[i] = people[i + k - 1];
    sort(moon + 1, moon + n + 1);

    multiset<int> mlst;

    int j = 1;
    int result = 0;

    for(int i = 1; i <= n; i ++){
        while(j <= n && earth[i].first > moon[j].first){
            mlst.insert(moon[j ++].second);
        }
        if(mlst.empty() || * mlst.begin() >= earth[i].second) continue;

        auto it = mlst.lower_bound(earth[i].second);
        it --;
        result ++;
        mlst.erase(it);
    }
    return result;
}

void solve(){
    while(q --){
        int k;
        cin >> k;
        cout << query(k) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    init();
    solve();
    return 0;
}