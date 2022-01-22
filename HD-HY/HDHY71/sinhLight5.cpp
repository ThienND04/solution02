 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "light5"
#define inf 1e9
#define mod 1000000007
#define maxn 5001

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
    int n, m, q;
    pii ed[maxn * maxn];

    int Rand(int gh){
        return rand() % gh;
    }

    void process(){
        cin >> n >> m >> q;
        cout << n << " " << m << " " << q << "\n";
        int cnt = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = i + 1; j <= n; j ++){
                ed[++ cnt] = {i, j};
            }
        }
        random_shuffle(ed + 1, ed + cnt + 1);
        for(int i = 1; i <= m; i ++){
            cout << ed[i].first << " " << ed[i].second << " " << Rand(2) << "\n";
        }
        while(q --){
            cout << Rand(n) + 1 << " ";
        }
    }
}

int main()
{
    srand(clock());
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task ".inp", "w", stdout);
    process::process();
    return 0;
}
