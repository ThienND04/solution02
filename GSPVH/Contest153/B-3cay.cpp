#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "3cay"
#define inf 1e9
#define mod 1000000007
#define maxn 20

#define B 1000007

#define bit(x, i) ((x >> i) & 1)

int subtask, n1, n2, n3;
vector<int> adj[maxn];
int treeSize[maxn], hight[maxn];
ll sumDist[maxn];
ll start = 0, result = 0;

void preDFS(int u, int par)
{
    treeSize[u] = 1;
    for (int v : adj[u])
    {
        if (v == par)
            continue;
        hight[v] = hight[u] + 1;
        preDFS(v, u);
        treeSize[u] += treeSize[v];
    }
}

void init()
{
    cin >> subtask;
    cin >> n1;
    for (int i = 1; i < n1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> n2;
    for (int i = 1; i < n2; i++)
    {
        int u, v;
        cin >> u >> v;
        u += n1;
        v += n1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> n3;
    for (int i = 1; i < n3; i++)
    {
        int u, v;
        cin >> u >> v;
        u += n1 + n2;
        v += n1 + n2;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void calcSumDist(int u, int par, int n)
{
    for (int v : adj[u])
    {
        if (v == par)
            continue;
        sumDist[v] = sumDist[u] + n - 2 * treeSize[v];
        calcSumDist(v, u, n);
    }
}


void updatePair(pair<ll, ll> &a, ll b)
{
    if (b > a.first)
    {
        a.second = a.first;
        a.first = b;
    }
    else
        a.second = max(a.second, b);
}

ll best[maxn], bestU1[maxn], bestU2[maxn];

void calc(int u, int par, int numVer1, int numVer3)
{
    bestU1[u] = 1ll * numVer1 * sumDist[u] + 1ll * numVer1 * 1ll * numVer3 * hight[u];
    bestU2[u] = 1ll * numVer1 * sumDist[u] + 1ll * numVer1 * 1ll * numVer3 * hight[u];
    best[u] = bestU1[u] + bestU2[u];

    pair<ll, ll> childU1(bestU1[u], -1), childU2(bestU2[u], -1);

    for (int v : adj[u])
    {
        if (v == par)
            continue;
        calc(v, u, numVer1, numVer3);
        bestU1[u] = max(bestU1[u], bestU1[v]);
        bestU2[u] = max(bestU2[u], bestU2[v]);
        updatePair(childU1, bestU1[u]);
        updatePair(childU2, bestU2[u]);
    }
    for (int v : adj[u])
    {
        if (v == par)
            continue;
        best[u] = max(best[u], bestU1[v] + (childU2.first == bestU2[v] ? childU2.second : childU2.first));
        best[u] = max(best[u], bestU2[v] + (childU1.first == bestU1[v] ? childU1.second : childU1.first));
    }
    best[u] -= 2ll * numVer1 * numVer3 * hight[u];
}

void solve()
{
    for (int i = 1; i <= n1 + n2 + n3; i++)
        start += sumDist[i];
    start /= 2;
    // tree 2 is mid
    calc(n1 + 1, -1, n1, n3);
    ll bestF = 0;
    for(int i = n1 + 1; i <= n1 + n2; i ++){
        bestF = max(bestF, best[i]);
    }
    result = max(result, bestF + start);
    // tree 3 is mid
    calc(n1 + n2 + 1, -1, n1, n2);
    bestF = 0;
    for(int i = n1 + n2 + 1; i <= n1 + n2 + n3; i ++){
        bestF = max(bestF, best[i]);
    }
    result = max(result, bestF + start);
    // tree 2 is mid
    calc(1, -1, n2, n3);
    bestF = 0;
    for(int i = 1; i <= n1; i ++){
        bestF = max(bestF, best[i]);
    }
    result = max(result, bestF + start);
    cout << result;
}

void precess()
{
    hight[1] = 0;
    preDFS(1, -1);
    for (int i = 1; i <= n1; i++)
        sumDist[1] += hight[i];
    calcSumDist(1, -1, n1);
    hight[1] = 0;
    preDFS(n1 + 1, -1);
    for (int i = n1 + 1; i <= n1 + n2; i++)
        sumDist[n1 + 1] += hight[i];
    calcSumDist(n1 + 1, -1, n2);
    hight[n1 + n2 + 1] = 0;
    preDFS(n1 + n2 + 1, -1);
    for (int i = n1 + n2 + 1; i <= n1 + n2 + n3; i++)
        sumDist[n1 + n2 + 1] += hight[i];
    calcSumDist(n1 + n2 + 1, -1, n3);
    solve();
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
    precess();
    return 0;
}