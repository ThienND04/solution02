#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "ex6"
#define maxn 11
#define inf 1000000007
#define mod 998244353

int n, k;
string t;
string s;
int res = 0;

bool check(){
    int cnt = 0;
    for(int l = 0; l < n; l ++){
        for(int r = l; r < n; r ++){
            int length = r - l + 1;
            string s1 = s.substr(l, length);
            string s2 = t.substr(l, length);
            if(s1 > s2) cnt ++;
        }
    }
    return cnt == k;
}

void Try(int p){
    if(p == n){
        res += check();
        return;
    }
    for(int i = 'a'; i <= 'z'; i ++){
        s[p] = i;
        Try(p + 1);
    }
}

void subtask4(){
    int res = 1;
    for(int i = 1; i <= n; i ++){
        res = (1ll * res * 26) % mod;
    }
    cout << res;
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n >> k >> t;
    for(int i = 0; i < n; i ++) s += ' ';
    // cerr << 'z' - 'a' + 1;
    if(k == 0){
        subtask4();
    }
    else{
        Try(0);
        cout << res;
    }
    return 0;
}