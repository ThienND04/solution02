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
int blue = 0;
int f[maxn][maxn]; 
int bestBot[maxn], bestTop[maxn], bestLeft[maxn], bestRight[maxn];

int get(int x, int y, int i, int j){
    return f[i][j] - f[x - 1][j] - f[i][y - 1] + f[x - 1][y - 1];
}

int get(int x, int y){
    return get(x, y, x + p - 1, y + p - 1);
}

void init(){
    blue = 0;
    memset(bestBot, 99, sizeof(bestBot));
    memset(bestLeft, 99, sizeof(bestLeft));
    memset(bestRight, 99, sizeof(bestRight));
    memset(bestTop, 99, sizeof(bestTop));
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + (mp[i][j] == 'r') - (mp[i][j] == 'b');
            blue += (mp[i][j] == 'b');
        }
    }
    for(int i = 1; i <= m - p + 1; i ++){
        for(int j = 1; j <= n - p + 1; j ++){
            int top = i, bot = i + p - 1;
            int left = j, right = j + p - 1;
            int tmp = get(i, j);
            bestTop[bot] = min(bestTop[bot], tmp);
            bestBot[top] = min(bestBot[top], tmp);
            bestLeft[right] = min(bestLeft[right], tmp);
            bestRight[left] = min(bestRight[left], tmp);
        }
    }
    for(int i = 2; i <= m; i ++) bestTop[i] = min(bestTop[i - 1], bestTop[i]);
    for(int i = m - 1; i >= 1; i --) bestBot[i] = min(bestBot[i + 1], bestBot[i]);
    for(int j = 2; j <= n; j ++) bestLeft[j] = min(bestLeft[j], bestLeft[j - 1]);
    for(int j = n - 1; j >= 1; j --) bestRight[j] = min(bestRight[j], bestRight[j + 1]);
}

void solve(){
    for(int x = 1; x <= m - p + 1; x ++){
        for(int y = 1; y <= n - p + 1; y ++){
            int res = blue;
            int top = x, bot = x + p - 1, left = y, right = y + p - 1;
            int d1 = get(x, y);
            res = min(res, d1 + blue + bestTop[top - 1]);
            res = min(res, d1 + blue + bestBot[bot  + 1]);
            res = min(res, d1 + blue + bestLeft[left - 1]);
            res = min(res, d1 + blue + bestRight[right + 1]);
            
            for(int i = max(x - p + 1, 1); i <= min(x + p - 1, m - p + 1); i ++){
                for(int j = max(y - p + 1, 1); j <= min(y + p - 1, n - p + 1); j ++){
                    int interTop = max(top, i), interBot = min(bot, i + p - 1);
                    int interLeft = max(left, j), interRight = min(right, j + p - 1);
                    int d2 = blue + d1 + get(i, j) - 2 * get(interTop, interLeft, interBot, interRight);
                    res = min(res, d2);
                }
            }

            cout << res << " ";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> m >> n >> p;
    // cerr << m << " " << n;
    for(int i = 1; i <= m; i ++) {
        cin >> mp[i];
        mp[i] = " " + mp[i];    
    }
    init();
    solve();
    return 0;
}