#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "sweets"
#define inf 1e9
#define mod 1000000007
#define maxn 30

#define bit(x, i) ((x >> i) & 1)

int n, k;
int a[maxn], p[maxn], q[maxn], cnt = 0, t = 1;
ll sum = 0, tb = 0;

void duyet(int pos){
    if(pos > n){
        ll total = 0;
        for(int i = 1; i <= cnt; i ++){
            total += a[q[i]];
        }
        if(total == tb){
            for(int i = 1; i <= cnt; i ++) p[q[i]] = t;
            t ++;
        }
        p[n + 1] = 0;
        return;
    }
    for(int i = pos + 1; i <= n + 1; i ++){
        if(! p[i]) {
            q[++ cnt] = i;
            duyet(i);
            cnt --;
            if(p[pos]) {
                return;
            }
        }
    }
}

void solve(){
    tb = sum / k;
    duyet(0);
    for(int i = 1; i <= n; i ++){
        if(! p[i]) {
            cout << -1;
            exit(0);
        }
    }
    for(int i = 1; i <= n; i ++) cout << p[i] << " ";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        sum += a[i];
    }
    solve();
    return 0;
}