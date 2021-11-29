#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "j"
#define inf 1000000000
#define mod 1000000007
#define maxn 500001

const ll mod2 = 1ll * mod * mod;

class HashTable{
public:
    static const int B = 31;
    string s;
    int n;
    int h[maxn], hs[maxn];
    
    HashTable() {}
    HashTable(const string& _s){
        n = _s.size();
        s = ' ' + _s;

        h[0] = 1;
        for(int i = 1; i <= n; i ++) h[i] = (1ll * h[i - 1] * B) % mod;
        calc();
    }

    void calc(){
        hs[0] = 0;
        for(int i = 1; i <= n; i ++){
            hs[i] = (1ll * hs[i - 1] * B + s[i]) % mod;
        }
    }   

    int get(int left, int right){
        return (hs[right] - 1ll * hs[left - 1] * h[right - left + 1] + mod2) % mod;
    }
};

string s;
int n;
HashTable h, hr;

bool ok(int x){
    for(int i = 1; i <= n - x + 1; i ++){
        if(h.get(i, i + x - 1) == hr.get(n - i - x + 2 ,n - i + 1)) return 1;
    }
    return 0;
}

void process(){
    cin >> s;
    n = s.size();

    h = HashTable(s);
    reverse(s.begin(), s.end());
    hr = HashTable(s);

    s = ' ' + s;
    if(n >= 100) for(int i = 1; i <= n - 100 + 1; i ++){
        if(h.get(i, i + 99) == hr.get(n - i - 98, n - i + 1)){
            cout << s.substr(i, 100);
            return ;
        }
    }
    int l = 0, r = n + 1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(ok(mid)) l = mid;
        else r = mid;
    }
    for(int i = 1; i <= n - l + 1; i ++){
        if(h.get(i, i + l - 1) == hr.get(n - i - l + 2 ,n - i + 1)) {
            cout << s.substr(i, l);
            return ;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    process();
    return 0;
}