#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "bidoimau"
#define maxn 501
#define inf 1000000007
#define mod 998244353

int m, n, p;
string mp[maxn];
int blue = 0, red = 0;
int cnt_b[maxn][maxn], cnt_r[maxn][maxn];
char dao[300];

void dp(){
    blue = red = 0;
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){
            if(mp[i][j] == 'b') blue ++;
            else if(mp[i][j] == 'r') red ++;
            cnt_b[i][j] = cnt_b[i - 1][j] + cnt_b[i][j - 1] - cnt_b[i - 1][j - 1] + (mp[i][j] == 'b');
            cnt_r[i][j] = cnt_r[i - 1][j] + cnt_r[i][j - 1] - cnt_r[i - 1][j - 1] + (mp[i][j] == 'r');
        }
    }
}

void solve(){
    for(int i = 1; i <= m - p + 1; i ++){
        for(int j = 1; j <= n - p + 1; j ++){
            int res = 1e9;
            for(int u = 0; u < p; u ++){
                for(int v = 0; v < p; v ++){
                    mp[i + u][j + v] = dao[mp[i + u][j + v]];
                }
            }
            dp();
            for(int u = 1; u <= m - p + 1; u ++){
                for(int v = 1; v <= n - p + 1; v ++){
                    int b = cnt_b[u + p - 1][v + p - 1] - cnt_b[u - 1][v + p - 1] \
                            - cnt_b[u + p - 1][v - 1] + cnt_b[u - 1][v - 1];
                    int r = cnt_r[u + p - 1][v + p - 1] - cnt_r[u - 1][v + p - 1] \
                            - cnt_r[u + p - 1][v - 1] + cnt_r[u - 1][v - 1];
                    res = min(res, blue - b + r);
                }
            }
            cout << res << " ";
            // reset
            for(int u = 0; u < p; u ++){
                for(int v = 0; v < p; v ++){
                    mp[i + u][j + v] = dao[mp[i + u][j + v]];
                }
            }
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> m >> n >> p;
    dao['.'] = '.';
    dao['b'] = 'r';
    dao['r'] = 'b';
    for(int i = 1; i <= m; i ++) {
        cin >> mp[i];
        mp[i] = " " + mp[i];
    }
    solve();
    return 0;
}