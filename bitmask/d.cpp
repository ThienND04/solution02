#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "d"
#define maxn 15
#define bit(x, i) ((x >> i) & 1)
#define inf 1410065407

int n, m;
string s[maxn];
int f[1 << maxn][maxn], diff[maxn][maxn];

int cmp(string& s1, string& s2){
    int res = 0;
    for(int i = 0; i < n; i ++){
        if(s1[i] != s2[i]) res ++;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> m;
    for(int i = 0;i < m; i ++) cin >> s[i];
    for(int x = 0; x < 1 << m; x ++){
        for(int i = 0; i < m; i ++) f[x][i] = inf;
    }
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < m; j ++) diff[i][j] = cmp(s[i], s[j]);
    }
    for(int i = 0; i < m; i ++){
        f[1 << i][i] = 0;
        for(char c: s[i]) if(c == '1') f[1 << i][i] ++;
    }
    for(int x = 0; x < 1 << m; x ++){
        for(int i = 0; i < m; i ++){
            if(! bit(x, i)) continue;
            int u = x - (1 << i);
            for(int j = 0; j < m; j ++){
                if(! bit(u, j)) continue;
                f[x][i] = min(f[x][i], f[u][j] + diff[i][j]);
            }
        }
    }
    int res = inf;
    for(int i = 0; i < m; i ++) res=  min(res, f[(1 << m) - 1][i]);
    cout << res;
    return 0;
}