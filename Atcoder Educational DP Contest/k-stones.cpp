#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "k-stones"
#define maxn 101
#define inf 1000000007
#define mod 1000000007

int n, k;
int a[maxn];
bool dp[100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n >> k;
    for(int i  = 1; i <= n; i ++){
        cin >> a[i];
    }
    dp[0] = 0;
    for(int i = 1; i <= k; i ++ ) {
        for(int j = 1; j <= n; j ++){
            if(i >= a[j] && ! dp[i - a[j]]){
                dp[i] = 1;
            }
        }
    }
    if(dp[k]) cout << "First";
    else cout << "Second";
    return 0;
}