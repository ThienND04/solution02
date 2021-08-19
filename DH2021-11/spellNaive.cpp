#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "spell"
#define maxn 301
#define inf 1000000007

int m, n, k;
string s, hcn[maxn];
vector<pii> cc[maxn];
int dp[maxn][90001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> m >> n >> k >> s;
    for(int i = 0; i < m; i ++) cin >> hcn[i];
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            cc[hcn[i][j] - 'A'].push_back({i, j});
        }
    }
    for(int i = 0; i < k; i ++){
        for(int j = 0; j < m * n; j ++) dp[i][j] = inf;
    }
    for(int i = 0; i < cc[s[0] - 'A'].size(); i ++) dp[0][i] = 1;
    for(int i = 1; i < k; i ++){
        int x = s[i - 1] - 'A';
        int y = s[i] - 'A';
        for(int j = 0; j < cc[x].size(); j ++){
            pii p = cc[x][j];
            for(int t = 0; t < cc[y].size(); t ++){
                pii p2 = cc[y][t];
                int tmp;
                if(p.first == p2.first && p.second == p2.second) tmp = dp[i - 1][j] + 1;
                else tmp = dp[i - 1][j] + abs(p.first - p2.first) + abs(p.second - p2.second);
                dp[i][t] = min(dp[i][t], tmp);
            }
        }
    }
    int res = inf;
    for(int i = 0;i < cc[s[k - 1] - 'A'].size(); i ++) res = min(res, dp[k - 1][i]);
    cout << res;
    return 0;
}