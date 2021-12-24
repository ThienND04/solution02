#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "leaves"
#define maxn 100001
#define inf 1e18
#define mod 1000000007

int n, k;
ll weight[maxn];
ll s[maxn];
ll dp[maxn][13];
vector<ll> p[13], q[13];
vector<double> x[13];
int u[13];

bool ok(int id, ll p0, ll q0){
    if(p0 == p[id].back()) return 0;
    if(p[id].size() == 1) return 1;
    int m = p[id].size()  -1;
    double x1 = 1.0 * (q[id][m] - q0) / (p0 - p[id][m]);
    double x2 = 1.0 * (q[id][m - 1] - q0) / (p0 - p[id][m - 1]);
    return x1 > x2;
}

void add(int id, ll p0, ll q0){
    if(p[id].size() && p[id].back() == p0 && q0 >= q[id].back()) return;
    while(p[id].size() && !ok(id, p0, q0)) {
        p[id].pop_back();
        q[id].pop_back();
        x[id].pop_back();
    }
    if(p[id].size() == 1 && p[id].back() == p0 && q0 < q[id].back()) q[id][q[id].size() - 1] = q0;
    else {
        p[id].push_back(p0);
        q[id].push_back(q0);
        x[id].push_back(0);
    }
    int m = p[id].size() - 1;
    if(m == 0) {
        x[id][m] = -inf;
    }
    else{
        x[id][m] = 1.0 * (q[id][m - 1] - q[id][m]) / (p[id][m] - p[id][m - 1]);
    }
}

ll get(int id, int xx){
    if(u[id] >= p[id].size()) u[id] = p[id].size() - 1;
    while(u[id] < p[id].size() && xx >= x[id][u[id]]) u[id] ++;
    u[id] --;
    return p[id][u[id]] * xx + q[id][u[id]];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> weight[i];
    reverse(weight + 1, weight + n + 1);
    for(int i = 1; i <= n; i ++){
        weight[i] = weight[i - 1] + weight[i];
        s[i] = s[i - 1] + weight[i];
    }
    add(0, 0, 0);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= min(i, k); j ++){
            dp[i][j] = s[i - 1] + get(j - 1, i);
            add(j, -weight[i], dp[i][j] - s[i] + weight[i] * (i + 1));
        }
    }
    cout << dp[n][k];
    return 0;
}