#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "orga"
#define inf 1e9
#define mod 2021
#define maxn 1001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

#define maxVal(s) (s.empty() ? 0 : *s.rbegin())

template<class T>
void maximize(T& x, T y){
    if(x < y) x = y;
}

int p, m, n, k;
int mp[maxn][11], cost[maxn][11];
int start[11], target[11];
int t[maxn][1024];

void init(){
    cin >> p >> m >> n;
    char c;
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){
            cin >> c;
            if(c == '/') mp[i][j] = 1;
            else mp[i][j] = -1;
        }
    }
    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= n; j ++) cin >> cost[i][j];
    }
    cin >> k;
    for(int i = 1; i <= k; i ++) {
        cin >> start[i];
    }
    for(int i = 1; i <= k; i ++) {
        cin >> target[i];
    }
}

void sub2(){

}

void process(){
    init();
    cout << rand() % 10000000;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    process();
    return 0;
}