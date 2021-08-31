#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 100001
#define task "car"
#define inf 1000000000

int n;
int a[maxn], b[maxn];
int id[maxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
        id[i] = i;
    }
    sort(id + 1, id + n + 1, [](int x, int y){return 1.0 * a[x] / b[x] > 1.0 * a[y] / b[y]; });
    int sumb = 0;
    ll res = 0;
    for(int i = 1; i <= n; i ++){
        sumb += b[id[i]];
        res += 1ll * sumb * a[id[i]];
    }
    cout << res << "\n";
    for(int i = 1; i <= n; i ++) cout << id[i] << " ";
    return 0;
}