#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "d"
#define inf 1e9
#define mod 1000000007
const int maxn = 5e4 + 5;

int n, q;
int a[maxn];
int S[maxn], cnt = 0, pos[100001], prime[100001];

bitset<maxn> bit[10000];

void mask(int val, int id, int d){
    while(val != 1){
        int x = prime[val];
        bit[pos[x]][id] = d;
        while(val % x == 0) val /= x;
    }
}

void process(){
    // init prime
    reset(prime);
    for(int i = 2; i < 100001; i ++){
        if(prime[i]) continue;
        S[++ cnt] = i;
        pos[i] = cnt;
        for(int j = i; j < 100001; j += i){
            prime[j] = i;
        }
    }
    // cerr << cnt;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) mask(a[i], i, 1);
    cin >> q;
    while(q --){
        int type, x, y, g;
        cin >> type;
        if(type == 1){
            cin >> x >> y;
            mask(a[x], x, 0);
            a[x] = y;
            mask(a[x], x, 1);
        }
        else{
            cin >> x >> y >> g;
            bitset<maxn> res;
            while(g > 1){
                int x = prime[g];
                while(g % x == 0) g /= x;
                res |= bit[pos[x]];
            }
            res >>= x;
            res <<= (maxn - 1 - y + x);
            cout << y - x + 1 - res.count() << "\n";
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