#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 501
#define task "vboard"
#define inf 1000000000

int n, q;
int a[maxn][maxn], type[maxn][maxn], s[2][maxn][maxn];

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> a[i][j];
            if(type[i - 1][j] || type[i][j - 1]) type[i][j] = 0;
            else type[i][j] = 1;
        }
    }
    for(int t = 0; t < 2; t ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j++){
                s[t][i][j] = s[t][i - 1][j] + s[t][i][j - 1] - s[t][i - 1][j - 1];
                if(t == type[i][j]) s[t][i][j] += a[i][j];
            }
        }
    }
}

int get(int x, int y, int u, int v, int t){
    return s[t][u][v] - s[t][u][y - 1] - s[t][x - 1][v] + s[t][x - 1][y - 1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r",  stdin);
        freopen(task ".out", "w", stdout);
    }
    init(); 
    cin >> q;
    for(int i = 0; i < q; i ++){
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        int res = abs(get(x, y, u, v, 0) - get(x, y, u, v, 1));
        cout << res << "\n";
    }
    return 0;
}