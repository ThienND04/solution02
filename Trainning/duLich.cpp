#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 1001
#define task "duLich"
#define inf 1000000000
#define bit(x, i) ((x >> i) & 1)

int n, m ,k;
int l[maxn], r[maxn];
char ct[maxn];
int p[32][maxn];

void init(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++){
        cin >> l[i] >> r[i];
    }
    for(int i = 1; i <= m; i ++) cin >> ct[i];
    for(int i = 1; i <= n; i ++){
        p[0][i] = i;
        for(int j = 1; j <= m; j ++){
            if(ct[j] == 'L') p[0][i] = l[p[0][i]];
            else p[0][i] = r[p[0][i]];
        }
    }
    for(int i = 1; i <= 30; i ++){
        for(int j = 1; j <= n; j ++){
            p[i][j] = p[i - 1][p[i - 1][j]];
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
    int res = 1;
    for(int i = 30; i >= 0; i --){
        if(bit(k, i)){
            res = p[i][res];
        }
    }
    cout << res;
    return 0;
}