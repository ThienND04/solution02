#define taskname "KIOSKS"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
using lli = long long;
const int maxN = 1e4 + 1;
const int maxK = 11;
const int maxColorSet = 1 << maxK;
const int MOD = 1e9 + 7;

int n, k, nsets;
int c[maxN];
vector<int> adj[maxN];
int f[maxN];
int q[maxColorSet];

void ReadInput()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        if (c[i] <= k) c[i] = 1 << c[i];
        else c[i] = 1;
    }
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void Build(int u, int parent)
{
    for (int& v: adj[u])
        if (v == parent)
        {
            v = adj[u].back();
            adj[u].pop_back();
            break;
        }
    for (int v: adj[u])
        Build(v, u);
}

void Init()
{
    Build(1, -1);
    nsets = 1 << (k + 1);
}

void Visit(int u, int ColorSet)
{
    for (int v: adj[u])
        Visit(v, ColorSet);
    if ((c[u] & ColorSet) != c[u])
        f[u] = 0;
    else
    {
        f[u] = 1;
        for (int v: adj[u])
            f[u] = (f[u] + (lli)f[u] * f[v]) % MOD;
    }
}

int Cardinality(int s)
{
    int res = 0;
    for (; s > 0; s &= s - 1)
        ++res;
    return res;
}

int Cal(int s)
{
    int Result = 0;
    for (int x = 0; x < nsets; ++x)
        {
            if ((x & s) != x) continue;
            if (Cardinality(s ^ x) % 2 == 0)
                Result = (Result + q[x]) % MOD;
            else
                Result = (Result - q[x]) % MOD;
        }
    return Result;
}

void Solve()
{
    for (int s = 0; s < nsets; ++ s)
    {
        Visit(1, s);
        q[s] = 0;
        for (int u = 1; u <= n; ++u)
            q[s] = (q[s] + f[u]) % MOD;
    }
    int Res = Cal(nsets - 1) + Cal(nsets - 2);
    Res = (Res % MOD + MOD) % MOD;
    cout << Res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    Init();
    Solve();
}