#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "digits"
#define maxn 2001
#define inf 1000000007
#define mod 998244353

struct action
{
    char tp;
    int p, t, d;
};


int subtask, t, n, m, q;
vector<int> dop[maxn];
action ac[maxn];
bool nghien[maxn];
bool uong[maxn][maxn];
int nguoi[maxn], nd[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> subtask >> t;
    while(t --){
        reset(uong);
        reset(nghien);
        reset(nguoi);
        reset(nd);
        cin >> n >> m >> q;
        for(int i = 1; i <= n; i ++) dop[i].clear();
        for(int i = 1; i <= q; i ++) {
            cin >> ac[i].tp >> ac[i].p;
            if(ac[i].tp == '+') cin >> ac[i].d;
            cin >> ac[i].t;
        }
        sort(ac + 1, ac + q + 1, [](action& a, action& b){return a.t < b.t; });
        int cnt = 0;
        for(int i = 1; i <= q; i ++){
            action a = ac[i];
            if(nghien[a.p]) continue;
            if(a.tp == '!'){
                nghien[a.p] = 1;
                cnt ++;
                for(int v: dop[a.p]){
                    nd[v] ++;
                }
            }
            else{
                if(uong[a.p][a.d]) continue;
                dop[a.p].push_back(a.t);
                uong[a.p][a.d] = 1;
                nguoi[a.d] ++;
            }
        }
        bool ok = 0;
        for(int i = 1; i <= m; i ++){
            if(nd[i] == cnt){
                ok = 1;
            }
        }
    }
    return 0;
}