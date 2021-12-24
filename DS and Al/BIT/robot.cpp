#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a))
#define task "robot"
#define mod 30103
#define inf 999999999
#define maxn 500001

struct data
{
    int l, r, id;
};

struct data2
{
    int x, l, r, t;
};


bool cmp(data& a, data& b){
    if(a.id != b.id) return (a.id < b.id);
    return (a.l < b.l);
}

bool cmp2(data2& a, data2& b){
    if(a.x != b.x) return a.x < b.x;
    return a.t > b.t;
}

int n, m, k;
ll sum = 0;
vector<data>ngang, doc, na, da;
vector<data2> cc;
vector<int> v;
int bit[maxn];
bool mark[2][maxn];

void update(int x, int v){
    while(x < maxn){
        bit[x] += v;
        x += x & -x;
    }
}

ll get(int x){
    int res = 0;
    while(x) {
        res += bit[x];
        x -= x & -x;
    }
    return res;
}

ll getRange(int l, int r){
    return get(r) - get(l - 1);
}

void init(){
    cin >> n >> m >> k;
    for(int i  = 0; i < k; i ++){
        int x, y;
        char t;
        cin >> x >> y >> t;
        if(t == 'N') doc.push_back({x, n, y});
        if(t == 'E') ngang.push_back({y, m, x});
        if(t == 'S') doc.push_back({1, x, y});
        if(t == 'W') ngang.push_back({1, y, x});
    }
}

void khop(vector<data> & vt, int t){
    reset(mark[t]);
    for(int i = 0; i < vt.size() - 1; i ++){
        data x1 = vt[i];
        data &x2 = vt[i + 1];
        if(x1.id != x2.id) continue;
        if(x1.r >= x2.l){
            x2.l = x1.l;
            x2.r = max(x2.r, x1.r);
            mark[t][i] = 1;
        }
    }
    for(int i = 0; i < vt.size(); i ++){
        if(mark[t][i]) continue;
        v.push_back(vt[i].l);
        v.push_back(vt[i].r);
        v.push_back(vt[i].id);
    }
}   

void roiRac(vector<data>& in, vector<data>& out, int t){
    for(int i = 0; i < in.size(); i ++){
        if(mark[t][i]) continue;
        int x = lower_bound(v.begin(), v.end(), in[i].l) - v.begin() + 1;
        int y = lower_bound(v.begin(), v.end(), in[i].r) - v.begin() + 1;
        int z = lower_bound(v.begin(), v.end(), in[i].id) - v.begin() + 1;
        out.push_back({x, y, z});
        sum += in[i].r - in[i].l + 1;
    }
}

void solve(){
    sort(doc.begin(), doc.end(), cmp);
    sort(ngang.begin(), ngang.end(), cmp);
    khop(doc, 0);
    khop(ngang, 1);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    roiRac(doc, da, 0);
    roiRac(ngang, na, 1);
    for(data e: da){
        cc.push_back({e.l, e.id, 0, 1});
        cc.push_back({e.r, e.id, 0, -1});
    }
    for(data e: na){
        cc.push_back({e.id, e.l, e.r, 0});
    }
    sort(cc.begin(), cc.end(), cmp2);
    for(data2 e: cc){
        if(e.t){
            update(e.l, e.t);
        }
        else {
            sum -= getRange(e.l, e.r);
        }
    }
    cout << sum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();
    solve();
    return 0;
}