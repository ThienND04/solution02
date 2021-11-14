#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "b"
#define inf 1000000000
#define mod 1000000007
#define maxn 500500

int m, n, num = 0;
pii facs[maxn], shop[maxn];

const int delta = 30;

bool cmp(pii& a, pii& b){
    return a > b;
}

ll calc(int l, int r, int u, int v){
    ll res = 0;
    if(r - l < delta || v - u < delta){
        for(int i = l; i <= r; i ++){ 
            for(int j = u; j <= v; j ++){
                if(facs[i].second < shop[j].second && facs[i].first < shop[j].first){
                    res = max(res, 1ll * (shop[j].first - facs[i].first) * (shop[j].second - facs[i].second));
                } 
            }
        }
        return res;
    }
    int mid = (l + r) / 2;
    int bestShop = 0;
    for(int j = u; j <= v; j ++){
        if(facs[mid].first < shop[j].first && facs[mid].second < shop[j].second){
            ll cc = 1ll * (shop[j].first - facs[mid].first) * (shop[j].second - facs[mid].second);
            if(cc > res){
                res = cc;
                bestShop = j;
            }
        }
    }
    return max(calc(l, mid, u, bestShop), calc(mid, r, bestShop, v));
}

void process(){
    cin >> m >> n;
    for(int i = 1; i <= m ; i++) cin >> facs[i].first >> facs[i].second;
    for(int i = 1; i <= n; i ++) cin >> shop[i].first >> shop[i].second;

    sort(facs + 1, facs + m + 1);
    sort(shop + 1, shop + n + 1, cmp);
    num = 1;
    for(int i = 2; i <= n; i ++){
        if(shop[i].second > shop[num].second) shop[++ num] = shop[i];
    }
    n = num;
    reverse(shop + 1, shop + n + 1);

    num = 0;
    facs[0].second = inf;
    for(int i = 1; i <= m; i ++){
        int u = lower_bound(shop + 1, shop + n + 1, facs[i]) - shop;
        if(u > n || shop[u].second <= facs[i].second) continue;
        if(facs[i].second < facs[num].second) facs[++ num] = facs[i];
    }
    m = num;
    cout << calc(1, m, 1, n);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    process();
    return 0;
}