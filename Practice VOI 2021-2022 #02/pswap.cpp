#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "pswap"
#define inf 1e18
#define mod 1000000007
#define maxn 20000

int n;
int p[maxn];

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> p[i];
}

void process(){
    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    process();
    return 0;
}