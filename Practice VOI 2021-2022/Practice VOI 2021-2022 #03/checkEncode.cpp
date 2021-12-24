#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "checkEncode"
#define inf 1e9
#define mod 1000000007
#define maxn 10000

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

struct Node{
    int child[26];
    bool isLeaf;

    Node(){
        reset(child);
        isLeaf = 0;
    }
};

int n;
string s;
vector<Node> trie;

void Push(string& str){
    int curNode = 0;
    for(char c: str){
        if(! trie[curNode].child[c - 'a']) {
            trie[curNode].child[c - 'a'] = trie.size();
            trie.push_back(Node());
        }
        curNode = trie[curNode].child[c - 'a'];
    }
    trie[curNode].isLeaf  = 1;
}

void init(){
    trie.push_back(Node());
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> s;
        Push(s);
    }
}

void process(){
    vector<vector<pii>> pre(trie.size(), vector<pii> (trie.size(), {-1, -1}));
    queue<pii> q;
    pre[0][0] = {0, 0};
    q.push({0, 0});
    while(! q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(trie[x].isLeaf && pre[0][y].first == -1){
            pre[0][y] = {x, y};
            q.push({0, y});
        }
        if(trie[y].isLeaf && pre[x][0].first == -1){
            pre[x][0] = {x, y};
            q.push({x, 0});
        }
        for(int i = 0; i < ALPHABET; i ++){
            int xx = trie[x].child[i], yy = trie[y].child[i];
            if(xx && yy && pre[xx][yy].first == -1){
                pre[xx][yy] = {x, y};
                q.push({xx, yy});
                if(xx != yy && trie[xx].isLeaf && trie[yy].isLeaf){
                    goto found;
                }
            }
        }
    }
    // not found
    cout << -1;
    return ;

found:
    int x = q.back().first, y = q.back().second;
    string a, b;
    int res = 0;
    while(x || y){
        int xx = pre[x][y].first, yy = pre[x][y].second;
        if(x == 0) a += '+';
        if(y == 0) b += '+';
        if(x && y){
            int c = 0;
            while(trie[xx].child[c] != x) c++;
            a += char(c + 'a');
            b += char(c + 'a');
        }
        x = xx;
        y = yy;
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    cout << a << "\n" << b;
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
    process();
    return 0;
}