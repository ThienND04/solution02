#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "teleport"
#define inf 1e9
#define mod 1000000007
#define maxn 100001
#define delta 0.0000001

#define bit(x, i) ((x >> i) & 1)

int n;
int x[maxn], positive[maxn];
ll res = 1e18;
ll sum[maxn];

void calc(){
    int numPositive = 0;
    ll sumNegative = 0;
    for(int i = 1; i <= n; i ++){
        if(x[i] > 0) positive[++ numPositive] = x[i];
        else sumNegative -= x[i];
    }
    sum[0] = 0;
    for(int i  = 1; i <= numPositive; i ++) sum[i] = sum[i - 1] + positive[i];
    for(int i = 0; i <= numPositive; i ++){
        ll sumTo0 = sum[i];
        int tmp = (numPositive - i) / 2;
		// tổng quãng đường di chuyển của các điểm đi tới P (áp dụng bài toán phụ)
		ll sumToP = 
			(sum[numPositive] - sum[numPositive - tmp]) - (sum[i + tmp] - sum[i]);
        res = min(res, sumNegative + sumTo0 + sumToP);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> x[i];
    sort(x + 1, x + n + 1);
    calc();
    for(int i = 1; i <= n; i ++) x[i] = -1.0 * x[i];
    sort(x + 1, x + n + 1);
    calc();
    cout << res;
    return 0;
}