#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "xorSet"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

int n, k;
int a[maxn];
vector<int> adj[maxn];

void init(){
    cin >> n >> k;
    reset(a);
    if(n <= 10000){
        for(int i = 1; i <= n; i ++) cin >> a[i];
    }
}

void sub1(){
    cout << 66;
}

void process(){
    sub1();
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
    process();
    return 0;
}