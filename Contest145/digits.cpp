#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "digits"
#define maxn 1000000
#define inf 1000000007
#define mod 998244353

int q;
ll p, r;
int no0 = 0;
ll ght = 1;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> p >> q >> r;
    if(p == 0){
        if(r == 1) {
            cout << 0;
            exit(0);
        }
        p += q;
        r --;
    }
    while(ght <= p) {
        ght *= 10;
        no0 ++;
    }
    while(r){
        ll so = (ght - p - 1) / q + 1;
        if(so * no0 >= r){
            p = p + (r / no0 - 1) * q;
            if(r % no0 != 0) {
                r %= no0;
                p += q;
            }
            else r = no0;
            break;
        }
        r -= so * no0;
        no0 ++;
        p += so * q;
        ght *= 10;
    }
    stringstream ss;
    ss << p;
    string s;
    ss >> s;
    for(int i = 0; i < r; i ++) cout << s[i];
    return 0;
}