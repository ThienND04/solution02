#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "ex3"
#define maxn 1000001
#define inf 1000000007
#define mod 998244353

#define cd(c) (c == '('? ')': '(')

int n, q;
string s;

void init(){
    cin >> n >> q >> s;
    s = " " + s;
}

bool check(){
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(s[i] == '(') cnt ++;
        else{
            if(! cnt) return 0;
            cnt --;
        }
    }
    return cnt == 0;
}

void solve(){
    while(q --){
        int x;
        cin >> x;
        s[x] = cd(s[x]);
        for(int i = 1; i <= x; i ++){
            s[i] = cd(s[i]);
            if(check()) {
                cout << i << " ";
                break;
            }
            s[i] = cd(s[i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    init();
    // cerr << n << " " << q << ' ' << s;
    solve();
    return 0;
}