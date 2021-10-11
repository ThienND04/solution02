#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "distinct"
#define inf 1e9
#define mod 1000000007
#define maxn 250001
#define delta 0.0000001

#define bit(x, i) ((x >> i) & 1)

int m, n;

vector<vector<int>> board;
int cnt[maxn];

void init(){
    cin >> m >> n;
    vector<int> v;
    v.reserve(n * m);
    if(m > n){
        swap(m, n);
        board.resize(m + 1);
        for(int i = 0; i <= m; i ++) board[i].resize(n + 1, 0);
        for(int j = 1; j <= n; j ++){
            for(int i = 1; i <= m; i ++){
                cin >> board[i][j];
                v.push_back(board[i][j]);
            }
        }
    }
    else {
        board.resize(m + 1);
        for(int i = 0; i <= m; i ++) board[i].resize(n + 1, 0);
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                cin >> board[i][j];
                v.push_back(board[i][j]);
            }
        }
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){
            board[i][j] = lower_bound(v.begin(), v.end(), board[i][j]) - v.begin() + 1;
        }
    }
}

void solve(){
    int res = 0;
    for(int bot = 1; bot <= m; bot ++){
        for(int top = bot; top <= m; top ++){
            reset(cnt);
            int right = 0;
            for(int left = 1; left <= n; left ++){
                right = max(right, left - 1);
                if(left > 1){
                    for(int i = bot; i <= top; i ++) {
                        //assert(board[i][left - 1] < 250001);
                        cnt[board[i][left - 1]] --;
                    }
                }
                while(right < n){
                    bool ok = 1;
                    for(int i = bot; i <= top; i ++) {
                        if(cnt[board[i][right + 1]]) ok = 0;
                        cnt[board[i][right + 1]] ++;
                    }
                    if(! ok) {
                        for(int i = bot; i <= top; i ++) {
                            cnt[board[i][right + 1]] --;
                        }
                        break;
                    }
                    right ++; 
                }
                if(right < left) continue;
                res = max(res, (top - bot + 1) * (right - left + 1));
            }
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    solve();
    return 0;
}