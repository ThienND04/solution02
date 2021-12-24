#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "allstars"
#define inf 1e9
#define mod 1000000007
#define maxn 7001

#define bit(x, i) ((x >> i) & 1)

int m, n;
int cd[301];
bool sky[maxn][maxn];
int range[maxn][maxn];
int cntR[maxn];
int res = 0, id[maxn], lf;
int lfRes = 0, rtRes = 0, t, b;

void loadSky(int i, string& s){
    int cnt = 0;
    for(char ch: s){
        int tmp = cd[ch];
        for(int j = 0; j <= 5; j ++){
            if(cnt == n) return;
            sky[i][++ cnt] = bit(tmp, j);
        }
    }
}

void init(){
    for(char ch = '0'; ch <= '9'; ch ++) cd[ch] = ch - '0';
    for(char ch = 'a'; ch <= 'z'; ch ++) cd[ch] = ch - 61;
    for(char ch = 'A'; ch <= 'Z'; ch ++) cd[ch] = ch - 55;
    cd['#'] = 62;
    cd['$'] = 63;
    cin >> m >> n;
    string s;
    for(int i = 1; i <= m; i ++){
        cin >> s;
        loadSky(i, s); 
    }
    // for(int i = 1; i <= m; i ++){
    //     for(int j = 1; j <= n; j ++) cerr << (sky[i][j] ? "*" : ".");
    //     cerr << "\n";
    // }
}

void solve(){
    for(int i = 1; i <= m; i ++){
        int right = n + 1;
        for(int j = n; j >= 1; j --){
            if(! sky[i][j]) right = j;
            range[i][j] = right;
        }
    }
    for(int left = 1; left <= n; left ++){
        reset(cntR);
        for(int i = 1; i <= m; i ++) cntR[range[i][left]] ++;
        int sz = m;
        for(int right = left; right <= n; right ++){
            sz -= cntR[right];
            if(res < (right - left + 1) * sz){
                res = (right - left + 1) * sz;
                //for(int i = 1; i <= m; i ++) sorted[i] = id[i];
                lfRes = left;
                rtRes = right;
                t = 1, b = sz;
            }
        }
    }
    for(int i = 1; i <= m; i ++) id[i] = i;
    lf = lfRes;
    sort(id + 1, id + m + 1, [](int a, int b) {return range[a][lf] > range[b][lf]; });
    for(int i = 1; i <= m; i ++ ) cout << id[i] << " ";
    cout << "\n";
    cout << t << " " << b << " " << lfRes << " " << rtRes << "\n";
    // cerr << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    solve();
    return 0;
}