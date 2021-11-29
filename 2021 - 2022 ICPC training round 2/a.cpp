#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "a"
#define inf 1e9
#define mod 2021
#define maxn 20001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

#define maxVal(s) (s.empty() ? 0 : *s.rbegin())

template<class T>
void maximize(T& x, T y){
    if(x < y) x = y;
}

template<class T>
void minimum(T& x, T y){
    if(x > y) x = y;
}

int n, q;
int a[maxn];
ll f[maxn];

void prepare(){
    for(int i = 0; i <= n; i ++) f[i] = a[i];
    for(int i = n + 1; i < maxn; i ++){
        f[i] = 1e18;
        for(int j = 1; j < i; j ++){
            minimum(f[i], f[j] + f[i - j]);
        }
    }
}

ll query(int k){
    if(k < maxn) return f[k];
    ll res = 1e18;
    for(int i = n + 1; i < maxn; i ++){
        int sl = k / i;
        minimum(res, f[i] * sl + f[k - sl * i]);
    }
    return res;
}

void process(){
    cin >> n >> q;
    a[0] = 0;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    prepare();
    while(q --){
        int k;
        cin >> k;
        cout << query(k) << "\n";
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