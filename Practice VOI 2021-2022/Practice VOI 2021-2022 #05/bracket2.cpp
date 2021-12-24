#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bracket"
#define inf 1e9
#define mod 2021
#define maxn 5001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

#define maxVal(s) (s.empty() ? 0 : *s.rbegin())

template<class T>
void maximize(T& x, T y){
    if(x < y) x = y;
}

int n;
int a[maxn];
ll f[maxn][maxn];

void process(){
    reset(f);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++){
        for(int j = 0; j < i; j ++){
            maximize(f[i][j], f[i - 1][j]);
            maximize(f[i][j + 1], f[i - 1][j] + a[i]);
            if(j) maximize(f[i][j - 1], f[i - 1][j] - a[i]);
        }
    }
    cout << f[n][0];
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