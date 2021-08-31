#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 1001
#define task "bonus"
#define inf 1000000000

int n, k;
int a[maxn][maxn];
int s[maxn][maxn];

void init(){
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++) cin >> a[i][j];
    }
    memset(s, 0, sizeof(s));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r",  stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    int res = 0;
    for(int i = k; i <= n; i ++){
        for(int j = k; j <= n; j ++){
            int tmp = s[i][j] - s[i - k][j] - s[i][j - k] + s[i - k][j - k];
            res = max(res, tmp);
        }
    }
    cout << res;
    return 0;
}