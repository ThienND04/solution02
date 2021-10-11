#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 9999
#define task "xquery"

struct trieTree
{
    vector<vector<int>> trie;
    vector<vector<int>> cnt;
    int a;
#define child(x, t) trie[x][t]
#define sz(x) trie[x][2]
#define c1(x, i) cnt[x][i]
#define c0(x, i) (sz(x) - c1(x, i))

    trieTree()
    {
        trie.push_back(vector<int>(3));
        cnt.push_back(vector<int>(18));
        a = 0;
    }

    bool exist(int key)
    {
        key ^= a;
        for (int k = 0, i = 18; i--;)
        {
            int t = key >> i & 1;
            k = child(k, t);
            if (!sz(k))
                return 0;
        }
        return true;
    }

    void push(int key, int d)
    {
        if (d == -1 && !exist(key))
            return;
        key ^= a;
        for (int k = 0, i = 18; i--;)
        {
            int t = key >> i & 1;
            if (!child(k, t))
            {
                child(k, t) = trie.size();
                trie.push_back(vector<int>(3));
                cnt.push_back(vector<int>(i));
            }
            k = child(k, t);
            sz(k) += d;
            for (int j = i; j--;)
                c1(k, j) += d * (key >> j & 1);
        }
    }

    void Xor(int val)
    {
        a ^= val;
    }

    ll sumn(int n)
    {
        ll res = 0;
        for (int k = 0, i = 18; i--;)
        {
            int l = child(k, a >> i & 1), r = child(k, (a >> i & 1) ^ 1);
            if (sz(l) >= n)
            {
                k = l;
                continue;
            }
            for (int j = i; j--;)
            {
                int c;
                if (a >> j & 1)
                    c = c0(l, j);
                else
                    c = c1(l, j);
                res += 1ll * c << j;
            }
            n -= sz(l);
            res += 1ll * n << i;
            k = r;
        }
        return res;
    }
};

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
    int Query;
    cin >> Query;
    trieTree S;
    while (Query--)
    {
        int t, val;
        cin >> t >> val;
        if (t == 0 || t == 1)
        {
            if (t)
                S.push(val, -1);
            else
                S.push(val, 1);
        }
        if (t == 2)
            S.Xor(val);
        if (t == 3)
            cout << S.sumn(val) << '\n';
    }
}