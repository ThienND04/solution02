#include<bits/stdc++.h>

using  namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "c"
#define maxn 1001
#define mod 2020

string s;

int solve(){
    cin >> s;
    int res = 0, t = 1;
    for(int i = 1; i < s.size(); i ++) t = (t * i) % mod;
    int b = 1;
    for(int i = 0; i < s.size(); i ++){
        for(char c: s){
            res = (res + (c - '0') * t * b) % mod;
        }
        b = (b * 10) % mod;
    }   
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cout << solve();
    return 0;
}