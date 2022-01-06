#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 1000001
#define task "mulgame"
#define BLOCK_SIZE 100001

#define mod 998244353
#define inf 2100000000
#define LOG 30
#define reset(a) memset(a, 0, sizeof(a))
#define bit(x, i) ((x >> i) & 1)

int t;
bool f[maxn];
map<int, bool> mp;

void init(){
    cin >> t;
    reset(f);

    for(int i = 2; i < maxn; i ++){
        for(int j = 2; j <= 9; j ++){
            if(! f[(i - 1) / j + 1]) f[i] = 1;
        }
    }
    // f[1] = 1;
}

bool check(int n){
    if(n < maxn) return f[n];
    if(mp.find(n) != mp.end()) return mp[n];
    for(int i = 2; i <= 9; i ++){
        if(! check((n - 1) / i + 1)) return (mp[n] = 1);
    }
    return (mp[n] = 0);
}

void process(){
    init();
    while(t --){
        int n;
        cin >> n;
        if(check(n)) cout << "La premiere joueuse gagne.\n";
        else cout << "La deuxieme joueuse gagne.\n";
    }
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