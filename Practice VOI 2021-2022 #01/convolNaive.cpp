#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "convol"
#define inf 1e9
#define mod 1000000007
#define maxn 5001

#define B 1000007

#define bit(x, i) ((x >> i) & 1)

int n;
int a[maxn], b[maxn];
ll res = -(1e18);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) cin >> b[i];
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            int k = 0;
            ll sum = 0;
            while(i + k <= n && j + k <= n){
                sum += 1ll * a[i + k] * b[j + k];
                k ++;
                res = max(res, sum);
            }
        }
    }
    cout << res;
    return 0;
}