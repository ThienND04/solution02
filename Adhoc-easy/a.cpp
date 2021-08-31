#include<bits/stdc++.h>

using  namespace std;

typedef long long ll;
#define task "a"
#define maxn 1000001

int t;
ll n;
int sl[maxn];
ll kt[maxn];

void init(){
    sl[1] = 1, kt[1] = 1;
    sl[2] = 2, kt[2] = 3;
    for(int i = 3; i < maxn; i ++){
        int k = lower_bound(kt + 1, kt + i, i) - kt;
        sl[i] = k;
        kt[i] = kt[i - 1] + k;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    init();
    cin >> t;
    while(t --){
        cin >> n;
        int k = lower_bound(kt + 1, kt + maxn, n) - kt;
        cout << k << "\n";
    }
    return 0;
}