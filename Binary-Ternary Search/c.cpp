#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef long long ll;
#define task "c"
#define inf 2000000
#define maxn 1001

int n;
ll x[maxn], y[maxn];

double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

pdd calc(double a, double b, double c)
{
    double x1, x2;
    double delta = b * b - 4 * a * c;
    if (delta < 0)
    {
        x1 = inf;
        x2 = -inf;
    }
    else if (delta == 0)
    {
        x1 = x2 = -b / (2 * a);
    }
    else
    {
        delta = sqrt(delta);
        x1 = (-b - delta) / (2 * a);
        x2 = (-b + delta) / (2 * a);
    }
    return {x1, x2};
}

bool check(double ra)
{
    double l = -inf, r = inf;
    for (int i = 1; i <= n; i++)
    {
        pdd gh = calc(1, 2 * x[i], x[i] * x[i] - 2 * ra* y[i] + y[i] * y[i]);
        l = max(l, gh.first);
        r = min(r, gh.second);
    }
    return l <= r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    double l = 0, r = 1e13;
    double delta = 0.0001;
    while (r - l > delta)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << fixed << setprecision(3) << r;
    return 0;
}