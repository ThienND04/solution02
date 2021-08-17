#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "ranking"
#define maxn 20
#define bit(x, i) ((x >> i) & 1)
#define inf 1000000000000000

struct data
{
    int id, sc1, sc2, sc3;
    // 2^sc1 > 2^sc2 + 2^sc3
    data(){
        id = 0;
        sc1 = sc2 = sc3 = -1;
    }
    bool operator < (const data& a){
        if(sc1 != a.sc1) return sc1 < a.sc1;
        if(sc2 != a.sc2) return sc2 < a.sc2;
        return sc3 < a.sc3;
    }
    bool operator <= (const data& a){
        if(sc1 != a.sc1) return sc1 < a.sc1;
        if(sc2 != a.sc2) return sc2 < a.sc2;
        return sc3 <= a.sc3;
    }
    void reArange(){
        if(sc1 < sc2) swap(sc1, sc2);
        if(sc1 < sc3) swap(sc1, sc3);
        if(sc2 < sc3) swap(sc2, sc3);
        if(sc2 == sc3 && sc3 != -1) {
            sc2 ++;
            sc3 = -1;
        }
        if(sc1 < sc2) swap(sc1, sc2);
        if(sc1 == sc2 && sc2 != -1) {
            sc1 ++;
            sc2 = -1;
        }
    }
};

int n;
data a[maxn];
int best[maxn], wost[maxn];

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        a[i].id = i;
        cin >> a[i].sc1;
    }
    for(int i = 1; i <= n; i ++)  {
        cin >> a[i].sc2;
        a[i].reArange();
    }
    sort(a + 1, a + n + 1);
}

void calcBest(int p){
    data bestSc = a[p];
    bestSc.sc3 = 1;
    int l = 0, r = n + 1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        bool check = 1;
        int curSc3 = n;
        for(int i = mid; i <= n; i ++){
            if(i == p) continue;
            data tmp = a[i];
            tmp.sc3 = curSc3 --;
            tmp.reArange();
            if(tmp <= bestSc){
                check = 0;
                break;
            }
        }
        if(check){
            r = mid;
            best[a[p].id] = n - curSc3;
        }
        else l = mid;
    }
}

void solve(){
    for(int i = 1; i <= n; i ++) calcBest(i);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();
    solve();
    for(int i = 1; i <= n; i ++) cout << best[i] << "\n";
    return 0;
}