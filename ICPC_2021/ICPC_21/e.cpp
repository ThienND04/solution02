#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "e"
#define inf 1000000000
#define mod 1000000007
#define maxn 10

template<class T> 
void maximize(T& x, T y){
    if(y > x) x = y;
}

template<class T> 
void add(T& x, T y){
    x += y;
}

int x, n;
int a[maxn];
ll f[1000001];

void process(){
    cin >> x >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    f[0] = 1;
    for(int i = 1; i <= x; i ++){
        for(int j = 1; j <= n; j ++){
            add(f[i], f[i - a[j]]);
        }
    }
    cout << f[x];
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