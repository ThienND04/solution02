#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "permute"
#define inf 1e9
#define maxn 400001
#define delta 0.0000001

int t, n, m;
int a[maxn], b[maxn];
bool check[maxn];

void init(){
    cin >> t >> n;
    m = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(a[i] != -1) check[a[i]] = 1;
    }
    for(int i = 1; i <= n; i ++) if(! check[i]) b[++ m] = i;
    sort(b + 1, b + m + 1); 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    int j = 1;
    for(int i = 1; i <= n;  i++){
        if(a[i] == -1) a[i] = b[j ++];
    }
    for(int i = 1; i <= n; i ++) cout << a[i] << " ";
    return 0;
}