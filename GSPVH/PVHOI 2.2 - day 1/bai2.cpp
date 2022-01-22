#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bai2"
#define inf 1e9
#define mod 1000000007
#define maxn 101

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

namespace process{
    int n, m;
    ll k;
    bool nt[maxn][maxn];

    int visited[maxn], q[maxn];
    bool check(){
        for(int i = 1; i < n; i ++) {
            if(nt[q[i]][q[i + 1]]) return 0;
        }
        return 1;
    }
    void Try(int pos){
        if(pos > n){
            if(check()) {
                k --;
                if(k == 0) {
                    for(int i = 1; i <= n; i ++) cout << q[i] << " ";
                    exit(0);
                }
                
            }
            return;
        }
        for(int i = 1; i <= n; i ++){
            if(! visited[i]){
                q[pos] = i;
                visited[i] = 1;
                Try(pos + 1);
                visited[i] = 0;
            }
        }
    }

    void subtask1(){
        Try(1);
    }

    ll gt(int x){
        ll res = 1;
        for(int i = 1; i <= x; i ++) res *= i;
        return res;
    }
    void subtask3(){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(visited[j]) continue;
                ll t = gt(n - i);
                if(t < 0 || t >= k) {
                    q[i] = j;
                    visited[j] = 1;
                    break;
                }
                else{
                    k -= t;
                }
            }
        }
        for(int i = 1; i <= n; i ++) cout << q[i] << " ";
    }

    void process(){
        reset(nt); reset(visited);
        cin >> n >> m >> k;
        while(m --) {
            int u, v;
            cin >> u >> v;
            nt[u][v] = nt[v][u] = 1;
        }
        if(n <= 10) return subtask1();
        if(m == 0) return subtask3();
        subtask1();
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
