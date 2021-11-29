#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "sumlove"
#define inf 1000000000
#define mod 1000000007
#define maxn 100001

#define T 330

int n, q;
int f[maxn], maxk = 0;
int k[maxn];

void Add(int &x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

void calc(){
    f[0] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = maxk; j >= i; j --){
            Add(f[j], f[j - i]);
        }
    }
}

void process(){
    cin >> n >> q;
    for(int i = 1; i <= q; i ++) {
        cin >> k[i];
        maxk = max(maxk, k[i]);
    }
    calc();
    // for(int i = 1; i <= maxk; i ++) cerr << f[i] << " ";
    int numBlocks = (maxk - 1) / T + 1;
    for(int i = 1; i <= numBlocks; i ++){
        for(int j = i + 1; j <= numBlocks; j ++){
            
        }
    }
    
    for(int i = 1; i <= q; i ++){
        int result = 0;
        for(int j = 0; j <= k[i]; j ++){
            Add(result, (1ll * f[j] * f[k[i] - j]) % mod);
        }
        cout << result << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    process();
    return 0;
}