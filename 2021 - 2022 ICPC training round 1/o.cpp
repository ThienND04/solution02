#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "o"
#define inf 1000000000
#define mod 1000000007
#define maxn 500001

#define LOG 32

int n, cnt = 0;
ll res[maxn];

int cntBit(ll num){
    if(num == 0) return 1;
    int x = 0;
    while(num){
        num /= 2;
        x ++;
    }
    return x;
}

void process(){
    cin >> n;
    for(int i = 1; i < LOG; i ++){
        for(int j = i; j < LOG; j ++){
            int b = (1 << j - i + 2) - 3;
            ll d = (1ll * b * b + 8 * n);
            ll x1 = (-b + sqrt(d)) / 2;
            if(cntBit(x1) == i && x1 * x1 - x1 * b - 2 * n == 0){
                x1 <<= j - i + 1;
                res[++ cnt] = x1;
            }
        }
    }
    ll x1 = (1 + sqrt(1 + 8 * n)) / 2;
    if(x1 >= 0 && x1 * x1 - x1 - 2 * n == 0){
        res[++ cnt] = x1;
    }
    if(cnt == 0) {
        cout << -1;
        return ;
    }
    sort(res + 1, res + cnt + 1);
    for(int i = 1; i <= cnt; i ++){
        cout << res[i] << "\n";
    }
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