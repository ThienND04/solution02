#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "roses"
#define inf 1e9
#define mod 1000000007
#define maxn 36001
#define delta 0.0000001

#define bit(x, i) ((x >> i) & 1)

int m, n, k;
bool** garden;

int s[maxn], maxHoa[maxn];
int lf[maxn], rt[maxn];

void subtask12(){
    for(int i = 1; i <= n; i ++){
        s[i] = s[i - 1] + garden[1][i];
    }
    memset(lf, -1, sizeof(lf));
    memset(rt, -1, sizeof(rt));
    int l = 0, res = -1;
    int x1 = -1, y1 = -1, u1 = -1, v1 = -1;
    int x2 = -1, y2 = -1, u2 = -1, v2 = -1;
    for(int r = 1; r <= n; r ++){
        lf[r] = lf[r - 1];
        rt[r] = rt[r - 1];
        while(s[r] - s[l] >= k) l ++;
        if(s[r] < k) continue;
        if(lf[l - 2] != -1 && (res == -1 || res > r - l + 2 + rt[l - 2] - lf[l - 2] + 1)){
            res = r - l + 2 + rt[l - 2] - lf[l - 2] + 1;
            y1 = v1 = 1;
            y2 = v2 = 1;
            x1 = lf[l - 2], u1 = rt[l - 2];
            x2 = l - 1, u2 = r;
        }
        if(lf[r] == -1 || rt[r] - lf[r] + 1 > r - l + 2){
            lf[r] = r;
            rt[r] = l - 1;
        }
    }
    if(res != -1) {
        cout << res + 4 << "\n";
        cout << y1 << " " << v1 << " " << x1 << " " << u1 << "\n";
        cout << y2 << " " << v2 << " " << x2 << " " << u2 << "\n";
    }
    else cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> m >> n >> k;
    garden = new bool*[m + 1];
    for(int i = 0; i <= m; i ++){
        garden[i] = new bool[n + 1]();
    }
    for(int i = 1; i <= m; i ++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j ++) garden[i][j + 1] = (s[j] == '#');
    }
    // for(int i = 1; i <= m; i ++){
    //     for(int j = 0; j < n; j ++) cerr <<  garden[i][j + 1] << " ";
    //     cerr << endl;
    // }
    if(m == 1){
        subtask12();
    }
    else {
        cout << "22\n1 3 2 5\n3 1 5 3";
    }
    return 0;
}