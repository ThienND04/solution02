#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 100002
#define LOG 20
#define task "tournament"

#define reset(a) memset(a, 0, sizeof(a))

int lg2[maxn];

class RMQ{
private:
    int n;
    vector<int> a;
    vector<vector<int>> p, maxVal;

public:
    RMQ(){}
    RMQ(int _n){
        n = _n;
        a.resize(n + 4);
        p.resize(_n + 4);
        for(int i = 0; i <= n + 1; i ++) p[i].assign(LOG, 0);
        maxVal.resize(_n + 4);
        for(int i = 0; i <= n + 1; i ++) maxVal[i].assign(LOG, 0);

        for(int i = 1; i <= n; i ++){
            p[i][0] = i + 1;
        }
        
        for(int i = 1; i < LOG; i ++){
            for(int j = 1; j <= n; j ++){
                p[j][i] = p[p[j][i - 1]][i - 1];
            }
        }
    }

    void assign(int pos, int val){
        a[pos] = val;
    }

    void calc(){
        for(int i = 1; i <= n; i ++){
            maxVal[i][0] = a[i + 1];
        }
        for(int i = 1; i < LOG; i ++){
            for(int j = 1; j <= n; j ++){
                maxVal[j][i] = max(maxVal[j][i - 1], maxVal[p[j][i - 1]][i - 1]);
            }
        }
    }

    int getMax(int l, int r){
        int delta = r - l;
        if(delta == 0) return a[l];
        return max(maxVal[l][lg2[delta]], maxVal[r - (1 << lg2[delta])][lg2[delta]]);
    }
};

class BIT{
private:
    int n;
    int cnt[maxn];

public:
    BIT(){}
    BIT(int _n){
        n = _n;
    }
    
    void update(int pos, int c){
        while(pos <= n){
            cnt[pos] += c;
            pos += pos & -pos;
        }
    }

    int get(int x){
        int res = 0;
        while(x) {
            res += cnt[x];
            x -= x & - x;
        }
        return res;
    }

    int find(int k){
        int l = 1, r = n + 1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(get(mid) <= k) l = mid;
            else r = mid;
        }
        return l;
    }   
};

int n, c, r;
int k[maxn];
int s[maxn], e[maxn];
pii p[maxn], ran[maxn];
BIT bit;
RMQ maxRange;

void init(){
    cin >> n >> c >> r;

    int val = 1;
    int tp = 0;
    for(int i = 1; i < maxn; i ++){
        lg2[i] = tp - 1;
        if(i == val){
            lg2[i] = tp;
            tp ++;
            val <<= 1;
        }
    }
    // for(int i = 1; i <= 30; i ++) cerr << i << " " << lg2[i] << "\n";

    maxRange = RMQ(n - 1);
    bit = BIT(n);

    for(int i = 1; i < n; i ++) {
        cin >> k[i];
        bit.update(i, 1);
        maxRange.assign(i, k[i]);
    }
    bit.update(n, 1);

    maxRange.calc();

    for(int i = 1; i <= c; i ++) {
        cin >> s[i] >> e[i];
    }
    
}

void prepare(){
    for(int i = 1; i <= n; i ++) p[i] = {i, i};
    for(int i = 1; i <= c; i ++){
        // cerr << s[i] << " " << e[i] << endl;
        int posL = bit.find(s[i]);
        int posR = bit.find(e[i]);
        ran[i].first = p[posL].first;
        ran[i].second = p[posR].second;
        p[posL].second = p[posR].second;
        for(int j = 0; j < e[i] - s[i]; j ++){
            int tmp = bit.find(s[i] + 1);
            bit.update(tmp, -1);
        }
    }
    int cnt = 0;
    for(int i = 1; i <= c; i ++){
        // cerr << maxRange.getMax(ran[i].first, ran[i].second - 1) << endl;
        // assert(ran[i].first <= n && ran[i].first <= n);
        if(ran[i].first == ran[i].second || maxRange.getMax(ran[i].first, ran[i].second - 1) < r){
            ran[++ cnt] = ran[i];
        }
    }
    c = cnt;
}

int cntA[maxn], cntS[maxn];

void process(){
    prepare();
    // cerr << c << endl;
    // for(int i = 1; i <= c; i ++){
    //     cerr << ran[i].first << " " << ran[i].second << endl;
    // }
    reset(cntA);
    reset(cntS);
    for(int i = 1; i <= c; i ++){
        cntA[ran[i].first] ++;
        cntS[ran[i].second] ++;
    }
    int res = 0, tmp = 0;
    for(int i = 1; i <= n; i ++){
        tmp += cntA[i];
        res = max(res, tmp);
        tmp -= cntS[i];
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
    init();
    process();
    return 0;
}