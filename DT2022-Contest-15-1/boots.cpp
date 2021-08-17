#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "boots"
#define maxn 100001
#define bit(x, i) ((x >> i) & 1)
#define inf 1000000000000000

int n, m;
int h[maxn], b[maxn], d[maxn];

bool check(int g){
    int pre = -1;
    for(int i = 1; i <= n; i ++){
        if(h[i] <= b[g]) {
            if(pre != -1 && i - pre > d[g]){
                return 0;
            }
            pre = i;
        }
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> h[i];
    }
    for(int i = 1; i <= m; i ++) cin >> b[i] >> d[i];
    for(int i = 1; i <= m; i ++){
        if(check(i)) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}