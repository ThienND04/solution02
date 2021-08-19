#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "caribe"
#define maxn 41
#define bit(x, i) ((x >> i) & 1)
#define inf 1e9

int n, k, m;
int a[maxn], b[maxn];
int res = 0;
vector<pii> v1, v2;

void duyet(int p, int kg, int s, vector<pii>& vt){
    if(p > n){
        if(kg <= k) {
            vt.push_back({kg, s});
        }
        return;
    }
    for(int i = p + 1; i <= n + 1; i ++) duyet(i, kg + a[i], s + b[i], vt);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> m >> k;
    n = m / 2;
    for(int i = 1; i <= n; i ++) cin >> a[i] >> b[i];
    v1.push_back({0, 0});
    duyet(0, 0, 0, v1);
    sort(v1.begin(), v1.end());
    n = m - n;
    for(int i = 1; i <= n; i ++) cin >> a[i] >> b[i];
    v2.push_back({0, 0});
    duyet(0, 0, 0, v2);
    sort(v2.begin(), v2.end());
    int j = 0;
    int ma = 0;
    for(int i = v2.size() - 1; i >= 0; i --){
        while(v1[j].first + v2[i].first <= k && j < v1.size()) {
            ma = max(ma, v1[j ++].second);
        }
        res = max(res, v2[i].second + ma);
    }
    cout << res;
    return 0;
}