#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "station"
#define maxn 200001
#define inf 1000000007
#define mod 1000000007

int n;
int h[maxn], st[maxn], sz = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n;
    int res = 0;
    for(int i = 1; i <= n; i ++) cin >> h[i];
    for(int i = 1; i <= n; i ++){
        while(sz && h[st[sz]] < h[i]){
            sz --;
            res ++;
        }
        if(sz) res ++;
        while(sz && h[st[sz]] <= h[i]) sz --;
        st[++ sz] = i;
    }
    cout << res;
    return 0;
}