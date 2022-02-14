#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "addition"
#define inf 1e9
#define mod 1000000007
#define maxn 26

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
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

int t;
int a, b, c, n;

int bruteForce(){
    int res = 0;

    for(int z = 0; z * c <= n; z ++){
        for(int y = 0; z * c + b * y <= n; y ++){
            int tmp = n - (z * c + b * y);
            if(tmp % a == 0) res ++;
        }
    }
    return res;
}

vector<int> cntMod[1000000];

void init(){
    for(int i = 0; i < c; i ++){
        cntMod[i].clear();
    }

    for(int i = 0; i * b <= n; i ++){
        int x = (i * b) % c;
        cntMod[x].push_back(i * b);
    }
}

// by + cz = x
// z = (x - by) / c

// by <= x

bool ok(int x, int i){
    if(i == 0) return 1;
    return (cntMod[x % c][i - 1] <= x);
}

int calc(int x){
    int d = x % c;
    int l = 0, r = cntMod[d].size() + 1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(ok(x, mid)) l = mid;
        else r = mid;
    }
    return l;
}

ll solve(){
    init();
    ll res = 0;
    for(int x = 0; x * a <= n; x ++){
        res += calc(n - a * x);
    }

    return res;
}

namespace process{
    void process(){
        cin >> t;
        while(t --){
            cin >> a >> b >> c >> n;
            if(a > c) swap(a, c);
            if(a > b) swap(a, b);
            if(b > c) swap(b, c);

            if(n <= 1e6 || c >= 1e6) cout << bruteForce() << "\n";
            else cout << solve() << "\n";
            //cout << solve() << "\n";
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
