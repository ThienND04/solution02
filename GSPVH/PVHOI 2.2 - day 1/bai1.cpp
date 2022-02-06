#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bai1"
#define inf 1e9
#define mod 1000000007
#define maxn 2001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

namespace caculate{
    template<class T>
    void add(T& x, T y){
        x += y;
        if(x >= mod) x -= mod;
    }
    template<class T>
    void sub(T& x, T y){
        x -= y;
        if(x < 0) x += mod;
    }
    template<class T>
    void maximize(T& x, T y){
        if(x < y) x = y;
    }
    template<class T>
    void minimize(T& x, T y){
        if(x > y) x = y;
    }
}

using namespace caculate;

namespace process{
    int n, m;
    int e[maxn], res[300001];
    pli query[300001];

    int getResult(ll q){
        ll sum = q;
        int cnt = 0;
        priority_queue<int> pq;
        for(int i = 1; i <= n; i ++){
            sum += e[i];
            pq.push(- e[i]);
            if(sum < 0){
                sum += pq.top();
                pq.pop();
            }
            else cnt ++;
        }
        return cnt;
    }

    void calc(int l, int r, int minRes, int maxRes){
        if(l > r) return;
        if(minRes == maxRes){
            for(int i = l; i <= r; i ++) res[query[i].second] = minRes;
            return ;
        }
        int mid = (l + r) / 2;
        int x = getResult(query[mid].first);
        res[query[mid].second] = x;
        calc(l, mid - 1, minRes, x);
        calc(mid + 1, r, x, maxRes);
    }

    void init(){
        cin >> n >> m;
        for(int i = 1; i <= n;  i++) cin >> e[i];
        for(int i = 1; i <= m; i ++) {
            cin >> query[i].first;
            query[i].second = i;
            // cout << getResult(query[i].first) << " ";
        }
        sort(query + 1, query + m + 1);
    }


    void process(){
        init();
        calc(1, m, 0, n);
        for(int i = 1; i <= m; i ++){
            cout << res[i] << " ";
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
