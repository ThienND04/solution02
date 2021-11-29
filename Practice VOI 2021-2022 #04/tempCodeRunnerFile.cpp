#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<long long, int> pli;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "kary"
#define inf 1e9
#define mod 2021
#define maxn 30

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

#define maxVal(s) (s.empty() ? 0 : *s.rbegin())

int k, h, n;
ll num[maxn];
ll maxId[maxn];
vector<ll> a;
queue<pli> q;

void init(){
    cin >> k >> h >> n;
    a.resize(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }   
    sort(a.rbegin(), a.rend());
    maxId[0] = num[0] = 1;
    for(int i = 1; i < h; i ++){
        num[i] = num[i - 1] * k;
        maxId[i] = maxId[i - 1] + num[i];
    }
}

ll getPar(ll u){
    int lv = lower_bound(maxId, maxId + h, u) - maxId;
    if(lv == 0) return -1;
    if(lv == 1) return 1;
    return ((u - maxId[lv - 1] - 1) / k + 1 + maxId[lv - 2]);
}       

void process(){
    init();
    int res = 0;
    int i = 1;
    pli pre, cur;
    pre = {a[0], 1};
    q.push({getPar(a[0]), 1});
    while(pre.second < n){
        if(i == n){
            cur = q.front();
            q.pop();
        }
        else if(q.empty()){
            cur = {a[i++ ], 1};
        }
        else {
            if(a[i] < q.front().first){
                cur = q.front();
                q.pop();
            }
            else {
                cur = {a[i ++], 1};
            }
        }
        if(cur.first != pre.first){
            res ++;
            pre = cur;
            cur.first = getPar(cur.first);
            q.push(cur);
        }
        else{
            pre.second += cur.second;
            q.back().second += cur.second;
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