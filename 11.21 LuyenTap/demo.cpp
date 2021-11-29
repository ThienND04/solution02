#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "tower"
#define inf 1000000000
#define mod 1000000007
#define maxn 100001

template<class T>
void maximize(T& x, T y){
    if(x < y) x = y;
}

int n;
int r[maxn], h[maxn], f[501];

void process(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> r[i] >> h[i];
    reset(f);
    for(int i = 1; i <= n; i ++){
        for(int j = r[i]; j <= 500; j ++) {
            maximize(f[r[i]], f[j] + h[i]);
        }
    }
    cout << *max_element(f + 1, f + 501);
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