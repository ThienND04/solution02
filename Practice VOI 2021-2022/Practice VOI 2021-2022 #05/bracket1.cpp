#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "bracket"
#define inf 1e9
#define mod 2021
#define maxn 30

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

#define maxVal(s) (s.empty() ? 0 : *s.rbegin())

template<class T>
void maximize(T& x, T y){
    if(x < y) x = y;
}

int n;
int a[maxn];
int state[maxn];

ll res = 0;

void calc(){
    ll s = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i ++){
        if(state[i] == 1) {
            cnt ++;
            s += a[i];
        }
        else if(state[i] == -1){
            cnt --;
            if(cnt < 0) return;
            s -= a[i];
        }
    }
    if(cnt) return;
    maximize(res, s);
    // if(res == s){
    //     for(int i = 1; i <= n; i ++ ) cerr << state[i] << " ";
    //     cerr << "\n";
    // }
}

void Try(int pos){
    if(pos > n){
        calc();
        return ;
    }
    for(int i = -1; i <= 1; i ++){
        state[pos] = i;
        Try(pos + 1);
    }
}

void process(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    Try(1);
    cout << res;
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