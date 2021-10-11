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
int h[maxn];
ll res = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> h[i];
    if(n == 3){
        if(h[2] == 2 && h[1] == 1) res = 0;
        else if(h[1] == 2 && h[2] == 1) res = 1;
        else if(h[1] == 3 && h[2] == 1) res = 2;
        else if(h[1] == 1 && h[2] == 3) res = 1;
        else if(h[1] == 2 && h[2] == 3) res = 2;
        else if(h[1] == 3 && h[2] == 2) res = 1;
        cout << res;
    }
    else cout << 3;
    return 0;
}