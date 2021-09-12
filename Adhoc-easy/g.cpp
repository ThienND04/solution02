#include<bits/stdc++.h>

using  namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "g"
#define maxn 100001

int n, k;
int p[maxn];
int cnt[maxn];
int a, b;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> p[i];
    cin >> a >> b;
    for(int i = 1; i <= n; i ++){
        int t = a / p[i] * p[i];
        if(t < a) t += p[i];
        while(t <= b){
            cnt[t - a] ++;
            t += p[i];
        }
    }
    int res = 0;
    for(int i = 0; i < b - a + 1; i ++) if(cnt[i] == k) res ++;
    cout << res;
    return 0;
}