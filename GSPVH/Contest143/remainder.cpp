#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "remainder"
#define maxn 1000001
#define inf 1000000007
#define mod 1000000007

string a;
ll b;
unsigned long long r;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> a >> b;
    b = abs(b);
    for(char c: a){
        if(c == '-') continue;
        r = (r * 10 + c - '0') % b;
    }
    if(a[0] == '-') r = (b - r) % b;
    cout << r;
    return 0;
}