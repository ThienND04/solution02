#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bracket"
#define inf 1e9
#define mod 2021
#define maxn 100001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

#define maxVal(s) (s.empty() ? 0 : *s.rbegin())

template<class T>
void maximize(T& x, T y){
    if(x < y) x = y;
}

int n, a[maxn];

namespace subtask1{
    ll res = 0;
    void Try(int pos, ll sum,  int t){
        if(pos == n + 1){
            if(t == 0) maximize(res, sum);
            return;
        }
        Try(pos + 1, sum + a[pos], t + 1);
        if(t > 0) Try(pos + 1, sum - a[pos], t - 1);
        Try(pos + 1, sum, t);
    }

    void subtask1(){
        Try(1, 0, 0);
        cout << res;
    }
}

namespace subtask2{
    ll f[5001][5001];

    void subtask2(){
        for(int i = 0; i <= n; i ++){
            for(int j = 0; j <= n; j ++) f[i][j] = -(1e18);
        }
        f[0][0] = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j <= i; j ++){
                f[i][j] = f[i - 1][j];
                if(j > 0) maximize(f[i][j], f[i - 1][j - 1] + a[i]);
                if(j < i) maximize(f[i][j], f[i - 1][j + 1] - a[i]);
            }
        }
        cout << f[n][0];
    }
}

namespace subtask3{
    int t = 0;
    
    bool check(){
        for(int i = 1; i <= n; i ++){
            if(a[i]) t ++;
        }
        return (t <= 1000);
    }

    bool ok[maxn];
    int b[maxn];

    void init(){
        for(int i = 1; i <= n; i ++){
            if(a[i] != 0) ok[i] = 1;
        }
        for(int i = 1; i <= t && a[i] == 0; i ++){
            ok[i] = 1;
        }

        for(int i = n; i >= n - t + 1 && a[i] == 0; i --){
            ok[i] = 1;
        }
        int tmp = 0;
        for(int i = 1; i <= n; i ++){
            if(tmp > 0 && a[i] == 0){
                ok[i] = 1;
                tmp --;
            }
            if(a[i] != 0) tmp ++;
        }
        tmp = 0;
        for(int i = n; i >= 1; i --){
            if(tmp > 0 && a[i] == 0){
                ok[i] = 1;
                tmp --;
            }
            if(a[i] != 0) tmp ++;
        }
        tmp = 0;
        for(int i = 1; i <= n; i ++){
            if(ok[i]) b[++ tmp] = a[i];
        }
        for(int i = 1; i <= tmp; i ++) a[i] = b[i];
        n = tmp;
    }

    void subtask3(){
        init();
        return subtask2::subtask2();
    }
}

namespace subtask4{

    void subtask4(){
        ll res = 0;

        priority_queue<int> q;

        for(int i = 1; i <= n; i ++){
            q.push(a[i]);
            if(! q.empty() && q.top() - a[i] >= 0){
                res += q.top() - a[i];
                q.pop();
                q.push(a[i]);
            }
        }
        cout << res;
    }
}

void process(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];

    //if(n <= 10) return subtask1::subtask1();
    //if(n <= 1000) return subtask2::subtask2();
    //if(subtask3::check()) return subtask3::subtask3();
    return subtask4::subtask4();
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
    process();
    return 0;
}