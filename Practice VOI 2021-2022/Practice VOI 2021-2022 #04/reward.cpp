#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "reward"
#define inf 1e9
#define mod 2021
#define maxn 1001

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

int m, n, q;
int color[maxn][maxn];
int a[maxn][maxn], s[maxn][maxn];
pii posColor[maxn * maxn];

void init(){
    reset(a);
    reset(s);
    cin >> m >> n;
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++) cin >> color[i][j];
    }
    for(int i = 0; i <= 1000000; i ++) posColor[i] = {0, 0};
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){
            if(posColor[color[i][j]].first == 0) {
                posColor[color[i][j]] = {i, j};
                a[i][j] = 1;
            }
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
}

int get(int x1, int y1, int x2, int y2){
    // if(x1 > x2 || y1 > y2) return 0;
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

bool trong(int u, int v, int x1, int y1, int x2, int y2){
    if(x1 > x2 || y1 > y2) return 0;
    return (u >= x1 && v >= y1 && u <= x2 && v <= y2);
}

bool mask[maxn * maxn];

void reclear(int x1, int y1, int x2, int y2){
    for(int i = x1; i <= x2; i ++){
        mask[color[i][y1]] = 0;
    }
    for(int i = x1; i <= x2; i ++){
        mask[color[i][y2]] = 0;
    }
    for(int i = y1; i <= y2; i ++){
        mask[color[x1][i]] = 0;
    }
    for(int i = y1; i <= y2; i ++){
        mask[color[x2][i]] = 0;
    }
}

int query(int x1, int y1, int x2, int y2){
    int res = get(x1, y1, x2, y2);
    for(int i = x1; i <= x2; i ++){
        if(mask[color[i][y1]]) continue;
        int u = posColor[color[i][y1]].first, v = posColor[color[i][y1]].second;
        if(! trong(u, v, x1, y1, x2, y2)){
            res ++;
            mask[color[i][y1]] = 1;
        } 
    }
    for(int i = x1; i <= x2; i ++){
        if(mask[color[i][y2]]) continue;
        int u = posColor[color[i][y2]].first, v = posColor[color[i][y2]].second;
        if(! trong(u, v, x1, y1, x2, y2)){
            res ++;
            mask[color[i][y2]] = 1;
        }
    }
    for(int i = y1; i <= y2; i ++){
        if(mask[color[x1][i]]) continue;
        int u = posColor[color[x1][i]].first, v = posColor[color[x1][i]].second;
        if(! trong(u, v, x1, y1, x2, y2)){
            res ++;
            mask[color[x1][i]] = 1;
        } 
    }
    for(int i = y1; i <= y2; i ++){
        if(mask[color[x2][i]]) continue;
        int u = posColor[color[x2][i]].first, v = posColor[color[x2][i]].second;
        if(! trong(u, v, x1, y1, x2, y2)){
            res ++;
            mask[color[x2][i]] = 1;
        } 
    }
    reclear(x1, y1, x2, y2);
    return res;
}   

void process(){
    reset(mask);
    cin >> q;
    int x1, y1, x2, y2;
    while(q --){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << query(x1, y1, x2, y2) << "\n";
    }
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
    process();
    return 0;
}