#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "volleyball"
#define inf 1e9
#define mod 1000000007
#define maxn 300001
#define delta 0.0000001

#define bit(x, i) ((x >> i) & 1)

int t;

int solve(int k, int x, int y){
    if(x < y) swap(x, y);
    return max(max(k, y + 2) - x, 0);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> t;
    while(t --){
        int k, x, y;
        cin >> k >> x >> y;
        cout << solve(k, x, y) << " ";
    }
    return 0;
}