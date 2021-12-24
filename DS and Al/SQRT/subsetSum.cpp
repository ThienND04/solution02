#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 100001
#define task "subsetSum"
#define BLOCK_SIZE 500

#define inBlock(pos) ((pos - 1) / BLOCK_SIZE + 1)

#define reset(a) memset(a, 0, sizeof(a))

ll a[maxn];

class bigSet{
public:
    int size, n;
    ll total, value;
    bitset<maxn> ok;
    vector<int> s;

public:
    bigSet(int _n, int _size): n(_n), size(_size), value(0){
        s.resize(size);
        total = 0;
        for(int i = 0; i < size; i ++){
            cin >> s[i];
            total += a[s[i]];
            ok[s[i]] = 1;
        }
    }

    void update(ll d){
        value += d;
    }
};

int n, m, q;
vector<vector<int>> s, chung1, chung2;
vector<bigSet> bs;
pii id[maxn];

void init(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    for(int i = 1; i <= m; i ++){
        int sz;
        cin >> sz;
        if(sz <= BLOCK_SIZE){
            id[i] = {0, s.size()};
            s.push_back(vector<int> ());
            s.back().resize(sz);
            for(int & element: s.back()) cin >> element;
        }
        else{
            id[i] = {1, bs.size()};
            bs.push_back(bigSet(n, sz));
        }
    }

    // init chung
    chung1.resize(s.size());
    for(int i = 0; i < s.size(); i ++){
        chung1[i].resize(bs.size());
    }
    chung2.resize(bs.size());
    for(int i = 0; i < bs.size(); i ++) {
        chung2[i].resize(bs.size());
    }


    for(int i = 0; i < bs.size(); i ++){
        for(int j = 0; j < s.size(); j ++){
            for(int v: s[j]){
                if(bs[i].ok[v]) chung1[j][i] ++;
            }
        }
        for(int j = 0; j < bs.size(); j ++){
            if(j == i) continue;
            for(int v: bs[j].s){
                if(bs[i].ok[v]) chung2[j][i] ++;
            }
        }
    }
}

void add(int t, int k, int d){
    if(t == 0){
        for(int v: s[k]){
            a[v] += d;
        }
        for(int i = 0; i < bs.size(); i ++){
            bs[i].total += 1ll * chung1[k][i] * d;
        }
    }
    else{
        bs[k].total += 1ll * d * bs[k].size;
        bs[k].update(d);
    }
}

ll query(int t, int k){
    ll result = 0;
    if(t == 0){
        for(int v: s[k]){
            result += a[v];
        }
        for(int i = 0; i < bs.size(); i ++){
            result += 1ll * bs[i].value * chung1[k][i];
        }
        return result;
    }
    else{
        result = bs[k].total;
        for(int i = 0; i < bs.size(); i ++){
            if(i == k) continue;
            result += 1ll * chung2[k][i] * bs[i].value;
        }
        return result;
    }
}

void solve(){
    while(q --){
        char type;
        int x, k;
        cin >> type >> k;
        if(type == '?'){
            cout << query(id[k].first, id[k].second) << "\n";
        }
        else{
            cin >> x;
            add(id[k].first, id[k].second, x);
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
    init();
    solve();
    return 0;
}