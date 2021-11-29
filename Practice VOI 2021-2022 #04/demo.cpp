#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "demo"
#define inf 1e9
#define mod 2021
#define maxn 101

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

#define maxVal(s) (s.empty() ? 0 : *s.rbegin())


int n;
int a[maxn];
int sum = 0;

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++) {
       cin >> a[i];
       sum += a[i];
    }
}       

bool ok(int x){
    if(sum % x) return 0;
    int c = sum / x, s = 0;
    for(int i = 1; i <= n; i ++){
        s += a[i];
        if(s == c) {
            s = 0;
            x --;
        }
    }
    return (x == 0);
}

void process(){
    init();
    int l = 1;
    for(l = n; l >= 1; l --){
        if(ok(l)) break;
    }
    cout << l << "\n";

    if(l == 1){
        cout << n;
        return;
    }
    
    // cerr << sum;
    int c = sum / l, s = 0;
    for(int i = 1; i <= n; i ++){
        s += a[i];
        if(s == c) {
            s = 0;
            cout << i << " ";
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
    process();
    return 0;
}