#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "balloon"
#define inf 1000000000
#define mod 1000000007
#define maxn 10

int n;
string s;
int a[maxn];
int f[maxn][maxn];
char chrs[maxn];

template<class T> 
void maximize(T& x, T y){
    if(y > x) x = y;
}

void init(){
    reset(a);
    reset(f);
    reset(chrs);
    n = s.size();
    s = ' ' + s;
    int cnt = 0, m = 0;
    for(int i = 1; i <= n; i ++){
        if(s[i] != s[i - 1]){
            chrs[m] = s[i - 1];
            a[m ++] = cnt;
            cnt = 1;
        }
        else cnt ++;
    }
    chrs[m] = s[n];
    a[m] = cnt;
    n = m;
}

int calc(){
    init();
    for(int i = 1; i <= n; i ++) {
        if(a[i] == 1) f[i][i] = 0;
        else f[i][i] = a[i] * a[i];
    }
    for(int d = 2; d <= n; d ++){
        for(int l = 1; l <= n - d + 1; l ++){
            int r = l + d - 1;
            for(int d2 = 1; d2 < d; d2 ++){
                for(int l2 = l; l2 <= r - d2 + 1; l2 ++){
                    int r2 = l2 + d2 -1;
                    if(l2 > l && r2 < r){
                        if(chrs[l2 - 1] == chrs[r2 + 1]){
                            if(r2 + 2 <= r && l2 - 2 >= l && f[l2][r2] && f[l][l2 - 2] && f[r2 + 2][r]) {
                                maximize(f[l][r], f[l][l2 - 2] + f[l2][r2] + f[r2 + 2][r] + \
                                    (a[l2 - 1] + a[r2 + 1]) * (a[l2 - 1] + a[r2 + 1]));
                            }
                            if(r2 + 1 == r && l2 - 2 >= l && f[l2][r2] && f[l][l2 - 2]) {
                                maximize(f[l][r], f[l][l2 - 2] + f[l2][r2] + \
                                    (a[l2 - 1] + a[r2 + 1]) * (a[l2 - 1] + a[r2 + 1]));
                            }
                            if(r2 + 2 <= r && l2 - 1 == l && f[l2][r2] && f[r2 + 2][r]) {
                                maximize(f[l][r], f[l2][r2] + f[r2 + 2][r] + \
                                    (a[l2 - 1] + a[r2 + 1]) * (a[l2 - 1] + a[r2 + 1]));
                            }
                            if(r2 + 1 == r && l2 - 1 == l && f[l2][r2]) {
                                maximize(f[l][r], f[l2][r2] + \
                                    (a[l2 - 1] + a[r2 + 1]) * (a[l2 - 1] + a[r2 + 1]));
                            }
                        }
                        else {
                            if(f[l2][r2] && f[l][l2 - 1] && f[r2 + 1][r]) {
                                maximize(f[l][r], f[l][l2 - 1] + f[l2][r2] + f[r2 + 1][r]);
                            }
                        }
                    }
                    else if(l2 == l){
                        if(f[l2][r2] && f[r2 + 1][r]) {
                            maximize(f[l][r], f[l2][r2] + f[r2 + 1][r]);
                        }
                    }
                    else if(r2 == r){
                        if(f[l2][r2] && f[l][l2 - 1]){
                            maximize(f[l][r], f[l2][r2] + f[l][l2 - 1]);
                        }
                    }
                }
            }
        }
    }
    return f[1][n];
}

void process(){
    int t;
    cin >> t;
    while(t --){
        cin >> s;
        cout << calc() << "\n";
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