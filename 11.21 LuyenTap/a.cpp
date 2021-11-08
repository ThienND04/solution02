#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "a"
#define inf 1000000000
#define mod 1000000007
#define maxn 1000001

int sum = 0;
int a1, a2, a3;
int b1, b2, b3;
int x, y, z;

map<int, int> f[maxn];

int process(){
    // memset(f, 99, sizeof(f));
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> x >> y >> z;
    sum = b1 + b2 + b3;
    // cerr << f[0][0];
    queue<pii> q;
    f[b1][b2] = 0;
    q.push({b1, b2});
    while(! q.empty()){
        b1 = q.front().first, b2 = q.front().second;
        q.pop();
        b3 = sum - b1 - b2;

        auto it = f[b1 - min(b1, a2 - b2)].find(min(b2 + b1, a2));
        if(b1 != 0 && b2 < a2 && it == f[b1 - min(b1, a2 - b2)].end() ){
            f[b1 - min(b1, a2 - b2)][min(b2 + b1, a2)] = f[b1][b2] + 1;
            q.push({b1 - min(b1, a2 - b2), min(b2 + b1, a2)});
        }
        it = f[min(b1 + b2, a1)].find(b2 - min(b2, a1 - b1));
        if(b2 != 0 && b1 < a1 && it == f[min(b1 + b2, a1)].end()){
            f[min(b1 + b2, a1)][b2 - min(b2, a1 - b1)] = f[b1][b2] + 1;
            q.push({min(b1 + b2, a1), b2 - min(b2, a1 - b1)});
        }

        it = f[b1 - min(b1, a3 - b3)].find(b2);
        if(b1 != 0 && b3 < a3 && it == f[b1 - min(b1, a3 - b3)].end()){
            f[b1 - min(b1, a3 - b3)][b2] = f[b1][b2] + 1;
            q.push({b1 - min(b1, a3 - b3), b2});
        }
        it = f[min(b1 + b3, a1)].find(b2);
        if(b3 != 0 && b1 < a1 && it == f[min(b1 + b3, a1)].end()){
            f[min(b1 + b3, a1)][b2] = f[b1][b2] + 1;
            q.push({min(b1 + b3, a1), b2});
        }

        it = f[b1].find(b2 - min(b2, a3 - b3));
        if(b2 != 0 && b3 < a3 && it == f[b1].end()){
            f[b1][b2 - min(b2, a3 - b3)] = f[b1][b2] + 1;
            q.push({b1, b2 - min(b2, a3 - b3)});
        }
        it = f[b1].find(min(b2 + b3, a2));
        if(b3 != 0 && b2 < a2 && it == f[b1].end()){
            f[b1][min(b2 + b3, a2)] = f[b1][b2]+ 1;
            q.push({b1, min(b2 + b3, a2)});
        }
    }

    int res = inf;
    auto it = f[x].find(y);
    if(it != f[x].end()) res = min(res, f[x][y]);
    it = f[y].find(x);
    if(it != f[y].end()) res = min(res, f[y][x]);
    it = f[x].find(z);
    if(it != f[x].end()) res = min(res, f[x][z]);
    it = f[z].find(x);
    if(it != f[z].end()) res = min(res, f[z][x]);
    it = f[y].find(z);
    if(it != f[y].end()) res = min(res, f[y][z]);
    it = f[z].find(y);
    if(it != f[z].end()) res = min(res, f[z][y]);
    if(res == inf) return -1;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cout << process();
    return 0;
}