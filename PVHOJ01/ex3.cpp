#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "ex3"
#define maxn 1000001
#define inf 1000000007
#define mod 998244353

struct  segmentTree
{
    vector<int> tree, lazy;
    int n;
    segmentTree(int _n = 0){
        n = _n;
        tree.assign(4 * n + 11, 0);
        lazy.assign(4 * n + 11, 0);
    }

    void push(){

    }

    int getMin(){
        
    }

    void update(int id, int l, int r, int u, int v){

    }

    void update(int lf, int rt, int d){
        
    }
};

int n, q;
string s;
set<int> closes;
segmentTree it;

void init(){
    cin >> n >> q >> s;
    s = " " + s;
}

void changeBracket(int pos){
    if(s[pos] == '('){
        s[pos] = ')';
        closes.insert(pos);
        ...
    }
    else{
        s[pos] = '(';
        closes.erase(pos);
        ...
    }
}

int findMin(int pos){

}

int query(int pos){
    changeBracket(pos);
    if(s[pos] == '('){
        int tmp = findMin(pos);
        changeBracket(tmp);
        return tmp;
    }
    else{
        int tmp = *closes.begin();
        changeBracket(tmp);
        return tmp;
    }
}

void solve(){
    while(q --){
        int p;
        cin >> p;
        cout << query(p) << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    init();
    solve();
    return 0;
}