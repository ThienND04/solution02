#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "pokemon"
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

int t, n, m, k;

namespace subtask1{
    ll ls[10000000];
    int num = 0;

    void Try(int idSkill, ll s = 0){
        if(idSkill == 0){
            ls[++ num] = s;
            return;
        }

        for(int i = 0; i <= m; i ++){
            Try(idSkill - 1, s + 1ll * i * idSkill);
        }
    }
    ll subtask1(){
        ll res = 0;
        Try(n, 0);
        sort(ls + 1, ls + num + 1);
        for(int i = 1; i <= k; i ++) res += ls[i];
        return res;
    }
}

namespace process{

    void process(){
        cin >> t;
        while(t --){
            cin >> n >> m >> k;
            cout << subtask1::subtask1() << "\n";
        }
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
