#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 100001
#define task "data"

#define reset(a) memset(a, 0, sizeof(a))

int n, x;
int s[maxn];

void init(){
    cin >> n >> x;
    for(int i = 1; i <= n; i ++) cin >> s[i];
    sort(s + 1, s + n + 1);
}

void solve(){
    int res = 0;
    int left = 1, right = n;
    while(right > left){
        if(s[left] + s[right] <= x){
            left ++;
            right --;
        }
        else {
            right --;
        }
        res ++;
    }
    if(left == right) res ++;
    cout << res;
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