#include <bits/stdc++.h>
using namespace std;
#define ALL(i_) i_.begin(), i_.end()
#define PB push_back
#define TASK "problemC"
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
const ll oo = 1e18;
const int mod = 1000000007;
const int maxn = 1e5 + 11;
int n, delta;
int a[maxn], pre[maxn], res[maxn];
ll dp[maxn];
struct Lines
{
    ll a, b, pos;
    ll f(ll x) { return (a * x + b); }
} seg[4 * maxn];
void Build(int node = 1, int lf = 1, int rt = 100000)
{
    seg[node] = {0, -oo};
    if (lf == rt)
        return;
    int mid = (lf + rt) >> 1;
    Build(node << 1, lf, mid);
    Build(node << 1 | 1, mid + 1, rt);
}
void Update(Lines new_lines, int node = 1, int lf = 1, int rt = 100000)
{
    int mid = (lf + rt) >> 1;
    bool inLeft = seg[node].f(lf) < new_lines.f(lf);
    bool inMid = seg[node].f(mid) < new_lines.f(mid);
    if (inMid)
        swap(new_lines, seg[node]);
    if (lf == rt)
        return;
    if (inLeft != inMid)
        Update(new_lines, node << 1, lf, mid);
    else
        Update(new_lines, node << 1 | 1, mid + 1, rt);
}
Lines Get(int x, int node = 1, int lf = 1, int rt = 100000)
{
    if (lf == rt)
        return seg[node];
    int mid = (lf + rt) >> 1;
    if (x <= mid)
    {
        Lines L = Get(x, node << 1, lf, mid);
        if (seg[node].f(x) >= L.f(x))
            return seg[node];
        else
            return L;
    }
    else
    {
        Lines R = Get(x, node << 1 | 1, mid + 1, rt);
        if (seg[node].f(x) >= R.f(x))
            return seg[node];
        else
            return R;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(TASK ".inp", "r"))
    {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin >> n >> dp[1] >> delta;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Build();
    a[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        Update({(dp[i - 1] - delta) / a[i - 1], (dp[i - 1] - delta) % a[i - 1] - delta, i - 1});
        dp[i] = dp[i - 1];
        int best = Get(a[i]).pos;
        ll val = (dp[best] - delta) / a[best] * a[i] + (dp[best] - delta) % a[best] - delta;
        if (val > dp[i])
        {
            dp[i] = val;
            pre[i] = best;
        }
    }
    cout << dp[n] << "\n";
    int cur = n;
    while (cur)
    {
        if (pre[cur] == 0)
        {
            --cur;
            continue;
        }
        int p = pre[cur];
        res[p] = (dp[p] - delta) / a[p];
        res[cur] -= res[p];
        cur = p;
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << "\n";
    return 0;
}