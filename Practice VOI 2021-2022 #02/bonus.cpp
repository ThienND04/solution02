#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bonus"
#define inf 1e18
#define mod 1000000007
#define maxn 5001

int m, n;
vector<vector<int> > a;
vector<vector<ll> > f, g;
pii dist[maxn];
int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, -1, 1};

ll res = 0;

void minimize(ll& x, ll y){
    if(x > y) {
        x = y;
    }
}

void maximize(ll& x, ll y){
    if(x < y){
        x = y;
    }
}

void init(){
    cin >> m >> n;
    a.resize(m + 1);
    f.resize(m + 1);
    g.resize(m + 1);
    for(int i = 1; i <= m; i ++ ) {
        a[i].assign(n + 1, 0);
        f[i].assign(n + 1, 0);
        g[i].assign(n + 1, 0);
    }
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }
    if(res < 0){
        cout << res;
        exit(0);
    }
}

void calc(){
    int cnt = 0;

    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j ++){
            dist[++ cnt] = {i, j};
        }
    }
    
    sort(dist + 1, dist + cnt + 1, [](pii& pa, pii& pb)
            {return pa.first * pa.first + pa.second * pa.second \
             <= pb.first * pb.first + pb.second * pb.second; });

    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++) f[i][j] = g[i][j] = a[i][j];
    }

    
    for(int _ = 2; _ <= cnt; _ ++){
        int x = dist[_].first, y = dist[_].second;
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++){
                for(int k = 0; k < 4; k ++){
                    if(i + dx[k] * x > 0 && i + dx[k] * x <= m && j + dy[k] * y > 0 && j + dy[k] * y <= n){
                        maximize(g[i][j], f[i + dx[k] * x][j + dy[k] * y] + a[i][j]);
                        if(f[i + dx[k] * x][j + dy[k] * y] != a[i + dx[k] * x][j + dy[k] * y]) 
                            maximize(res, f[i + dx[k] * x][j + dy[k] * y] + a[i][j]);

                    }
                }
            }
        }     
        if(x * x + y * y != dist[_ + 1].first * dist[_ + 1].first + dist[_ + 1].second * dist[_ + 1].second){
            for(int i = 1; i <= m; i ++){
                for(int j = 1; j <= n; j ++){
                    f[i][j] = g[i][j];
                }
            }
        }
    }
}

void process(){
    calc();
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++) a[i][j] = -a[i][j];
    }
    calc();
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    // cerr << n;
    process();
    return 0;
}