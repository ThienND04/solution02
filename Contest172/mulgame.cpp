#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 300001
#define task "mulgame"
#define BLOCK_SIZE 100001

#define mod 998244353
#define inf 2100000000
#define LOG 30
#define reset(a) memset(a, 0, sizeof(a))
#define bit(x, i) ((x >> i) & 1)

int t;
int f[maxn];

void init(){
    cin >> t;
    f[1] = 2;
    for(int i = 2; i < maxn; i ++) f[i] = 0;
    for(int i = 2; i < maxn; i ++){
        for(int j = 2; j <= 9; j ++){
            if(i % j == 0){
                if(f[i] == 1) continue;
            }
        }
    }
}

bool check(int n){
    if(n == 1) return 1;
    int j = n / 9;
    while(j * 9 < n) j ++;
    int i = j / 2;
    while(i * 2 < j) i ++;
    while(i < j){
        if(f[i ++] == 1) return 1;
    }
    if(f[n] == 1) return 1;
    return 0;
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