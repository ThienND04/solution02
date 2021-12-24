#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "weather"
#define maxn 100009
#define inf 1000000007
#define mod 1000000007

void Add(int& x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

string s;
bool ok[100][100];
int dp[maxn], n;
string hh[] = {"NW", "WS", "SE", "EN"};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> s;
    for(int i = 0; i < 4; i ++) ok[hh[i][0]][hh[i][1]] = 1;
    n = s.size();
    s = " " + s;
    reset(dp);
    dp[0] = 1;
    for(int i = 1; i <= n; i ++){
        dp[i] += dp[i - 1];
        if(ok[s[i - 1]][s[i]]) Add(dp[i], dp[i - 2]);
    }
    cout << dp[n];
    return 0;
}