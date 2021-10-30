#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 100001
#define task "colorful"
#define BLOCK_SIZE 500

#define inBlock(pos) ((pos - 1) / BLOCK_SIZE + 1)

#define reset(a) memset(a, 0, sizeof(a))

int n, m;

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