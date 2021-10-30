#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 500001
#define task "gvstr"
#define MAG 500

#define reset(a) memset(a, 0, sizeof(a))

#define inBlock(pos) ((pos - 1) / BLOCK_SIZE + 1)

int n, numShort = 0, numLong = 0;
string t;
string shortStr[maxn], longStr[maxn];
int cntLeft[maxn], cntRight[maxn];
int z[maxn];

class trie{
public:
    #define ASCII(c) (c - 'a')
    #define NUM_ALPHABET 27

    struct Node
    {
        int cntTail;
        int child[NUM_ALPHABET];
        Node(): cntTail(0) {
            reset(child);
        }
    };
    

private:
    vector<Node> nodes;

public:
    trie(){
        nodes.push_back(Node());
    }

    void insert(const string& s){
        int cur = 0;
        for(int i = 0; i < s.size(); i ++){
            if(! nodes[cur].child[ASCII(s[i])]) {
                nodes[cur].child[ASCII(s[i])] = nodes.size();
                nodes.push_back(Node());
            }
            cur = nodes[cur].child[ASCII(s[i])];
        }
        nodes[cur].cntTail ++;
    }

    // Count how many string start at pos in s
    int search(const string& s, int pos){
        int cnt = 0;
        int cur = 0;
        for(int i = pos; i < s.size(); i ++){
            if(! nodes[cur].child[ASCII(s[i])]) return cnt;
            else {
                cnt += nodes[nodes[cur].child[ASCII(s[i])]].cntTail;
                cur = nodes[cur].child[ASCII(s[i])];
            }
        }
        return cnt;
    }
};

void init(){
    cin >> t >> n;
    string s;
    for(int i = 1; i <= n; i ++) {
        cin >> s;
        if(s.size() <= MAG) shortStr[++ numShort] = s;
        else longStr[++ numLong] = s;
    }
}

void z_funtion(string s){
    int left = 0, right = 0;
    z[0] = s.size();
    for(int i = 1; i < s.size(); i ++){
        if(i > right){
            left = right = i;
            while(right < s.size() && s[right] == s[right - left]) right ++;
            z[i] = right - left;
            right --;
        }
        else {
            int k = i - left;
            if(z[k] < right - i + 1) z[i] = z[k];
            else {
                left = i;
                while(right < s.size() && s[right] == s[right - left]) right ++;
                z[i] = right - left;
                right --;
            }
        }
    }
}

void solve(){

    reset(cntLeft);
    reset(cntRight);

    // caculate left to right

    for(int i = 1; i <= numLong; i ++){
        z_funtion(longStr[i] + t);
        for(int j = longStr[i].size(); j < longStr[i].size() + t.size(); j ++){
            if(z[j] >= longStr[i].size()) cntLeft[j - longStr[i].size()] ++;
        }
        reverse(longStr[i].begin(), longStr[i].end());
    }
    trie left;
    for(int i = 1; i <= numShort; i ++){
        left.insert(shortStr[i]);
        reverse(shortStr[i].begin(), shortStr[i].end());
    }

    for(int i = 0; i < t.size(); i ++){
        cntLeft[i] += left.search(t, i);
    }
    reverse(t.begin(), t.end());

    // calutlate right to left 

    for(int i = 1; i <= numLong; i ++){
        z_funtion(longStr[i] + t);
        for(int j = longStr[i].size(); j < longStr[i].size() + t.size(); j ++){
            if(z[j] >= longStr[i].size()) cntRight[t.size() - (j - longStr[i].size()) - 1] ++;
        }
    }
    trie right;
    for(int i = 1; i <= numShort; i ++){
        right.insert(shortStr[i]);
    }
    for(int i = 0; i < t.size(); i ++){
        cntRight[t.size() - i - 1] += right.search(t, i);
    }

    ll result = 0;

    for(int i = 1; i < t.size(); i ++){
        result += 1ll * cntLeft[i] * cntRight[i - 1];
    }

    cout << result;
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