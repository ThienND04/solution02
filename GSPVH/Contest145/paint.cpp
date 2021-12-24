#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "paint"
#define maxn 501
#define inf 1000000007
#define mod 998244353

ll a1, a2, b1, b2;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> a1 >> a2 >> b1 >> b2;
    if(a1 > a2) swap(a1, a2);
    if(b1 > b2) swap(b1, b2);
    if(a1 > b1){
        swap(a1, b1);
        swap(a2, b2);
    }
    if(a2 >= b1 && a2 <= b2){
        cout << a2 - a1 + b2 - a2;
    }
    else if(a2 < b1) cout << a2 - a1 + b2 - b1;
    else cout << a2 - a1;
    return 0;
}