#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "a"
#define inf 1e9
#define mod 1000000007
#define maxn 300001
#define delta 0.0000001

int t, n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j < i; j ++) cout << "()";
            for(int j = 0; j < n - i; j ++)  cout << "(";
            for(int j = 0; j < n - i; j ++) cout << ")";
            cout << "\n";
        }
    }
    return 0;
}