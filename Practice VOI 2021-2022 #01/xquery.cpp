#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "xquery"
#define inf 1e9
#define mod 1000000007
#define maxn 1000001

#define B 1000007

#define bit(x, i) ((x >> i) & 1)

class trieTree{
public: 
    #define child(x, t) trie[x][t] // t: 0 or 1
    #define sz(x) trie[x][2] // x: id of trie
    #define c1(x, i) cnt[x][i]
    #define c0(x, i) (sz(x) - c1(x, i))

    trieTree(){
        trie.push_back(vector<int>(3));
        cnt.push_back(vector<int>(18));
        a = 0;
    }
    
    bool exist(int key){
        key ^= a;
        for(int k = 0, i = 18; i --; ){
            int t = bit(key, i);
            k = child(k, t);
            if(! sz(k)) return 0;
        }
        return 1;
    }

    void Push(int key, int d);

    void Xor(int key);

    ll sumN(int n);

    vector<vector<int>> trie;
    vector<vector<int>> cnt;

    int a;
};

void trieTree::Push(int key, int d){
    if(d == -1 && !exist(key))  return ;
    key ^= a;
    for(int k = 0, i = 18; i --; ){
        int t = bit(key, i);
        if(! child(k, t)) {
            child(k, t) = trie.size();
            trie.push_back(vector<int> (3));
            cnt.push_back(vector<int> (i));
        }
        k = child(k, t);
        sz(k) += d;
        for(int j = i; j --; ){
            c1(k, j) += d * bit(key, j);
        }
    }
}

void trieTree::Xor(int key){
    a ^= key;
}

ll trieTree::sumN(int n){
    ll res = 0;
    for(int k = 0, i = 18; i --; ){
        int l = child(k, bit(a, i)), r = child(k, bit(a, i) ^ 1);
        if(bit(a, i)){
            swap(l, r);
        }
        for(int j = i; j --; ){
            int c = (bit(a, j)) ? c0(l, j) : c1(l, j);
            res += 1ll * c << j;
        }
        n -= sz(l);
        res += 1ll * n << i;
        k = r;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int q;
    cin >> q;
    trieTree S;

    while(q --){
        int t, val;
        cin >> t >> val;
        if(t == 0 || t == 1){
            S.Push(val, t ? -1 : 1);;
        }
        else if(t == 2) S.Xor(val);
        else cout << S.sumN(val) << "\n";
    }
    cerr << S.a;
    return 0;
}