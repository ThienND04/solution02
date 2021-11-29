#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 5000002
#define task "unique-substring"
#define BLOCK_SIZE 100001

#define mod 1000000007
#define inf 2100000000
#define LOG 30
#define reset(a) memset(a, 0, sizeof(a))
#define bit(x, i) ((x >> i) & 1)

const ll mod2 = 1ll * mod * mod;

class HashTable{
public:
    static const int B = 311;
private:
    int n;
    vector<int> h, hs;
public:
    HashTable(){}
    HashTable(const string& s){
        n = s.size();
        h.resize(n + 1);
        hs.resize(n + 1);
        h[0] = 1;
        hs[0] = 0;
        for(int i = 1; i <= n; i ++){
            h[i] = (1ll * h[i - 1] * B) % mod;
            hs[i] = (1ll * hs[i - 1] * B + s[i - 1]) % mod;
        }
    }
    int get(int left, int right){
        return (hs[right] - 1ll * hs[left - 1] * h[right - left + 1] + mod2) % mod;
    }
};

int n;
string s;
HashTable ht;
pii lsHs[maxn];

bool ok(int x){
    for(int i = 1; i<= n; i ++) lsHs[i] = {0, 0};
    for(int i = 1; i <= n - x + 1; i ++) lsHs[i] = {ht.get(i, i + x - 1), i};
    sort(lsHs + 1, lsHs + (n - x + 1) + 1);
    for(int i = 1; i <= n - x + 1; i ++) {
        if(lsHs[i].first != lsHs[i - 1].first && lsHs[i].first != lsHs[i + 1].first) return 1;
    }
    return 0;
}

void process(){
    cin >> s;
    n = s.size();
    ht = HashTable(s);
    int l = 0, r = s.size();
    while(r - l > 1){
        int mid = (l + r) >> 1;
        if(ok(mid)) r = mid;
        else l = mid;
    }
    for(int i = 1; i <= n; i ++) lsHs[i] = {0, 0};
    for(int i = 1; i <= n - r + 1; i ++) lsHs[i] = {ht.get(i, i + r - 1), i};
    sort(lsHs + 1, lsHs + (n - r + 1) + 1);
    string res = "-1";
    for(int i = 1; i <= n - r + 1; i ++) {
        if(lsHs[i].first != lsHs[i - 1].first && lsHs[i].first != lsHs[i + 1].first) {
            if(res == "-1" || res > s.substr(lsHs[i].second - 1, r)) {
                res = s.substr(lsHs[i].second - 1, r);
            }
        }
    }
    cout << res;
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
    process();
    return 0;
}