#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "toy"
#define inf 1e9
#define mod 1000000007
#define maxn 500001

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
    int n;
    pii toys[maxn];
    int minSL[maxn], maxSL[maxn], minSR[maxn], maxSR[maxn];

    void init(){
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> toys[i].first >> toys[i].second;
        sort(toys + 1, toys + n + 1);
        minSL[1] = toys[1].second;
        for(int i = 2; i <= n; i ++){
            minSL[i] = min(minSL[i - 1], toys[i].second);
        }   
        maxSL[1] = toys[1].second;
        for(int i = 2; i <= n; i ++){
            maxSL[i] = max(maxSL[i - 1], toys[i].second);
        }  
        minSR[n] = toys[n].second;
        for(int i = n - 1; i >= 1; i --){
            minSR[i] = min(minSR[i + 1], toys[i].second);
        } 
        maxSR[n] = toys[n].second;
        for(int i = n - 1; i >= 1; i --){
            maxSR[i] = max(maxSR[i + 1], toys[i].second);
        }
    }

    bool checkCase1(int l, int r){
        if(l == 1) return 0;
        if(r == n) return 1;
        return (minSL[l - 1] <= minSR[r + 1] && maxSL[l - 1] >= maxSR[r + 1]);
    }
    //case1: 
    //minSL <= minSR
    //maxSL >= maxSR
    int findCase1(int right){
        int l = 1, r = right + 1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(checkCase1(mid, right)) l = mid;
            else r = mid;
        }
        if(checkCase1(l, right)) return l;
        return -1;
    }

    bool checkCase2(int l, int r){
        if(l == 1) return 0;
        if(r == n) return 0;
        return (minSL[l - 1] > minSR[r + 1] && maxSL[l - 1] >= maxSR[r + 1]);
    }
    //case2: 
    //minSL > minSR
    //maxSL >= maxSR
    int findCase2(int right){
        int l = 1, r = right + 1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(checkCase2(mid, right)) l = mid;
            else r = mid;
        }
        if(checkCase2(l, right)) return l;
        return -1;
    }

    bool checkCase3(int l, int r){
        if(l == 1) return 0;
        if(r == n) return 0;
        return (minSL[l - 1] <= minSR[r + 1] && maxSL[l - 1] < maxSR[r + 1]);
    }
    //case3: 
    //minSL <= minSR
    //maxSL < maxSR
    int findCase3(int right){
        int l = 1, r = right + 1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(checkCase3(mid, right)) l = mid;
            else r = mid;
        }
        if(checkCase3(l, right)) return l;
        return -1;
    }

    bool checkCase4(int l, int r){
        if(r == n) return 0;
        if(l == 1) return 1;
        return (minSL[l - 1] > minSR[r + 1] && maxSL[l - 1] < maxSR[r + 1]);
    }
    //case4: 
    //minSL > minSR
    //maxSL < maxSR
    int findCase4(int right){
        int l = 1, r = right + 1;
        while(r - l > 1){
            int mid = (l + r) / 2;
            if(checkCase4(mid, right)) l = mid;
            else r = mid;
        }
        if(checkCase4(l, right)) return l;
        return -1;
    }

    void process(){
        init();
        int res = inf;
        for(int r = 1; r <= n; r ++){
            int l, sum;
            l = findCase1(r);
            if(l != -1){
                sum = toys[r].first - toys[l].first;
                sum += maxSL[l - 1] - minSL[l - 1];
                minimize(res, sum);
            }
            l = findCase2(r);
            if(l != -1){
                sum = toys[r].first - toys[l].first;
                sum += maxSL[l - 1] - minSR[r + 1];
                minimize(res, sum);
            }
            l = findCase3(r);
            if(l != -1){
                sum = toys[r].first - toys[l].first;
                sum += maxSR[r + 1] - minSL[l - 1];
                minimize(res, sum);
            }
            l = findCase4(r);
            if(l != -1){
                sum = toys[r].first - toys[l].first;
                sum += maxSR[r + 1] - minSR[r + 1];
                minimize(res, sum);
            }
        }
        cout << res;
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
