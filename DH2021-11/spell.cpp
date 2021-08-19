#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "spell"
#define maxn 301
#define inf 1000000007

struct point
{
    int mn, x, y;
};


int m, n, k;
string s;
string mp[maxn];
int d[maxn][maxn][maxn];
point q[maxn * maxn * maxn];
int moveX[] = {1, 0, -1, 0};
int moveY[] = {0, 1, 0, -1};

void BFS(){
    memset(d, 60, sizeof(d));
    int l = 1, r = 0;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            if(mp[i][j] == s[0]){
                q[++ r] = {0, i, j};
                d[0][i][j] = 1;
            }
        }
    }
    while(l <= r){
        int p = q[l].mn;
        int x = q[l].x;
        int y = q[l ++].y;
        int curD = d[p][x][y];
        if(p == k - 1){
            cout << curD;
            return;
        }
        for(int i = 0; i < 4; i ++){
            int ntX = x + moveX[i];
            int ntY = y + moveY[i];
            if(ntX < 0 || ntX == m || ntY < 0 || ntY == n) continue;
            int ntP = p + (mp[ntX][ntY] == s[p + 1]);
            if(d[ntP][ntX][ntY] > curD + 1){
                d[ntP][ntX][ntY] = curD + 1;
                q[++ r] = {ntP, ntX, ntY};
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> m >> n >> k;
    cin >> s;
    for(int i = 0; i < m; i ++) {
        cin >> mp[i];
    }
    BFS();
    return 0;
}