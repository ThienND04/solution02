#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "ex1"
#define maxn 3030
#define inf 1000000007
#define mod 1000000007

int r, c, h, w;
int p[maxn][maxn], s[maxn][maxn];

void init()
{
    cin >> r >> c >> h >> w;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> p[i][j];
        }
    }
}

int get(int x1, int y1, int x2, int y2){
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

int get(int x, int y){
    return get(x, y, x + h - 1, y + w - 1);
}

void build(int x){
    for(int i = 1; i <= r; i ++){
        for(int j = 1; j <= c; j ++){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (p[i][j] >= x? 1: -1);
        }
    }
}

bool check(int x){
    // check median greater or equal x
    for(int i = 1; i <= r - h + 1; i ++){
        for(int j = 1; j <= c - w + 1; j ++){
            if(get(i, j, i + h - 1, j + w - 1) > 0) return true;
        }
    }
    return false;
}

void solve(){
    int left = 1, right = r * c + 1;
    while(right - left > 1){
        int mid = (right + left) >> 1;
        build(mid);
        if(check(mid)) left = mid;
        else right = mid;
    }
    cout << left;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // if (fopen(task ".inp", "r"))
    // {
    //     freopen(task ".inp", "r", stdin);
    //     freopen(task ".out", "w", stdout);
    // }
    init();
    solve();
    return 0;
}