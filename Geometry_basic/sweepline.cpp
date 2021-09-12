#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "closestPair"
#define inf 1e14
#define maxn 200009

int n;
pii points[maxn], strip[maxn];
double res = DBL_MAX;
set<pii> S;

double distance(pii& p1, pii& p2){
    double dx = p1.first - p2.first;
    double dy = p1.second - p2.second;
    return sqrt(1ll * dx * dx + 1ll * dy * dy);
}

bool cmp(pii& p1, pii& p2){
    if(p1.first != p2.first) return p1.first < p2.first; 
    return p1.second < p2.second;
}

void solve(){
    sort(points, points + n, cmp);
    S.insert({points[0].second, points[0].first});
    int l = 0;
    for(int i = 1; i < n; i ++){
        double x = points[i].first, y = points[i].second;
        while(x - points[l].first > res) S.erase({points[l].second, points[l ++].first});
        set<pii>::iterator it = S.lower_bound({y - res, x - res});
        for(; it != S.end() && it -> first < y + res ; it ++){
            pii tmp = {it -> second, it -> first};
            res = min(res, distance(tmp, points[i]));
        }
        S.insert({points[i].second, points[i].first});
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> points[i].first >> points[i].second;
    solve();
    cout << fixed << setprecision(3) << res;
    return 0;
}