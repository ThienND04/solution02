#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 1501
#define task "putnik"

#define reset(a) memset(a, 0, sizeof(a))

void minimize(int& x, int y){
    if(x > y) x = y;
}

int n;
int f[maxn][2][maxn], d[maxn][maxn];

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++) cin >> d[i][j];
    }
}

vector<int> duoi[maxn][maxn];

void solve(){
    memset(f, 99, sizeof(f));
    f[1][1][1] = f[1][0][1] = 0;
    f[2][0][1] = f[2][1][1] = d[1][2];
    for(int i = 2; i < n; i ++){
        for(int j = 0; j < 2; j ++){
            for(int k = 1; k < i; k ++){
                int hd = (j == 0? i: k);
                int tl = (j == 0? k: i);
                minimize(f[i + 1][0][tl], f[i][j][k] + d[hd][i + 1]);
                minimize(f[i + 1][1][hd], f[i][j][k] + d[tl][i + 1]);
            }
        }
    }
    int result = 1e9;
    for(int i = 0; i < 2; i ++){
        for(int k = 1; k < n; k ++) minimize(result, f[n][i][k]);
    }
    cout << result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    solve();
    return 0;
}