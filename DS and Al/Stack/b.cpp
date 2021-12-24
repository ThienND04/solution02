#include<iostream>

using namespace std;

typedef long long ll;
#define task "b"
#define maxn 1000009
#define inf 1000000007

int n;
int h[maxn], front[maxn], back[maxn], st[maxn], sz = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> h[i];
    h[0] = h[n + 1] = inf;
    st[++ sz] = 0;
    for(int i = 1; i <= n; i ++){
        while(h[st[sz]] <= h[i]) sz --;
        front[i] = st[sz];
        st[++ sz] = i;
    }
    st[(sz = 1)] = 0;
    for(int i = n; i > 0; i --){
        while(h[st[sz]] < h[i]) sz --;
        back[i] = st[sz];
        st[++ sz] = i;
    }
    ll res = 0;
    for(int i = 1; i<= n; i ++) {
        if(front[i] || back[i]) res += min(h[front[i]], h[back[i]]);
    }
    cout << res;
    return 0;
}