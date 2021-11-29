#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "astronomy"
#define inf 1000000000
#define mod 1000000007
#define maxn 6001

int n;
pii points[maxn];
pii vt[maxn];
pii ls[2][36000001];
pair<pii, int> pvt[36000001];
int num[2];

const int maxPos = 1000000;

pll giao(const pii& p1,const pii& p2,const pii& p3,const pii& p4){
    int a1 = p2.second - p1.second, b1 = p1.first - p2.first;
    int a2 = p4.second - p3.second, b2 = p3.first - p4.first;
    ll c1 = -(1ll * a1 * p1.first + 1ll * b1 * p1.second);
    ll c2 = -(1ll * a2 * p3.first + 1ll * b2 * p3.second);

    if(1ll * a2 * b1 == 1ll * a1 * b2) return {inf, inf};
    if((a1 * c2 - a2 * c1) % (1ll * a2 * b1 - 1ll * a1 * b2)){
        return {inf, inf};
    }
    ll y = (1ll * a1 * c2 - 1ll * a2 * c1) / (1ll * a2 * b1 - 1ll * a1 * b2), x;
    if(a2 == 0) {
        if((-b1 * y - c1) % a1) return {inf, inf};
        x = (-b1 * y - c1) / a1;
    }
    else{
        if((-b2 * y - c2) % a2) return {inf, inf};
        x = (-b2 * y - c2) / a2;
    }
    return {x, y};
}

template<class T>
T gcd(T a, T b){
    while(a * b != 0){
        if(a > b) a %= b;
        else b %= a;
    }
    return a + b;
}

template<class T>
void rutGon(pair<T, T>& p){
    if(p.first == 0 && p.second == 0) return;
    else if(p.first == 0) p.second = 1;
    else if(p.second == 0) p.first = 1;
    else{
        T g = gcd(abs(p.first), p.second);
        p.first /= g;
        p.second /= g;
    }
}

pii getD(const pii& a, const pii& b){
    pii res = {a.first - b.first, a.second - b.second};
    if(res.second < 0){
        res.second = -res.second;
        res.first = -res.first;
    }
    rutGon(res);
    return res;
}

bool ok(int x, int y){
    for(int i = 1; i <= 2 * n; i ++){
        vt[i] = {x - points[i].first, y - points[i].second};
        if(vt[i].second < 0){
            vt[i].second = - vt[i].second;
            vt[i].first = - vt[i].first;
        }
        rutGon(vt[i]);
    }
    sort(vt + 1, vt + 2 * n + 1);
    for(int i = 1; i <= 2 * n; i += 2){
        if(vt[i] != vt[i + 1] || vt[i] == vt[i - 1]) return 0;
    }
    return 1;
}

void init(){
    cin >> n;
    for(int i = 1; i <= 2 * n; i ++) {
        cin >> points[i].first >> points[i].second;
    }
    random_shuffle(points + 1, points + 2 * n + 1);
    random_shuffle(points + 1, points + 2 * n + 1);
    pii a = points[1];
    num[0] = 0;
    for(int i = 2; i <= 2 * n; i ++){
        pii b = points[i];
        int x = (i == 2 ? 3 : 2);
        pii t = points[x];
        for(int y = x + 1; y <= 2 * n; y ++){
            if(y == i) continue;
            pii l = points[y];
            pll gt = giao(a, b, t, l);
            if(abs(gt.first) > maxPos || abs(gt.second) > maxPos) continue;
            ls[0][++ num[0]] = {gt.first, gt.second};
        }
    }
    num[1] = 0;
    sort(ls[0] + 1, ls[0] + num[0] + 1);
    sort(points + 1, points + 2 * n + 1);
    int u = 1;
    for(int i = 1; i <= num[0]; i ++){
        while(u <= 2 * n && points[u] < ls[0][i]) u ++;
        if(u > 2 * n || points[u] != ls[0][i]){
            ls[1][++ num[1]] = ls[0][i];
        }
    }
    random_shuffle(points + 1, points + 2 * n + 1);
    random_shuffle(points + 1, points + 2 * n + 1);
}

void process(){
    init();
    for(int i = 1; i <= 2 * n; i ++){
        int numd = 0;
        for(int j = 1; j <= 2 * n; j ++){
            if(i == j) continue;
            vt[++ numd] = getD(points[i], points[j]);
        }
        num[(i + 1) & 1] = 0;
        for(int j = 1; j <= num[i & 1]; j ++){
            pvt[j] = {getD(points[i], ls[i & 1][j]), j};
        }
        sort(pvt + 1, pvt + num[i & 1] + 1);
        sort(vt + 1, vt + 2 * n);
        int u = 1;
        for(int j = 1; j <= num[i & 1]; j ++){
            while(u < 2 * n && pvt[j].first > vt[u]) u ++;
            if(u < 2 * n && pvt[j].first == vt[u]){
                ls[(i + 1) & 1][++ num[(i + 1) & 1]] = ls[i & 1][pvt[j].second];
            }
        }
        if(((i + 1) & 1) && num[(i + 1) & 1] <= 100){
            break;
        }
    }
    for(int i = 1; i <= num[1]; i ++){
        if(ok(ls[1][i].first, ls[1][i].second)) {
            cout << "Yes\n" << ls[1][i].first << " " << ls[1][i].second;
            return;
        }
    }
    // assert(0);
    cout << "No";
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