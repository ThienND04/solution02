#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "d"
#define inf 1e9
#define maxn 20005
#define delta 0.0000001

struct pos
{
    double x, y;
};

struct line
{
    double a, b, c;
};

int n, m;
double s[3];
pos p[maxn], a[maxn];
line border, L[maxn];
bool in[maxn];

pos giao(pos L, pos R, line d1, line d2)
{
    double check = d1.a * d2.b - d2.a * d1.b;
    if (!check)
    {
        return {inf, inf};
    }
    else
    {
        pos res;
        res.x = (d2.b * d1.c - d1.b * d2.c) / check;
        res.y = (d1.a * d2.c - d2.a * d1.c) / check;
        if (res.x < L.x || res.x > R.x)
            return {inf, inf};
        return res;
    }
}

line getLine(pos p1, pos p2)
{
    pos u = {p2.y - p1.y, p1.x - p2.x};
    double c = (u.x * p2.x + u.y * p2.y);
    return {u.x, u.y, c};
}

int In(pos u)
{
    double y = -(border.a * u.x - border.c) / border.b;
    if (u.y > y)
        return 0;
    return 1;
}

// int In(pos u)
// {
//     double y = border.a * u.x + border.b * u.y - border.c;
//     if (y > 0)
//         return 1;
//     return 0;
// }

void init()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i].x >> p[i].y;
    border = getLine(p[1], p[n]);
}

void solve()
{
    m = 0;
    for (int i = 1; i < n; i++)
    {
        L[i] = getLine(p[i], p[i + 1]);
    }
    for (int i = 1; i < n; i++)
    {
        a[++m] = p[i];
        pos tmp = giao(p[i], p[i + 1], L[i], border);
        if (tmp.x == inf)
            continue;
        a[++m] = tmp;
        in[m] = 1;
    }
    n = m;
    int t = 1, ls = 1;
    double cur = 0;
    for (int i = 1; i <= n; i++)
    {
        double new_area = (a[i + 1].x - a[i].x) * (a[i + 1].y + a[i].y);
        if (in[i])
        {
            cur += (a[ls].x - a[i].x) * (a[i].y + a[ls].y);
            s[t] += abs(cur);
            cur = new_area;
            ls = i;
        }
        else
        {
            t = In(a[i]);
            cur += new_area;
        }
    }
    s[0] /= 2;
    s[1] /= 2;
    cout << fixed << setprecision(4) << s[1] << "\n"
         << s[0];
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