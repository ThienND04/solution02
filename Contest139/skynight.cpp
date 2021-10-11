#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "skynight"
#define inf 1e9
#define mod 1000000007
#define maxn 5001

#define bit(x, i) ((x >> i) & 1)

int r, c, m, n;
int cd[301];
bool sky[maxn][maxn];
int sao[maxn][maxn];

void loadSky(int i, string& s){
    int cnt = 0;
    for(char ch: s){
        int tmp = cd[ch];
        for(int j = 0; j <= 5; j ++){
            if(cnt == c) return;
            sky[i][++ cnt] = bit(tmp, j);
        }
    }
}

void init(){
    // reset(sao);
    // reset(sky);
    for(char ch = '0'; ch <= '9'; ch ++) cd[ch] = ch - '0';
    for(char ch = 'a'; ch <= 'z'; ch ++) cd[ch] = ch - 61;
    for(char ch = 'A'; ch <= 'Z'; ch ++) cd[ch] = ch - 55;
    cd['#'] = 62;
    cd['$'] = 63;
    cin >> r >> c >> m >> n;
    string s;
    for(int i = 1; i <= r; i ++){
        cin >> s;
        loadSky(i, s);
    }
}

void solve(){
    for(int i = 1; i <= r; i ++){
        for(int j = 1; j <= c; j ++){
            sao[i][j] = sao[i - 1][j] + sao[i][j - 1] - sao[i - 1][j - 1] + sky[i][j];
        }
    }
    int res = 0;
    for(int i = 1; i <= r; i ++){
        int x = i + m - 1;
        if(x > r) break;
        for(int j = 1; j <= c; j ++){
            int y = j + n - 1;
            if(y > c) break;
            int tmp = sao[x][y] - sao[x][j - 1] - sao[i - 1][y] + sao[i - 1][j - 1];
            res = max(res, tmp);
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    solve();
    // for(int i = 1; i <= r; i ++){
    //     for(int j = 1; j <= c; j ++) {
    //         // cerr << sky[i][j] << " ";
    //         if(sky[i][j]) cerr << "*";
    //         else cerr << ".";
    //     }
    //     cerr << endl;
    // }
    return 0;
}