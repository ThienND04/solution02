#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a))
#define task "e"
#define inf 1000000007
#define maxn 300

int m, t, n;
pii s, en;
vector<pii> adj[maxn][maxn];
int d[maxn][maxn];

void init(){
    cin >> m >> t >> n;
    string move;
    cin >> move;
    s = {101, 101};
    pii tmp = s;
    for(char c: move) {
        pii tmp2 = tmp;
        if(c == 'R') tmp.first ++;
        else if(c == 'L') tmp.first --;
        else if(c == 'U') tmp.second ++;
        else tmp.second --;
        adj[tmp2.first][tmp2.second].push_back(tmp);
    }
    en = tmp;
}

int getMana(int x1, int y1, int x2, int y2){
    // int x0 = x1 * 2 - x2, y0 = y1 * 2 - y2;
    int mana = inf;
    for(pii k: adj[x1][y1]){
        int x0 = k.first, y0 = k.second;
        if(x0 == x1 * 2 - x2 && y0 == y1 * 2 - y2) {
            mana = min(mana, d[x0][y0] + 2 * m);
        }
        else mana = min(mana, d[x0][y0] + 2 * m + t);
    }
    if(mana == inf) return m;
}

void dijkstra(){
    for(int i = 0; i < maxn; i ++){
        for(int j = 0; j < maxn; j ++) d[i][j] = inf;
    }
    pre[s.first][s.second] = {0, 0};
    d[s.first][s.second]  = 0;
    priority_queue<vector<int>> q;
    q.push({0, s.first, s.second});
    while(! q.empty()){
        int l = -q.top()[0], x1 = q.top()[1], y1 = q.top()[2];
        q.pop();
        if(l != d[x1][y1]) continue;
        for(pii v: adj[x1][y1]){
            int x2 = v.first, y2 = v.second;
            int w = getMana(x1, y1, x2, y2);
            if(d[x2][y2] > l + w){
                d[x2][y2] = l + w;
                q.push({- d[x2][y2], x2, y2});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();
    dijkstra();
    cout << d[en.first][en.second];
    cerr << d[en.first][en.second];
    return 0;
}