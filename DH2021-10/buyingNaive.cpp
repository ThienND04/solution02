#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "buying"
#define maxn 1000001
#define bit(x, i) ((x >> i) & 1)
#define inf 1000000000000000

int n;
int x[maxn], y[maxn], z[maxn];
int l[maxn];
ll res = inf;

void calc(){
    int tb = 0, tc = 0;
    ll sum = 0;
    for(int i = 1; i <= n; i ++){
        if(l[i] == 1){
            sum += x[i];
        }
        else if(l[i] == 2){
            sum += y[i] - tb;
            tb ++;
        }
        else{
            sum += z[i] - tc;
            tc ++;
        }
    }
    res = min(res, sum);
}

void duyet(int pos){
    if(pos == n + 1){
        calc();
        return;
    }
    for(int i = 1; i <= 3; i ++){
        l[pos] = i;
        duyet(pos + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> x[i] >> y[i] >> z[i];
    duyet(1);
    cout << res;
    return 0;
}