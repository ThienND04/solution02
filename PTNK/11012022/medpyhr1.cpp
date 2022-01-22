#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "medpyhr1"
#define inf 1e9
#define mod 1000000007
#define maxn 200001

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

namespace process{
    int n, x;
    int a[maxn];
    bool mask[maxn];

    void process(){
        cin >> n >> x;
        reset(a);
        reset(mask);
        if(n == 1){
            cout << "Yes\n1";
        }
        else{
            if(x == 1 || x == 2 * n - 1) cout << "No";
            else if(n == 2){
                cout << "Yes\n1\n2\n3";
            }
            else{
                cout << "Yes\n";
                if(x == 2){
                    a[n - 1] = x + 2; mask[x + 2] = 1;
                    a[n] = x; mask[x] = 1;
                    a[n + 1] = x - 1; mask[x - 1] = 1;
                    a[n + 2] = x + 1; mask[x + 1] = 1;
                }
                else{
                    a[n - 1] = x - 2; mask[x - 2] = 1;
                    a[n] = x; mask[x] = 1;
                    a[n + 1] = x + 1; mask[x + 1] = 1;
                    a[n + 2] = x - 1; mask[x - 1] = 1;
                }
                for(int i = 1, num = 1; i <= 2 * n - 1; i ++){
                    if(a[i]) continue;
                    while(mask[num]) num ++;
                    a[i] = num ++;
                }
                for(int i = 1; i < 2 * n; i ++) cout << a[i] << "\n";
            }
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
