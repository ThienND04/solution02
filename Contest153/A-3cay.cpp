#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "3cay"
#define inf 1e9
#define mod 1000000007
#define maxn 5002

#define B 1000007

#define bit(x, i) ((x >> i) & 1)

int t;
string pl1[3], pl2[3];
int h[300];

bool cmp(string s1, string s2)
{
    if (s1[1] != s2[1])
    {
        return h[s1[1]] > h[s2[1]];
    }
    return s1[0] - '0' > s2[0] - '0';
}

bool solve()
{
    int score1 = 0, score2 = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> pl1[i];
        if(pl1[i][0] != 'A') score1 += pl1[i][0] - '0';
        else score1 ++;
    }
    score1 %= 10;
    if(! score1) score1 = 10;
    cin >> pl2[0];
    for (int i = 0; i < 3; i++)
    {
        cin >> pl2[i];
        if(pl2[i][0] != 'A') score2 += pl2[i][0] - '0';
        else score2 ++;
    }
    score2 %= 10;
    if(! score2) score2 = 10;
    if (score1 != score2)
    {
        return score1 > score2;
    }
    sort(pl1, pl1 + 3, cmp);
    sort(pl2, pl2 + 3, cmp);
    if(h[pl1[0][1]] != h[pl2[0][1]]) return h[pl1[0][1]] > h[pl2[0][1]];
    return pl1[0][0] - '0' > pl2[0][0] - '0';
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
    h['R'] = 4;
    h['C'] = 3;
    h['P'] = 2;
    h['N'] = 1;
    cin >> t;
    while (t--)
    {
        cout << (solve() ? "Yes ": "No ");
    }
    // cerr << int('A' - '0');
    return 0;
}