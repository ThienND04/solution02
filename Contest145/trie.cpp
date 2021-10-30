#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "trie"
#define maxn 1001
#define inf 1000000007
#define mod 998244353

#define maxGroup 101

struct Node
{
    bool hasWord;
    int numWord;
    Node *child[26];
    pii dp[maxGroup];

    Node()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        hasWord = 0;
        numWord = 0;
    }
};

int n, m, cnt = 0;
string s[maxn];
Node *root;
pii f[maxn][101], g[maxn][101];

void addNode(const string &str)
{
    Node *p = root;
    for (char c : str)
    {
        if (p->child[c - 'A'] == NULL)
        {
            p->child[c - 'A'] = new Node;
        }
        p = p->child[c - 'A'];
    }
    p->hasWord = 1;
    p->numWord ++;
}

pii best[maxGroup], preBest[maxGroup];

void DFS(Node* p)
{
    for(int i = 0; i < 26; i ++) if(p->child[i] != NULL) DFS(p->child[i]);

    for(int i = 0; i <= m; i ++) best[i] = {-inf, 0};

    if(p->hasWord) best[1] = {0, 1};
    else best[0] = {0, 1};

    for(int i = 0; i < 26; i ++) if(p->child[i] != NULL) {
        Node* ch = p-> child[i];

        
    }
}

void init()
{
    cin >> n >> m;
    root = new Node();

    for (int i = 1; i <= n; i++)
    {
        string word;
        cin >> word;
        addNode(word);
    }
}

void solve(){
    
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
    init();
    solve();
    return 0;
}