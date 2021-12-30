#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "thuyvan"
#define inf 1e9
#define mod 1000000007
#define maxn 1001

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

class HashTable{
private: 
    const int BASE = 256;
    const int MOD = 1e9 + 2277;
    const ll MOD2 = 1ll * MOD * MOD;

    int n;
    vector<int> lt;
    vector<int> h;

public:
    HashTable(){ }
    void init(const string& s){
        n = s.size() - 1;
        h.resize(n + 1);
        lt.resize(n + 1);
        h[0] = 0;
        lt[0] = 1;
        for(int i = 1; i <= n; i ++) lt[i] = (1ll * lt[i - 1] * BASE) % MOD;
        for(int i = 1; i <= n; i ++){
            h[i] = (1ll * h[i - 1] * BASE + s[i]) % MOD;
        }
    }
    int get(int left, int right){
        return (h[right] - 1ll * h[left - 1] * lt[right - left + 1] + MOD2) % MOD;
    }
};

namespace process
{
    int n, k;
    string s[maxn];
    int len[maxn];

    HashTable hs[maxn];

    int ok(int x){
        map<int, int> mp;
        for(int i = 1; i <= n; i ++){
            map<int, bool> mp2;
            for(int j = 1; j <= len[i] - x + 1; j ++){
                mp2[hs[i].get(j, j + x - 1)] = 1;
            }
            for(auto tmp: mp2){
                mp[tmp.first] ++;
            }
        }
        for(auto tmp: mp){
            if(tmp.second >= k) return tmp.first;
        }
        return -1;
    }

    void process()
    {
        cin >> n >> k;
        cerr << 1;
        for(int i = 1; i <= n; i ++){
            cin >> s[i];
            len[i] = s[i].size();
            s[i] = " " + s[i];
            hs[i].init(s[i]);
        }
        int l = 0, r = *max_element(len + 1, len + n + 1) + 1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(ok(mid) != -1)  l = mid;
            else r = mid;
        }
        int h = ok(l);
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= len[i] - l + 1; j ++){
                if(hs[i].get(j, j + l - 1) == h){
                    cout << s[i].substr(j, l);
                    exit(0);
                }
            }
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
