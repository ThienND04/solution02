#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "birthday"
#define inf 100000000
#define mod 1000000007
#define maxn 100001

#define maxk 10000001

int m, n;
int k[maxn];
int best[maxk];
int f[maxk];

void process(){
    reset(best);
    memset(f, -1, sizeof(f));
    cin >> m >> n;
    for(int i = 1; i <= m; i ++) cin >> k[i];
    for(int i = 1; i <= m; i ++){
        for(int j = k[i] - 1; j < maxk; j += k[i]){
            best[j] = k[i] - 1;
        }
    }
    for(int i = 1; i <= m; i ++) best[maxk - 1] = max(best[maxk - 1], (maxk - 1) % k[i]);
    for(int i = maxk - 2; i >= 1; i --){
        best[i] = max(best[i], best[i + 1] - 1);
    }   
    f[0] = 0;
    for(int i = 1; i < maxk; i ++){
        if(f[i - best[i]] == -1) continue;
        f[i] = f[i - best[i]] + 1;
    }
    while(n --){
        int x;
        cin >> x;
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