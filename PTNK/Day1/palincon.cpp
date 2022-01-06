#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "palincon"
#define inf 1e9
#define mod 1000000007
#define maxn 1000001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

namespace caculate
{
    template <class T>
    void add(T &x, T y)
    {
        x += y;
        if (x >= mod)
            x -= mod;
    }
    template <class T>
    void sub(T &x, T y)
    {
        x -= y;
        if (x < 0)
            x += mod;
    }
    template <class T>
    void maximize(T &x, T y)
    {
        if (x < y)
            x = y;
    }
    template <class T>
    void minimize(T &x, T y)
    {
        if (x > y)
            x = y;
    }
}

using namespace caculate;

queue<int> empQ;

struct trieNode
{
    trieNode* child[ALPHABET];
    queue<int> q;

    trieNode(){
        for(int i = 0; i < ALPHABET; i ++) child[i] = NULL;
    }

    void insert(string& s, int t){
        trieNode *cur = this;
        for (char c : s)
        {
            if (! cur->child[c - 'a'])
            {
                cur->child[c - 'a'] = new trieNode;
            }
            cur = cur->child[c - 'a'];
        }
        cur->q.push(t);
    }

    queue<int>& find(string s){
        trieNode *cur = this;
        for (char c : s)
        {
            if (cur->child[c - 'a'])
            {
                cur = cur->child[c - 'a'];
            }
            else
            {
                return empQ;
            }
        }
        return cur->q;
    }

};

namespace process
{
    int n, k;
    string s[maxn];
    int order[maxn], lf = 0, rt = n + 1;
    
    trieNode trie;
    
    bool ok[maxn];

    bool check(int j){
        int l = 0, r = k - 1;
        while(l < r){
            if(s[j][l] != s[j][r]) return 0;
            l ++;
            r --;
        }
        return 1;
    }

    void process()
    {
        // cerr << 0;
        reset(ok);
        cin >> n >> k;
        rt = n + 1;
        for(int i = 1; i <= n; i ++){
            cin >> s[i];
            queue<int>& q = trie.find(s[i]);
            if(q.empty()){
                reverse(s[i].begin(), s[i].end());
                trie.insert(s[i], i);
            }
            else{
                order[++ lf] = i;
                ok[i] = 1;
                order[-- rt] = q.front();
                ok[order[rt]] = 1;
                q.pop();
            }
        }
        if(n % 2 == 0 && lf != rt - 1){
            cout << -1;
            return;
        }
        if(n % 2 == 1 && lf != rt - 2){
            cout << -1;
            return;
        }
        for(int i = 1; i <= n; i ++){
            if(! ok[i]){
                if(! check(i)) {
                    cout << -1;
                    return;
                }
                else{
                    order[++ lf] = i;
                }
            }
        }
        for(int i = 1; i <= n; i ++) cout << order[i] << " ";
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
