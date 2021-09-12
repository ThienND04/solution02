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
pdd points[maxn], strip[maxn];

double distance(pdd& p1, pdd& p2){
    double x2 = p1.first - p2.first;
    double y2 = p1.second - p2.second;
    return sqrt(x2 * x2 + y2 * y2);
}

bool cmp(pdd& p1, pdd& p2){
    return (p1.second < p2.second);
}

double bruteForce(pdd a[], int sz){
    double d = inf;
    for(int i  = 0; i < sz; i ++){
        // cerr << a[i].first << " " << a[i].second << "\n";
        for(int j = i + 1; j < sz; j ++) {
            d = min(d, distance(a[i], a[j]));
        }
    }
    return d;
}

double stripClosest(pdd a[], int sz, double d){
    double mink = d;
    // for(int i = 0; i < sz; i ++) cerr << a[i].first << " " << a[i].second << "\n";
    for(int i = 0; i < sz; i ++){
        for(int j = i + 1; j < sz && (a[j].second - a[i].second) < mink; j ++){
            mink = min(mink, distance(a[i], a[j]));
        }
    }
    return mink;
}

double minimumDistance(pdd a[], int sz){
    if(sz <= 3){
        sort(a, a + sz, cmp);
        return bruteForce(a, sz);
    }
    int mid = sz / 2;
    double dl = minimumDistance(a, mid);
    double dr = minimumDistance(a + mid, sz - mid);
    double d = min(dl, dr);
    // double splitLine = 1.0 * (a[mid].first + a[mid - 1].first) / 2;
    double splitLine = a[mid].first;
    merge(a, a + mid, a + mid, a + sz, strip, cmp);
    int cnt = 0;
    for(int i = 0; i < sz; i ++){
        a[i] = strip[i];
        if(abs(a[i].first - splitLine) < d){
            strip[cnt ++] = strip[i];
        }
    }
    return min(d, stripClosest(strip, cnt, d));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> points[i].first >> points[i].second;
    cout << fixed << setprecision(3) << bruteForce(points, n);
    return 0;
}