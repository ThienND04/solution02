//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define Random(lf, rt) (lf + rand() % (rt - lf + 1))
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define maxn 100005
#define MOD
#define all(x) x.begin(), x.end()
#define cosdo(x) cos((x)/180 * Pi)
#define sindo(x) sin((x)/180 * Pi)
#define tando(x) tan((x)/180 * Pi)
#define cotdo(x) 1/tando(x)
#define Task "assign"
using namespace std;
const double Pi = acos(-1);
typedef long long ll;
typedef long double ld;
vi ke[maxn];
int m, n;
int matchX[maxn], matchY[maxn];
bool dd[maxn];
int cur;
bool dfs(int u)
{
    if (dd[u]) return 0;
    dd[u] = 1;
    for (int v : ke[u])
        if(matchY[v] == 0 || dfs(matchY[v]))
        {
            matchY[v] = u;
            matchX[u] = v;
            return 1;
        }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> m >> n;
    int u, v;
    while(cin >> u >> v)
        ke[u].PB(v);
    for (int i : ke[1]) cout << i << " ";

}