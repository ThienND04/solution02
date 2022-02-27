 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "triangle"
#define inf 2000000007
#define mod 1000000007
#define maxn 100001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 20
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
    int n;
    int a[maxn];
    pii minFirst[maxn][LOG], minSecond[maxn][LOG], maxVal[maxn][LOG];
    pii tmp[5];

    template<class T> 
    void minimize(T& _minFirst, T& _minSecond, T _val){
        if(_val < _minFirst){
            _minSecond = _minFirst;
            _minFirst = _val;
        }
        else caculate::minimize(_minSecond, _val);
    }

    

    void sub3(){
        int res = 0;
        for(int i = 1; i < n; i ++){
            int p = lower_bound(a + i + 1, a + n + 1, a[i] + a[i + 1]) - a - 1;
            if(p - i + 1 >= 3) maximize(res, p - i + 1);
        }
        cout << res;
    }

    void Query(int& minF, int& minS, int& maxV, int l, int r){
        int j = log2(r - l + 1);
        int cnt = 0;
        maxV = max(maxVal[l][j].first, maxVal[r - (1 << j) + 1][j].first);
        if(maxVal[l][j].second != maxVal[r - (1 << j) + 1][j].second) {
            tmp[cnt ++] = min(maxVal[l][j], maxVal[r - (1 << j) + 1][j]);
        }
        tmp[cnt ++] = minFirst[l][j]; tmp[cnt ++] = minSecond[l][j];
        tmp[cnt ++] = minFirst[r - (1 << j) + 1][j]; tmp[cnt ++] = minSecond[r - (1 << j) + 1][j];
        
        sort(tmp, tmp + cnt);
        minF = tmp[0].first;
        for(int i = 1; i < cnt; i ++){
            if(tmp[i] != tmp[0]){
                minS = tmp[i].first;
                return;
            }
        }
    }
    
    bool ok(int x){
        // 
        int minF, minS, maxV;
        for(int i = 1; i + x - 1 <= n; i ++){
            Query(minF, minS, maxV, i, i + x - 1);
            // cerr << minF << " " << minSecond << " " << maxV << "\n";
            if(minF + minS > maxV) return 1;
        }
        return 0;
    }

    void process(){
        cin >> n;
        for(int i = 1; i <= n; i ++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i ++){
            maxVal[i][0] = {a[i], i};
            minFirst[i][0] = {inf, i};
            minSecond[i][0] = {inf, i};
        }
        for(int j = 1; j < LOG; j ++){
            for(int i = 1; i <= n && i + (1 << j) - 1 <= n; i ++){
                maxVal[i][j] = max(maxVal[i][j - 1], maxVal[i + (1 << j - 1)][j - 1]);
                tmp[0] = min(maxVal[i][j - 1], maxVal[i + (1 << j - 1)][j - 1]);
                tmp[1] = minFirst[i][j - 1]; tmp[2] = minSecond[i][j - 1];
                tmp[3] = minFirst[i + (1 << j - 1)][j - 1]; tmp[4] = minSecond[i + (1 << j - 1)][j - 1];

                sort(tmp, tmp + 5);
                minFirst[i][j] = tmp[0];
                minSecond[i][j] = tmp[1];
            }
        }

        int l = 3, r = n + 1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(ok(mid)) l = mid;
            else r = mid;
        }

        if(ok(l)) cout << l;
        else {
            // assert(0);
            cout << 0;
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
