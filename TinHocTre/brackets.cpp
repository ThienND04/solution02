#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "brakets"
#define maxn 1000001
#define maxk 10001
#define inf 1000000007
#define mod 1000000007

int n;
string s;
int pos[maxn], sz = 0;
int dp[maxk][maxk];
int id[maxn], ls[maxn], sls = 0;
int id2[maxn], ls2[maxn], sls2 = 0;

void Add(int& x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

pii calc(int l, int r){
    int minRes = 0, res = 0;
    for(int i = l; i <= r; i ++){
        if(s[i] == '('){
            res ++;
        }
        else res --;
        minRes = min(minRes, res);
    }
    return {res, minRes};
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n >> s;
    s = " " + s;
    pos[0] = 0;
    dp[0][1] = 1;
    for(int i = 1; i <= n; i ++){
        if(s[i] == '?') pos[++ sz] = i;
    }
    ls[sls = 1] = 0;
    id[0] = 1;
    for(int i = 0; i < sz; i ++){
        pii tmp = calc(pos[i] + 1, pos[i + 1] - 1);
        sls2 = 0;
        for(int k = 1; k <= sls; k ++){
            if(ls[k] + tmp.second < 0) continue;
            if(ls[k] + tmp.first - 1 >= 0 && ! id2[ls[k] + tmp.first - 1]) {
                sls2 ++;
                id2[ls[k] + tmp.first - 1] = sls2;
                ls2[sls2] = ls[k] + tmp.first - 1;
            }
            if(ls[k] + tmp.first - 1 >= 0) Add(dp[i + 1][id2[ls[k] + tmp.first - 1]], dp[i][k]);
            if(! id2[ls[k] + tmp.first + 1]){
                sls2 ++;
                id2[ls[k] + tmp.first + 1] = sls2;
                ls2[sls2] = ls[k] + tmp.first + 1;
            }
            Add(dp[i + 1][id2[ls[k] + tmp.first + 1]], dp[i][k]);
        }
        for(int i = 1; i <= sls; i ++){
            id[ls[i]] = 0;
        }
        sls = sls2;
        for(int i = 1; i <= sls2; i ++){
            id[ls2[i]] = i;
            ls[i] = ls2[i];
        }
        for(int i = 1; i <= sls2; i ++){
            id2[ls2[i]] = 0;
        }
        sls2 = 0;
    }
    pii tmp = calc(pos[sz] + 1, n);
    if(- tmp.first + tmp.second < 0 || ! id[- tmp.first]) cout << 0;
    else cout << dp[sz][id[- tmp.first]];
    return 0;
}