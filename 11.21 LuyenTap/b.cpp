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

int m, n;
pii facs[maxn], shop[maxn];
pii tmp[maxn]; int num = 0;

ll res = 0;

bool cmp(pii& a, pii& b){
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

void process(){
    cin >> m >> n;
    for(int i = 1; i <= m ; i++) cin >> facs[i].first >> facs[i].second;
    for(int i = 1; i <= n; i ++) cin >> shop[i].first >> shop[i].second;

    sort(facs + 1, facs + m + 1, cmp);
    sort(shop + 1, shop + n + 1, cmp);

    tmp[0].first = inf;

    int r = 1;
    for(int i = 1; i <= n; i ++){
        while(r <= m && shop[i].second >= facs[r].second){
            if(facs[r].first >= tmp[num].first) {
                r ++;
                continue;
            }
            if(facs[r].second == tmp[num].second) {
                tmp[num] = facs[r ++];
            }
            else {
                tmp[++ num] = facs[r ++];
            }
        }
        for(int j = 1; j <= num; j ++){
            res = max(res, 1ll * (shop[i].second - tmp[j].second) * (shop[i].first - tmp[j].first));
        }
    }
    cout << res;
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