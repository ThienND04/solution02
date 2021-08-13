#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 200005
#define MOD
#define Task "g"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int val[maxn * 8];
int ST[maxn * 8];
vi v;
int n;
struct data{
    int y, l, r, t;
};
vector <data> doc;
bool cmp(data a, data b)
{
    return a.y < b.y;
}
void day(int nut, int l, int r)
{
    if (val[nut]) ST[nut] = v[r] - v[l];
    else if (l + 1 >= r) ST[nut] = 0;
    else ST[nut] = ST[nut * 2] + ST[nut * 2 + 1];
}
void update(int nut, int l, int r, int u, int v, int w)
{
    if (l >= u && r <= v)
    {
        val[nut] += w;
        day(nut, l, r);
        return;
    }
    int mid = (l + r)/2;
    if (u < mid) update(nut * 2, l, mid, u, v, w);
    if (v > mid) update(nut * 2 + 1, mid, r, u, v, w);
    day(nut, l, r);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        doc.PB({y1, x1, x2, 1});
        doc.PB({y2, x1, x2, -1});
        v.PB(x1);
        v.PB(x2);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    sort(doc.begin(), doc.end(), cmp);
    ll res = 0;
    for (int i = 0; i < sz(doc) - 1; i ++)
    {
        int l = lower_bound(v.begin(), v.end(), doc[i].l) - v.begin();
        int r = lower_bound(v.begin(), v.end(), doc[i].r) - v.begin();
        update(1, 0, sz(v), l, r, doc[i].t);
        res += (1ll * ST[1] * (doc[i + 1].y - doc[i].y));
    }
    cout << res;
}