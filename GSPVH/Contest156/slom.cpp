#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 100001
#define task "slom"

#define reset(a) memset(a, 0, sizeof(a))

#define LOG 31

#define bit(x, i) ((x >> i) & 1)

int n, k;
string s;
int Next[maxn];
int nt[maxn][LOG];

void init(){
    cin >> k >> s;
    n = s.size();
    s = " " + s;
    int l = 1, r = n, tmp = 0;
    for(int i = 1; i <= n / 2; i ++){
        Next[l ++] = ++tmp;
        Next[r --] = ++ tmp;
    }
    if(l == (n % 2 == 0? n / 2: n / 2 + 1)) Next[l] = ++ tmp;
    // for(int i = 1; i <= n; i ++) cerr << Next[i] << " ";
    // cerr << endl;
    for(int i = 1; i <= n; i ++) nt[i][0] = Next[i];
    for(int x = 1; x <= 30; x ++){
        for(int i = 1; i <= n; i ++){
            nt[i][x] = nt[nt[i][x - 1]][x - 1];
        }
    }
    for(int i = 1; i <= n; i ++) Next[i] = i;
}

void solve(){
    for(int i = 30 ; i >= 0; i --){
        if(bit(k, i)){
            for(int j = 1; j <= n; j ++) Next[j] = nt[Next[j]][i];
        }
    }
    for(int i = 1; i <= n; i ++) cout << s[Next[i]];
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
    init();
    solve();
    return 0;
}