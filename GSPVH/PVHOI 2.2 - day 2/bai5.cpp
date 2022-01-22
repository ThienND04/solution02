#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bai5"
#define inf 1e9
#define mod 1000000007
#define maxn 5001

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

struct Node{
    Node* child[ALPHABET];
    int cnt = 0;

    Node(){
        for(int i = 0; i < ALPHABET; i ++) child[i] = NULL;
    }
};

Node* getNode(){
    Node* res = new Node;
    for(int i = 0; i < ALPHABET; i ++) res->child[i] = NULL;
    res->cnt = 0;
    return res;
}

void Add(Node* root, const string& s){
    Node* tmp = root;
    for(char c: s){
        if(! tmp->child[c - 'a']){
            tmp->child[c - 'a'] = getNode();
        }
        tmp->child[c - 'a']->cnt ++;
        tmp = tmp->child[c - 'a'];
    }
}

ll get(Node* root, const string& s){
    Node* tmp = root;
    ll res = 0;
    for(char c: s){
        if(! tmp->child[c- 'a']) break;
        res += tmp->child[c - 'a']->cnt;
        tmp = tmp->child[c - 'a'];
    }
    return res;
}

namespace process{
    int n, k;
    string s[maxn];
    int d[maxn][maxn];

    int lcp(int x, int y){
        int len = 0;
        while(len < s[x].size() && len < s[y].size() && s[x][len] == s[y][len]){
            len ++;
        }
        return len;
    }

    void subtask4(){
        for(int i = 1; i <= n; i ++){
            for(int j = i + 1; j <= n; j ++){
                d[i][j] = lcp(i, j);
            }
        }
        ll res = 0;
        for(int x = 0; x < (1 << 20); x ++){
            if(__builtin_popcount(x) != k) continue;
            ll sum = 0;
            for(int i = 0; i < n; i ++){
                if(! bit(x, i)) continue;
                for(int j = i + 1; j < n; j ++){
                    if(! bit(x, j)) continue;
                    sum += d[i + 1][j + 1];
                }
            }
            maximize(res, sum);
        }
        cout << res;
    }

    vector<int> ch[ALPHABET];
    ll f[maxn][ALPHABET], l[maxn][ALPHABET];
    bool checkSub1(){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j < s[i].size(); j ++) {
                if(s[i][j] != s[i][0]) return 0;
            }
        }
        return 1;
    }
    void subtask1(){
        reset(f); reset(l);
        Node* root = getNode();
        for(int i = 1; i <= n; i ++){
            ch[s[i][0] - 'a'].push_back(i);
        }
        for(int c = 0; c < ALPHABET; c ++) {
            sort(ch[c].begin(), ch[c].end(), [](int a, int b){return s[a].size() > s[b].size(); });
            ll sum = 0;
            for(int t = 0; t < ch[c].size(); t ++){
                sum += get(root, s[ch[c][t]]);
                Add(root, s[ch[c][t]]);
                l[t + 1][c] = sum;
            }
        }
        for(int i = 0; i <= k; i ++) f[i][0] = l[i][0];
        for(int c = 1; c < ALPHABET; c ++){
            for(int i = 0; i <= k; i ++){
                for(int j = 0; j <= i; j ++){
                    ll sum = f[j][c - 1] + l[i - j][c];
                    maximize(f[i][c], sum);
                }
            }
        }
        cout << f[k][ALPHABET - 1];
    }

    void subtask2(){
        ll res = 0;
        Node* root = getNode();
        for(int i = 1; i <= n; i ++){
            res += get(root, s[i]);
            Add(root, s[i]);
        }
        cout << res;
    }

    void process(){
        cin >> n >> k;
        for(int i = 1; i <= n; i ++) cin >> s[i];
        if(n <= 20) return subtask4();
        if(k == n) return subtask2();
        if(checkSub1()) return subtask1();
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
