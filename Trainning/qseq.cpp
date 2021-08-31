#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 2000005
#define task "qseq"
#define inf 1000000000

int x, y, m, q, t, mo;
int a[maxn];
int pos[maxn];

void init(){
    cin >> a[0] >> x >> y >> m >> q;
    memset(pos, -1, sizeof(pos));
    pos[a[0]] = 0;
    for(int i = 1; i <= m; i ++){
        a[i] = (1ll * a[i - 1] * x + y) % m;
        if(pos[a[i]] != -1){
            mo = i - pos[a[i]];
            t = pos[a[i]];
            break;
        }
        pos[a[i]] = i;
    }
}

int getId(){
    string s;
    cin >> s;
    if(s.size() <= 9) {
        int p = stoi(s);
        if(p > t) {
            return (p - t) % mo + t;
        }
        else {
            return p;
        }
    }
    int num = 0;
    for(char c: s){
        num = (num * 10 + c - '0') % mo;
    }
    return (num - t + mo) % mo + t;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r",  stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    int p;
    for(int i = 0; i < q; i ++){
        p = getId();
        cout << a[p] << " ";
    }
    return 0;
}