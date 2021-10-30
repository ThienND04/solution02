#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 2222
#define task "cnv"
#define BLOCK_SIZE 100001

#define maxc 600

#define mod 998244353

// #define inf 1e18

#define inBlock(pos) ((pos - 1) / BLOCK_SIZE + 1)

#define reset(a) memset(a, 0, sizeof(a))

string s;
string ans[] = {"", "TRETRAU", "CULUA", "DUDUA", "LAYCHONG"};

string  solve(){
    cin >> s;
    if(s == "cnv"){
        return "PHAMTHIDIEMQUYNH";
    }
    return ans[stoi(s)];
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
    cout << solve();
    return 0;
}