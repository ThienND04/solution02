#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "f"
#define inf 1000000000
#define mod 1000000007
#define maxn 10

template<class T> 
void maximize(T& x, T y){
    if(y > x) x = y;
}

int t;
int n, u, m;
int w[maxn];

#define tm(W, V) (W % V == 0 ? W / V : W / V + 1)

bool ok(int x){
    int lf = 0, rt = 0, i = 1;
    while(i <= n && lf + tm(w[i], u) <= x){
        lf += tm(w[i], u);
        i ++;
    }
    while(i <= n && rt + tm(w[i], m) <= x){
        rt += tm(w[i], m);
        i ++;
    }
    return (i == n + 1);
}

void solve(){
    cin >> n >> u >> m;
    if(u > m) swap(u, m);
    for(int i = 1; i <= n; i ++){
        cin >> w[i];
    }
    sort(w + 1, w + n + 1);
    // int l = 0, r = 100000000;
    int l = 0, r = 9;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(ok(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
}

void process(){
    cin >> t;
    while(t --) solve();
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