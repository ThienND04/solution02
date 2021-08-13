#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<long long, int> pli;
#define inf 1000000009
#define mod 1000000007
#define task "h"
#define maxn 200002
#define B 1000007

string s;
int len[maxn * 4];
ll lt[maxn], h[maxn * 4];

void init(int id, int l, int r){
    if(l == r){
        h[id] = s[l];
        len[id] = 1;
        return ;
    }
    int mid = (l + r) / 2;
    init(id * 2 +1, l, mid);
    init(id * 2 + 2, mid + 1, r);
    h[id] = (h[id * 2 + 1] * lt[len[id * 2 + 2]] + h[id * 2 + 2]) % mod;
    len[id] = r - l + 1;
}

void update(int id, int l, int r, int u){
    if(l == r){
        len[id] = 0;
        h[id] = 0;
        return;
    }
    int mid = (l + r ) / 2;
    if(u <= mid) update(id * 2 + 1, l, mid, u);
    else update(id * 2 + 2, mid + 1, r, u);
    h[id] = (h[id * 2 + 1] * lt[len[id * 2 + 2]] + h[id * 2 + 2]) % mod;
    len[id] = len[id * 2 + 1] + len[id * 2 + 2];
}

int getPos(int id, int l, int r, int u){
    if(l == r) return l;
    int mid = (l + r) / 2;
    if(len[id * 2 + 1] >= u){
        return getPos(id * 2 + 1, l, mid, u);
    }
    return getPos(id * 2 + 2, mid + 1, r, u - len[id * 2 + 1]);
}

pli getHash(int id, int l, int r, int u, int v){
    if(l > v || r < u) return {0, 0};
    if(u <= l && r <= v) return {h[id], len[id]};
    int mid = (l + r) / 2;
    pli x = getHash(id * 2 + 1, l, mid, u, v);
    pli y = getHash(id * 2 + 2, mid + 1, r, u, v);
    return {(x.first * lt[y.second] + y.first) % mod, x.second + y.second};
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> s;
    s = " " + s;
    int sz = s.size() - 1;
    lt[0] = 1;
    for(int i = 1; i <= sz; i ++){
        lt[i] = (lt[i - 1] * B) % mod;
    }
    init(0, 1, sz);
    int n;
    cin >> n;
    while(n --){
        char c;
        int l1, l2, m;
        cin >> c ;
        if(c == '-'){
            cin >> m;
            int x = getPos(0, 1, sz, m);
            update(0, 1, sz, x);
        }
        else{
            cin >> l1 >> l2 >> m;
            int u1 = getPos(0, 1, sz, l1), \
                u2 = getPos(0, 1, sz, l2), \
                v1 = getPos(0, 1, sz, l1 + m - 1), \
                v2 = getPos(0, 1, sz, l2 + m - 1);
            ll h1 = getHash(0, 1, sz, u1, v1).first, \
                h2 = getHash(0, 1, sz, u2, v2).first;
            if(h1 == h2){
                cout << "YES\n";
            }
            else cout << "NO\n";
        }
    }
    return 0;
}