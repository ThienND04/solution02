#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "less"
#define inf 1e9
#define mod 1000000007
#define maxn 1000001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

namespace caculate{
    template<class T>
    void add(T& x, T y){
        x += y;
        if(x >= mod) x -= mod;
    }
    template<class T>
    void sub(T& x, T y){
        x -= y;
        if(x < 0) x += mod;
    }
    template<class T>
    void maximize(T& x, T y){
        if(x < y) x = y;
    }
    template<class T>
    void minimize(T& x, T y){
        if(x > y) x = y;
    }
}

using namespace caculate;

struct trie
{
    trie* child[ALPHABET];
    int cnt = 0;

    trie(){
        for(int i = 0; i < ALPHABET; i ++) child[i] = NULL;
    }
};

trie* getTrieNode(){
    trie* tmp = new trie;
    for(int i = 0; i < ALPHABET; i ++) tmp->child[i] = NULL;
    tmp->cnt = 0;
    return tmp;
}

void Add(trie* root, const string& s){
    trie* tmp = root;
    tmp->cnt ++;
    for(char c: s){
        if(! tmp->child[c - 'a']){
            tmp->child[c - 'a'] = getTrieNode();
        }
        tmp = tmp->child[c - 'a'];
        tmp-> cnt ++;
    }
}

int Get(trie* root, const string& s){
    trie* tmp = root;
    int res = 0;
    for(char c: s){
        int cntTmp = 0;
        for(int i = 0; i < c - 'a'; i ++) {
            if(tmp->child[i]) cntTmp += tmp->child[i]->cnt;
        }
        res += cntTmp;
        for(int i = c - 'a'; i < ALPHABET; i ++) {
            if(tmp->child[i]) cntTmp += tmp->child[i]->cnt;
        }
        res += tmp->cnt - cntTmp;
        if(! tmp->child[c - 'a']){
            break;
        }
        tmp = tmp->child[c - 'a'];
    }
    return res;
}

namespace process{
    int n, q;
    string d[maxn];
    string s;
    trie* root = getTrieNode();

    void process(){
        cin >> n >> q;
        cin >> s;
        for(int i = 1; i <= n; i ++) {
            cin >> d[i];
            Add(root, d[i]);
        }
        cout << Get(root, s) << "\n";
        for(int i = 1; i <= q; i ++){
            int k;
            char c;
            cin >> k >> c;
            for(int j = k - 1; j < s.size(); j ++) s[j] = c;
            cout << Get(root, s) << "\n";
        }
    }
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
    process::process();
    return 0;
}
