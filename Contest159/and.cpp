#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 300001
#define task "and"
#define BLOCK_SIZE 100001

#define mod 998244353
#define inf 2100000000
#define LOG 31

// #define inf 1e18

#define inBlock(pos) ((pos - 1) / BLOCK_SIZE + 1)

#define reset(a) memset(a, 0, sizeof(a))

#define bit(x, i) ((x >> i) & 1)

int n, q;
int a[maxn];
int first[maxn][LOG];
int firstPos[maxn];

bool query(int x, int y){
    if(x > y) return 0;
    if((a[x] & a[y]) > 0) return 1;
    for(int i = 0; i < LOG; i ++){
        if(first[x][i] <= y && bit(a[y], i)) return 1;
    }
    return 0;
}

void process(){
    cin >> n >> q;
    memset(first, 99, sizeof(first));
    memset(firstPos, 99, sizeof(firstPos));
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = n; i >= 1; i --){
        for(int j = 0; j < LOG; j ++){
            if(bit(a[i], j)) continue;
            for(int tmp = a[i]; tmp > 0; tmp ^= tmp & - tmp){
                int k = __builtin_ctz(tmp & -tmp); // so luong so 0 o sau cua tmp 
                if(firstPos[k] <= n) {
                    first[i][j] = min(first[i][j], first[firstPos[k]][j]);
                }
            }
        }
        for(int j = 0; j < LOG; j ++){
            if(bit(a[i], j)){
                first[i][j] = i;
                firstPos[j] = i;
            }
        }
    }
    while(q --){
        int x, y;
        cin >> x >> y;
        cout << (query(x, y) ? "Yes " : "No ");
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