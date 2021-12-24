#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 300001
#define task "couples"
#define BLOCK_SIZE 100001

#define mod 998244353
#define inf 2100000000
#define LOG 30
#define reset(a) memset(a, 0, sizeof(a))
#define bit(x, i) ((x >> i) & 1)

int subtask, m, n, mg = 0, ml = 0, ng = 0, nl = 0;
int b[maxn], g[maxn];
pii bg[maxn], bl[maxn], gg[maxn], gl[maxn];
pii res[maxn];

bool cmp(pii& x, pii& y){
    return abs(x.first) < abs(y.first);
}

void init(){
    cin >> subtask;
    cin >> m;
    for(int i = 1; i <= m; i ++) cin >> b[i];
    for(int i = 1; i <= m; i ++){
        if(b[i] < 0) {
            bl[++ ml] = {- b[i], i};
        }
        else {
            bg[++ mg] = {b[i], i};
        }
    }
    sort(bl + 1, bl + ml + 1, cmp);
    sort(bg + 1, bg + mg + 1, cmp);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> g[i];
    for(int i = 1; i <= n; i ++){
        if(g[i] < 0) {
            gl[++ nl] = {- g[i], i};
        }
        else {
            gg[++ ng] = {g[i], i};
        }
    }
    sort(gg + 1, gg + ng + 1, cmp);
    sort(gl + 1, gl + nl + 1, cmp);
}

void process(){
    init();
    int cnt = 0;
    int j = 1;
    for(int i = 1; i <= mg; i ++){
        while(j <= nl && gl[j].first <= bg[i].first) j ++;
        if(j <= nl){
            res[++ cnt] = {bg[i].second, gl[j].second};
            j ++;
        }
    }
    j = 1;
    for(int i = 1; i <= ng; i ++){
        while(j <= ml && bl[j].first <= gg[i].first) j ++;
        if(j <= ml){
            res[++ cnt] = {bl[j].second, gg[i].second};
            j ++;
        }
    }
    cout << cnt << "\n";
    for(int i = 1; i <= cnt; i ++) cout << res[i].first << " " << res[i].second << "\n";
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