#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "lineall"
#define inf 1e9
#define mod 1000000007
#define maxn 10001
#define delta 0.0000001

#define bit(x, i) ((x >> i) & 1)

int n, k;
int h[maxn], c[maxn];
int t[maxn][257];

void Add(int& x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void update(int tt, int x, int y){
    while(x <= n + 1){
        Add(t[x][tt], y);
        x += x & -x;
    }
}

int get(int tt, int x){
    int s = 0;
    while(x){
        Add(s, t[x][tt]);
        x -= x & -x;
    }
    return s;
}

void init(){
    cin >> n >> k;
    vector<int> v;
    for(int i = 1; i <= n; i ++) {
        cin >> c[i] >> h[i];
        v.push_back(h[i]);
        c[i] --;
    }
    sort(v.begin(), v.end());
    for(int i = 1; i <= n; i ++) {
        h[i] = lower_bound(v.begin(), v.end(), h[i]) - v.begin() + 2;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    update(0, 1, 1);
    for(int i = 1; i <= n; i ++){
        for(int x = 0; x < (1 << k); x ++){
            int l = get(x, h[i] - 1);
            update(x | (1 << c[i]), h[i], l);
        }
    }
    cout << get((1 << k) - 1, n + 1);
    return 0;
}