#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "locphat"
#define maxn 220799
#define inf 1000000007
#define mod 998244353

string s, res[8];
int k, n;
vector<int> lucky = {0, 1, 6, 8};
bool f[maxn][7];
int pt[100000][8], tmp[9];
vector<int> sum;
pii trace[maxn][8];

void Try(int pos, int total = 0){
    if(pos > k){
        for(int i = 1; i <= k; i ++) pt[total][i] = tmp[i];
        sum.push_back(total);
        return;
    }
    for(int i = 0; i < 4; i ++) {
        tmp[pos] = lucky[i];
        Try(pos + 1, total + lucky[i]);
    }
}

void DP(){
    f[n + 1][0] = 1;
    for(int i = n; i >= 0; i --){
        for(int rem = 0; rem < 7; rem ++){
            if(f[i + 1][rem]){
                for(int t: sum){
                    if((t + rem) % 10 == s[i] - '0') {
                        f[i][(t + rem) / 10] = 1;
                        trace[i][(t + rem) / 10] = {rem, t};
                    }
                }
            }
        }
    }
}

void TruyVet(){
    if(! f[0][0]) {
        cout << -1;
        return;
    }
    int rem = trace[0][0].first;
    int total = trace[1][rem].second;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= k; j ++) res[j] += (pt[total][j] + '0');
        rem = trace[i][rem].first;
        total = trace[i + 1][rem].second;
    }
    for(int i = 1; i <= k; i ++){
        int j = 0;
        while(j < n && res[i][j] == '0') j ++;
        if(j == n) cout << "0\n";
        else{
            while(j < n) cout << res[i][j ++];
            cout << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    // k = 7;
    cin >> s >> k;
    n = s.size();
    s = "0" + s;
    Try(1);
    sort(sum.begin(), sum.end());
    sum.resize(unique(sum.begin(), sum.end()) - sum.begin());
    DP();
    TruyVet();
    return 0;
}