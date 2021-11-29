#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "c"
#define inf 1e9
#define mod 2021
#define maxn 101

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

int n, k, d, s;

void process(){
    cin >> n >> k >> d >> s;
    double res;
    if(n == k){
        if(d == s) res = s;
        else {
            cout << "impossible";
            return;
        }
    }
    else res = 1.0 * (n * d - k * s) / (n - k);
    if(res >= 0 && res <= 100) cout << fixed << setprecision(7) << res;
    else cout << "impossible";
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