#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "b"
#define inf 1e9
#define mod 1000000007
#define maxn 101

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

namespace caculate
{
    template <class T>
    void add(T &x, T y)
    {
        x += y;
        if (x >= mod)
            x -= mod;
    }
    template <class T>
    void sub(T &x, T y)
    {
        x -= y;
        if (x < 0)
            x += mod;
    }
    template <class T>
    void maximize(T &x, T y)
    {
        if (x < y)
            x = y;
    }
    template <class T>
    void minimize(T &x, T y)
    {
        if (x > y)
            x = y;
    }
}

using namespace caculate;

int n;
int a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];

void swapCol(int x, int y){
    for(int i = 1; i <= n; i ++) swap(c[i][x], c[i][y]);
}

void swapRow(int x){
    for(int i = 1; i <= n; i ++) c[x][i] = 1 - c[x][i];
}

namespace subtask1{
    int num = 0;
    pii ls[1001];

    int res = inf;
    vector<pii> ans;

    bool ok(){
        int cnt = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(c[i][j] != b[i][j]) cnt ++;
            }
        }
        //cerr << cnt << "\n";
        return (cnt <= 1);
    }

    void Try(int pos){
        if(pos > n){
            if(ok()){
                if(res > num){
                    res = num;
                    ans.clear();
                    for(int i = 1; i <= num; i ++){
                        ans.push_back(ls[i]);
                    }
                }
            }
            return;
        }

        Try(pos + 1);

        for(int i = pos + 1; i <= n; i ++){
            for(int j = i - 1; j >= pos; j --){
                swapCol(j, j + 1);
                ls[++ num] = {1, j};
            }

            Try(pos + 1);

            for(int j = pos; j < i; j ++){
                swapCol(j, j + 1);
                num --;
            }
        }
    }

    void subtask1(){
        for(int x = 0; x < (1 << n); x ++){
            num = 0;
            for(int i = 1; i <= n; i ++){
                if(bit(x, i - 1)) {
                    ls[++ num] = {2, i};
                    for(int j = 1; j <= n; j ++) c[i][j] = 1 - a[i][j];
                }
                else{
                    for(int j = 1; j <= n; j ++) c[i][j] = a[i][j];
                }
            }
            Try(1);
        }

        if(res == inf) cout << -1;
        else{
            cout << res << "\n";
            for(pii p: ans) cout << p.first << " " << p.second << "\n";
        }
    }
}

namespace subtask2{
    int num = 0;
    pii ls[1001];
    int res = inf;
    vector<pii> ans;

    void calc(){
        int cnt1 = 0;
        for(int i = 1; i <= n; i ++){
            int diff = 0;
            for(int j = 1; j <= n; j ++){
                if(c[i][j] != b[i][j]) ++ diff;
            }
            if(min(diff, n - diff) == 1) {
                cnt1 ++;
            }
            if(min(diff, n - diff) > 1) return;
        }
        if(cnt1 >= 2) return;
        int cnt = 1 - cnt1;
        for(int i = 1; i <= n; i ++){
            int diff = 0;
            for(int j = 1; j <= n; j ++){
                if(c[i][j] != b[i][j]) ++ diff;
            }
            if(diff == 0){
                
            }
            else if(min(diff, n - diff) == 1){
                if(diff != 1){
                    ls[++ num] = {2, i};
                }
            }
            else if(diff == 1 && cnt > 0){
                
            }
            else {
                ls[++ num] = {2, i};
            }
        }


        if(res > num){
            res = num;
            ans.clear();
            for(int i = 1; i <= num; i ++){
                ans.push_back(ls[i]);
            }
        }
    }

    void Try(int pos){
        if(pos > n){
            return calc();
        }

        Try(pos + 1);

        for(int i = pos + 1; i <= n; i ++){
            for(int j = i - 1; j >= pos; j --){
                swapCol(j, j + 1);
                ls[++ num] = {1, j};
            }

            Try(pos + 1);

            for(int j = pos; j < i; j ++){
                swapCol(j, j + 1);
                num --;
            }
        }
    }

    void subtask2(){
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) c[i][j] = a[i][j];
        }
        Try(1);
        if(res == inf) cout << -1;
        else{
            cout << res << "\n";
            for(pii p: ans) cout << p.first << " " << p.second << "\n";
        }
    }
}

namespace subtask3{
    int sc[maxn], sb[maxn];

    void calc(){
        reset(sc);
        for(int j = 1; j <= n; j ++){
            for(int i = 1; i <= n; i ++){
                if(c[i][j] == 1) sc[j] += (1 << i - 1);
            }
        }
    }

    void Try2(int pos){
        if(pos > n){
            calc();
            return;
        }
        for(int i = pos; i <= n; i ++){
            swapRow(i);
            Try2(i + 1);
            swapRow(i);
        }
    }

    void subtask3(){
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++) c[i][j] = a[i][j];
        }
        reset(sb);
        for(int j = 1; j <= n; j ++){
            for(int i = 1; i <= n; i ++){
                if(b[i][j] == 1) sb[j] += (1 << i - 1);
            }
        }
        Try2(1);
    }
}

namespace process
{
    void process()
    {
        cin >> n;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++) {
                cin >> b[i][j];
            }
        }
        
        //if(n <= 4) return subtask1::subtask1();
        if(n <= 10) return subtask2::subtask2();
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
    process::process();
    return 0;
}
