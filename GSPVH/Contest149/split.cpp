#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "split"
#define maxn 7001
#define inf 1e18
// #define mod 1000000007

const int mod = 998244353;

int n;
string s;
int f[maxn][maxn];
int sum[maxn][maxn];
int lcp[maxn][maxn];

void Add(int& x, int y){
    x += y;
    if(x > mod) x -= mod;
}

int cmp(int pos1, int pos2, int lenght){
    /*
        return 0 if s[pos1 ... pos1 + lenght - 1] == s[pos2 ... pos2 + lenght - 1]
        return -1 if s[pos1 ... pos1 + lenght - 1] < s[pos2 ... pos2 + lenght - 1]
        return 1 if s[pos1 ... pos1 + lenght - 1] > s[pos2 ... pos2 + lenght - 1]
    */
    if(lcp[pos1][pos2] >= lenght) return 0;
    return (s[pos1 + lcp[pos1][pos2]] > s[pos2 + lcp[pos1][pos2]] ? 1: -1);
}

void init(){
    cin >> s;
    n = s.size();
    s = " " + s;
    lcp[n + 1][n + 1] = 0;
    for(int i = n; i >= 1; i --){
        for(int j = n; j >= 1; j --){
            if(s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
            else lcp[i][j] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    init();
    // f[1][1] = 1;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= i; j ++){
            if(s[j] == '0'){
                f[i][j] = 0;
                sum[i][j] = sum[i][j - 1];
                continue;
            }
            if(j == 1) {
                f[i][j] = 1;
                sum[i][j] = 1;
                continue;
            }
            int k = 2 * j - i - 1;
            f[i][j] = sum[j - 1][j - 1];
            if(k >= 0) {
                f[i][j] -= sum[j - 1][k];
                if(cmp(k, j, i - j + 1) == -1) {
                    Add(f[i][j], f[j - 1][k]);
                }
            }
            f[i][j] = (f[i][j] + 1ll * mod * mod) % mod;
            sum[i][j] = sum[i][j - 1]; Add(sum[i][j], f[i][j]);
        }   
    }
    cout << sum[n][n];
    return 0;
}