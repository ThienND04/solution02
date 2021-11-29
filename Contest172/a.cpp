#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 1000001
#define task "a"
#define BLOCK_SIZE 100001

#define mod 998244353
#define inf 2100000000
#define LOG 30

// #define inf 1e18

#define inBlock(pos) ((pos - 1) / BLOCK_SIZE + 1)

#define reset(a) memset(a, 0, sizeof(a))

#define bit(x, i) ((x >> i) & 1)

int n;
int a[maxn];

void process(){
    string i;
    cin >> i;
    if(i == "1") cout << "1000DONG";
    else if(i == "2") cout << "UNGTHU";
    else if(i == "3") cout << "GIA";
    else if(i == "4") cout << "13";
    else if(i == "cnv") cout << "VN";
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
    process();
    return 0;
}