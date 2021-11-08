#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "kary"
#define inf 1e9
#define mod 2021
#define maxn 3000000

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

int k, h, n, numNode = 0;
ll lt[22];
bool ok[1000][1000];
int p[500500], hight[maxn], par[maxn];
map<pii, bool> ok3;

void init123(){
    lt[0] = 1;
    for(int i = 1; i <= h; i ++){
        lt[i] = lt[i - 1] * k;
    }
    hight[1] = 0;
    par[1] = 0;
    numNode = 1;
    for(int i = 1; i < h; i ++){
        int tmp = numNode;
        for(int j = tmp - lt[i - 1] + 1; j <= tmp; j ++){
            for(int t = 1; t <= k; t ++){
                hight[++ numNode] = i;
                par[numNode] = j;
            }
        }
    }
    for(int i = 1; i <= n; i ++) cin >> p[i];
}

int lca(int u, int v){
    if(hight[u] < hight[v]) swap(u, v);
    while(hight[u] > hight[v]) u = par[u];
    while(u != v) {
        u = par[u];
        v = par[v];
    }
    return u;
}

void sub2(){
    int u = p[1], v = p[2], res = 0;
    int llca = lca(u, v);
    while(u != llca){
        res ++;
        u = par[u];
    }
    while(v != llca){
        v = par[v];
        res ++;
    }
    cout << res;
    return; 
}

void sub1(){
    reset(ok);
    int curLCA = p[1], res = 0;
    for(int i = 2; i <= n; i ++){
        int u = curLCA, v = p[i];
        int llca = lca(u, v);
        while(u != llca){
            if(! ok[u][par[u]]){
                res ++;
                ok[u][par[u]] = 1;
            }
            // else break;
            u = par[u];
        }
        while(v != llca){
            if(! ok[v][par[v]]){
                res ++;
                ok[v][par[v]] = 1;
            }
            // else break;
            v = par[v];
        }
        curLCA = llca;
    }
    cout << res;
    return;
}

void sub3(){
    int curLCA = p[1], res = 0;
    for(int i = 2; i <= n; i ++){
        int u = curLCA, v = p[i];
        int llca = lca(u, v);
        while(u != llca){
            if(! ok3[{u, par[u]}]){
                ok3[{u, par[u]}] = 1;
                res ++;
            }
            u = par[u];
        }
        while(v != llca){
            if(! ok3[{v, par[v]}]){
                ok3[{v, par[v]}] = 1;
                res ++;
            }
            v = par[v];
        }
        curLCA = llca;
    }
    cout << res;
}

ll numHightBou[22];

ll findPar(ll u){
    int ht = 0;
    while(u > lt[ht]){
        u -= lt[ht ++];
    }
    if(ht == 0) return 0;
    if(ht == 1) return 1;
    return (((u - 1) / k) + 1 + numHightBou[ht - 2]);
}

int getHight(ll u){
    int ht = 0;
    while(u > lt[ht]){
        u -= lt[ht ++];
    }
    return ht;
}

ll getLca(ll u, ll v){
    int h1 = getHight(u), h2 = getHight(v);
    if(h1 < h2) {
        swap(h1, h2);
        swap(u, v);
    }
    while(h1 > h2){
        u = findPar(u);
        h1 --;
    }
    while (u != v)
    {
        u = findPar(u);
        v = findPar(v);
    }
    return u;
}

map<pair<ll, ll>, bool> ok4;

void sub4(){
    for(int i = 1; i <= n; i ++) cin >> p[i];
    lt[0] = 1;
    numHightBou[0] = 1;
    for(int i = 1; i <= h; i ++){
        lt[i] = lt[i - 1] * k;
        numHightBou[i] = numHightBou[i - 1] + lt[i];
    }
    int res = 0;
    ll curLCA = p[1];
    ll u, v, llca, pu, pv;
    for(int i = 2; i <= n; i ++){
        u = curLCA, v = p[i];
        llca = getLca(u, v);
        while(u != llca){
            pu = findPar(u);
            if(! ok4[{u, pu}]){
                res ++;
                ok4[{u, pu}] = 1;
                u = pu;
            }
            else break;
        }
        while(v != llca){
            pv = findPar(v);
            if(! ok4[{v, pv}]){
                ok4[{v, pv}] = 1;
                res ++;
                v = pv;
            }
            else break;
        }
        curLCA = llca;
    }
    cout << res;
}

void process(){
    cin >> k >> h >> n;
    if(h <= 8 && k <= 8){
        init123();
        if(n == 2){
            return sub2();
        }
        if(n == 3){
            return sub3();
        }
        return sub1();
    }
    return sub4();
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