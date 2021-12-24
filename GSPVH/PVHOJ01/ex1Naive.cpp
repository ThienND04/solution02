#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "ex1"
#define maxn 3001
#define inf 1000000007
#define mod 1000000007

int r, c, h, w;
int p[maxn][maxn];
int st[maxn * maxn];

int calc(int top, int left){
    int sz = 0;
    for(int i = top; i <= top + h - 1; i ++){
        for(int j = left; j <= left + w - 1; j ++){
            st[++ sz] = p[i][j];
        }
    }
    // assert(sz == h * w);
    sort(st + 1, st + sz + 1);
    return st[(sz + 1) / 2];
}

void solve(){
    int res = 0;
    for(int i = 1; i <= r - h + 1; i ++){
        for(int j = 1; j <= c - w + 1; j ++){
            res = max(res, calc(i, j));
        }
    }
    cout << res;
}

void init(){
    cin >> r >> c >> h >> w;
    for(int i = 1; i <= r; i ++){
        for(int j = 1; j <= c; j ++){
            cin >> p[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    init();
    solve();
    return 0;
}