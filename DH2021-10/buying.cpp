#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "buying"
#define maxn 2001
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
    bool operator < (const data& a){
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

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        a[i].id = i;
        cin >> a[i].sc1;
    }
    for(int i = 1; i <= n; i ++)  cin >> a[i].sc2;
    sort(a + 1, a + n + 1);
}

void solve(){

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    return 0;
}