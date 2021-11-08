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
int a[maxn][maxn];

bool co[1000001];
int cnt[maxn][maxn][21];
int ans[91][91][91][91];

void init(){
    reset(co);
    cin >> m >> n;
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){   
            cin >> a[i][j];
        }
    }
}

void sub1(){
    while(q --){
        int x1, y1, x2, y2, cnt = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i = x1; i <= x2; i ++){
            for(int j = y1; j <= y2; j ++){
                if(! co[a[i][j]]){
                    co[a[i][j]] = 1;
                    cnt ++;
                }
            }
        }
        cout << cnt << "\n";
        for(int i = x1; i <= x2; i ++){
            for(int j = y1; j <= y2; j ++){
                if(co[a[i][j]]){
                    co[a[i][j]] = 0;
                }
            }
        }
    }
}

void sub2(){
    for(int x1 = 1; x1 <= m; x1 ++){
        for(int y1 = 1; y1 <= n; y1 ++){
            int d = 0;
            for(int x2 = x1; x2 <= m; x2 ++){
                for(int y2 = y1; y2 <= n; y2 ++){
                    if(! co[a[x2][y2]]) {
                        co[a[x2][y2]] = 1;
                        d ++;
                    }
                    // if(! d) cerr << 0;
                    ans[x1][y1][x2][y2] = d;
                }
            }
            // clean co
            for(int x2 = x1; x2 <= m; x2 ++){
                for(int y2 = y1; y2 <= n; y2 ++){
                    co[a[x2][y2]] = 0;
                }
            }
        }
    }
    while(q --){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << ans[x1][y1][x2][y2] << "\n";
    }
}

void sub3(){
    reset(cnt);
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){
            for(int t = 1; t <= 20; t ++) {
                cnt[i][j][t] = cnt[i][j - 1][t] + cnt[i - 1][j][t] - cnt[i - 1][j - 1][t] + (a[i][j] == t);
            }
        }
    }
    while(q --){
        int x1, y1, x2, y2, res = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for(int t = 1; t <= 20; t ++){
            int tmp = cnt[x2][y2][t] - cnt[x1 - 1][y2][t] - cnt[x2][y1 - 1][t] + cnt[x1 - 1][y1 - 1][t];
            res += (tmp > 0);
        }
        cout << res << "\n";
    }
}

bool checkS3(){
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){
            if(a[i][j] > 20) return 0;
        }
    }
    return 1;
}

void process(){
    cin >> q;
    if(m <= 90 && n <= 90) {
        return sub2();
    }
    if(checkS3()){
        return sub3();
    }
    return sub1();
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