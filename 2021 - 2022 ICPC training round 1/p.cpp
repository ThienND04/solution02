#include <bits/stdc++.h>
using namespace std;

#define ALL(i_) i_.begin(), i_.end()
#define PB push_back
#define TASK "P"

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int oo = 1000000099;
const int mod = 1000000007;
const int maxn = 100011;

int numNode;
int mark[(1 << 20) + 11];

void Try(int u){
    if(mark[u]) return;
    mark[u] = 1;
    Try(u / 2);
    Try(u / 2 + numNode / 2);
    cout << u << " ";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }
    cin >> numNode;
    if(numNode & 1) return cout << -1, 0;
    cout << "0 ";
    Try(0);
    return 0;
}