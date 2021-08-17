#include<bits/stdc++.h>

using namespace std;

typedef pair<long long, int> pli;
typedef long long ll;
#define task "ranking"
#define maxn 2001
#define bit(x, i) ((x >> i) & 1)
#define inf 1000009

int n;
int p[maxn], a[maxn], s[maxn];
ll score[maxn], v[maxn];
int l[maxn], r[maxn];
bool visited[maxn];

void calc(){
    for(int i = 1; i <= n; i ++){
        ll tmp = (1 << ll(p[i])) + (1 << ll(a[i])) + (1 << ll(s[i]));
        score[i] = v[i] = tmp;
    }
    sort(v + 1, v + 1 + n);
    for(int i = 1; i <= n; i ++){
        int cnt = lower_bound(v + 1, v + n + 1, score[i]) - v;
        r[i] = max(r[i], cnt);
        l[i] = min(l[i], cnt);
    }
}

void sinh(int pos){
    if(pos == n + 1){
        calc();
        return;
    }
    for(int i = 1; i <= n; i ++) {
        if(! visited[i]){
            visited[i] = 1;
            s[pos] = i;
            sinh(pos + 1);
            visited[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++) l[i] = inf;
    for(int i = 1; i <= n; i ++) cin >> p[i];
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sinh(1);
    for(int i = 1; i <= n; i ++) cout << l[i] << " " << r[i] << "\n";
    return 0;
}