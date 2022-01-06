//Dai Ca Di Hoc
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define Rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define For(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define PB push_back
#define mp make_pair
#define F first
#define S second
#define maxn 100005
#define MOD 1000000007
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define Task "seladd"

using namespace std;

typedef long long ll;
typedef long double ld;

struct data{
    int L, R, W;
};

int n, m, k;
int a[maxn], need[12];
data Q[maxn];
vector <int> In[maxn], Out[maxn], Stop[maxn];
ll T[maxn];

void Update(int x, int delta){
    for(; x < maxn; x += x & -x) T[x] += delta;
}

ll Get(int x){
    ll sum = 0;
    for (; x; x -= x&-x) sum += T[x];
    return sum;
}

int Get_Time(ll x){
    int pos = 0;
    for (int i = log2(m); i >= 0; i--){
        int u = 1 << i;
        if (pos + u > m) continue;
        if (x >= T[pos+u]) x -= T[pos+u], pos += u;
    }
    if (x == 0) return pos + 1;
    return m+1;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= k; i++) cin >> need[i];
    sort(need+1, need+k+1);
    for (int L, R, W, i = 1; i <= m; i++){
        cin >> L >> R >> W;
        Q[i] = {L, R, W};
        In[L].PB(i);
        Out[R+1].PB(i);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int x : In[i]) Update(x, Q[x].W);
        for (int x : Out[i]) Update(x, -Q[x].W);
        for (int type = 1; type <= k; type++){
            int t = Get_Time(need[type]-a[i]);
            if (t <= m){
                Stop[t].PB(i);
                break;
            }
        }
    //    cerr << resi.F << endl;
    }
    ll sum = accumulate(a+1, a+n+1, 0ll);
    reset(T);
    for (int i = 1; i <= m; i++){
        for (int x : Stop[i]) Update(x, 1);
        int cnt = Get(Q[i].R) - Get(Q[i].L-1);
        sum += (ll)Q[i].W * (Q[i].R - Q[i].L + 1 - cnt);
        cout << sum << "\n";
    }
    return 0;
}

