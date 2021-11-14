#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "birthday"
#define inf 1000000000
#define mod 1000000007
#define maxn 100001

int m, n;
int k[maxn];
int f[10000001];

#define MAX 10000

void process(){
    memset(f, -1, sizeof(f));
    cin >> m >> n;
    for(int i = 1; i <= m; i ++) cin >> k[i];
    f[0] = 0;
    for(int i = 1; i < k[m]; i ++) f[i] = 1;
    for(int i = k[m]; i <= MAX; i ++){
        for(int j = 1; j <= m; j ++){
            if(f[i - i % k[j]] != -1){
                if(f[i] == -1) f[i] = f[i - i % k[j]] + 1;
                else f[i] = min(f[i], f[i - i % k[j]] + 1);
            }
        }
    }
    while(n --){
        int x;
        cin >> x;
        assert(x <= MAX);
        if(f[x] == -1) cout << "oo\n";
        else cout << f[x] << "\n";
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