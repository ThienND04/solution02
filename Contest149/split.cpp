#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "digits"
#define maxn 5001
#define inf 1e18
// #define mod 1000000007

const int mod = 998244353;

int n;
string s;
int dp[maxn][201];

void Add(int& x, int y){
    x += y;
    if(x > mod) x -= mod;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> s;
    n = s.size();
    s = " " + s;
    for(int i = 1; i <= n; i ++){
        
    }
    return 0;
}