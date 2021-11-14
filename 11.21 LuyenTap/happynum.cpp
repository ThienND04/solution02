#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "happynum"
#define inf 1000000000
#define mod 1000000007
#define maxn 101

void Add(int& x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

int m, k;
int nums[maxn], sd[maxn];
int f[51][8101];

int sumDigits(int n){
    int result = 0;
    while(n){
        result += n % 10;
        n /= 10;
    }
    return result;
}

int solve1(){
    int sum = 0;
    for(int i = 1; i <= m; i ++) sum += sd[i];
    if(sum % 2 == 1) return 0;
    sum >>= 1;
    f[0][0] = 1;
    int l = m / 2;
    for(int i = 1; i <= m; i ++){
        for(int j = l; j >= 1; j --){
            for(int s = sum; s >= sd[i]; s --){
                Add(f[j][s], f[j - 1][s - sd[i]]);
            }
        }
    }
    int result = 1;
    for(int i = 1; i <= l; i ++){
        result = (1ll * i * result) % mod;
    }
    result = (1ll * result * result) % mod;
    result = (1ll * result * f[l][sum]) % mod;
    return result;
}

// k - k / 2 + 1 --> k
int suffixSum(int n){
    int res = 0;
    for(int i = 1; i <= k / 2; i ++){
        res += n % 10;
        n /= 10;
    }
    return res;
}

int getMid(int n){
    if(k % 2 == 0) return 0;
    for(int i = 1; i <= k / 2; i ++) n /= 10;
    return n % 10;
}

int calc(int hib){
    reset(f);
    f[0][0] = 1;
    int sum = 0, l = m / 2;
    for(int i = 1; i <= m; i ++) sum += sd[i];
    sum -= getMid(nums[hib]);
    if(sum & 1)  return 0;
    sum >>= 1;
    for(int i = 1; i <= m; i ++){
        if(i == hib) continue;
        for(int j = l; j >= 1; j --){
            for(int s = sum; s >= sd[i]; s --){
                Add(f[j][s], f[j - 1][s - sd[i]]);
            }
        }
    }
    int result = 1;
    for(int i = 1; i <= l; i ++) result = (1ll * result * i) % mod;
    result = (1ll * result * result) % mod;
    int suff = suffixSum(nums[hib]);
    result = (1ll * result * f[l][sum - suff]) % mod;
    return result;
}

int solve2(){
    // assert(0);
    int result = 0;
    for(int i = 1; i <= m; i ++){
        Add(result, calc(i));
    }
    return result;
}

void process(){
    reset(f);
    cin >> m >> k;
    for(int i = 1; i <= m; i ++) cin >> nums[i];
    for(int i = 1; i <= m; i ++) sd[i] = sumDigits(nums[i]);
    if(m % 2 == 0){
        cout << solve1();
    }
    else cout << solve2();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    process();
    return 0;
}