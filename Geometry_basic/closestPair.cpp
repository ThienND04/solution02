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

double distance(pii& p1, pii& p2){
    double x2 = p1.first - p2.first;
    double y2 = p1.second - p2.second;
    return sqrt(1ll * x2 * x2 + 1ll * y2 * y2);
}

bool cmp(pii& p1, pii& p2){
    return p1.second < p2.second;
}

void bruteForce(pii a[], int sz){
    for(int i  = 0; i < sz; i ++){
        // cerr << a[i].first << " " << a[i].second << "\n";
        for(int j = i + 1; j < sz; j ++) {
            res = min(res, distance(a[i], a[j]));
        }
    }
}

void stripClosest(pii a[], int sz){
    // for(int i = 0; i < sz; i ++) cerr << a[i].first << " " << a[i].second << "\n";
    for(int i = 0; i < sz; i ++){
        for(int j = i + 1; j < sz && abs(a[j].second - a[i].second) < res; j ++){
            res = min(res, distance(a[i], a[j]));
        }
    }
}

void minimumDistance(pii a[], int sz){
    if(sz <= 3){
        sort(a, a + sz, cmp);
        bruteForce(a, sz);
        return;
    }
    int mid = sz / 2;
    minimumDistance(a, mid);
    minimumDistance(a + mid, sz - mid);
    // double splitLine = 1.0 * (a[mid].first + a[mid - 1].first) / 2;
    double splitLine = a[mid].first;
    merge(a, a + mid, a + mid, a + sz, strip, cmp);
    int cnt = 0;
    for(int i = 0; i < sz; i ++){
        a[i] = strip[i];
        if(abs(a[i].first - splitLine) < res){
            strip[cnt ++] = strip[i];
        }
    }
    stripClosest(strip, cnt);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> points[i].first >> points[i].second;
    sort(points, points + n);
    minimumDistance(points, n);
    cout << fixed << setprecision(3) << res;
    return 0;
}