#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 100001
#define task "tournament"

#define reset(a) memset(a, 0, sizeof(a))

int n, c, r;
int k[maxn];
int s[maxn], e[maxn];

void init(){
    cin >> n >> c >> r;
    for(int i = 1; i < n; i ++ ) cin >> k[i];
    for(int i = 1; i <= c; i ++) {
        cin >> s[i] >> e[i];
    }
}

void solve(){
    
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