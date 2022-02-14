#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "robot"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

namespace caculate{
    template<class T>
    void add(T& x, T y){
        x += y;
        if(x >= mod) x -= mod;
    }
    template<class T>
    void sub(T& x, T y){
        x -= y;
        if(x < 0) x += mod;
    }
    template<class T>
    void maximize(T& x, T y){
        if(x < y) x = y;
    }
    template<class T>
    void minimize(T& x, T y){
        if(x > y) x = y;
    }
}

using namespace caculate;

int n, x, y, z;
int a[maxn], b[maxn];

namespace subtask1{
    bool check(){
        for(int i = 1; i <= n; i ++){
            if(a[i] > 1) return 0;
            if(b[i] > 1) return 0;
        }
        return (n <= 20);
    }

    int pos0[11], pos1[11], num[2];
    bool visited[2][11];
    int h[2][11];

    ll res  = 1e18;

    void calc(){
        ll tt = num[0] * y + num[1] * x;
        minimize(res, tt);
        for(int i = 1; i <= min(num[0], num[1]); i ++){
            tt -= (x + y);
            tt += abs(h[0][i] - h[1][i]) * z;
            minimize(res, tt);
        }
    }

    void Try2(int pos, int N, int arr[], int hv[]){
        if(pos > N){
            calc();
            return;
        }
        for(int i = 1; i <= num[1]; i ++){
            if(! visited[1][i]){
                visited[1][i] = 1;
                hv[pos] = pos1[i];
                Try2(pos + 1, num[1], pos1, hv);
                visited[1][i] = 0;
            }
        }
    }

    void Try(int pos, int N, int arr[], int hv[]){
        if(pos > N){
            return Try2(1, num[1], pos1, h[1]);
        }
        for(int i = 1; i <= num[0]; i ++){
            if(! visited[0][i]){
                visited[0][i] = 1;
                hv[pos] = pos0[i];
                Try(pos + 1, num[0], pos0, hv);
                visited[0][i] = 0;
            }
        }
    }

    void subtask1(){
        num[0] = num[1] = 0;
        for(int i = 1; i <= n; i ++){
            if(a[i] != b[i]){
                if(a[i] == 0) pos0[++ num[0]] = i;
                else pos1[++ num[1]] = i;
            }
        }
        reset(visited);
        Try(1, num[0], pos0, h[0]);

        cout << res;
    }

}

namespace process{
    void process(){
        cin >> n >> x >> y >> z;
        for(int i = 1; i <= n; i ++) cin >> a[i];
        for(int i = 1; i <= n; i ++) cin >> b[i];

        if(subtask1::check()) return subtask1::subtask1();
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
