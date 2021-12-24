#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "orga"
#define inf 1e9
#define mod 2021
#define maxn 5001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define ALPHABET 26

#define maxVal(s) (s.empty() ? 0 : *s.rbegin())

template<class T>
void maximize(T& x, T y){
    if(x < y) x = y;
}

int k, d, q;
int n[maxn], tmp[maxn];
pii lr[maxn];
queue<int> que;

void sub1(){
    ll res = 0;
    for(int i = 0; i <= q; i ++){
        res = 0;
        for(int j = lr[i].first; j <= lr[i].second; j ++) n[j] --;
        if(d == 1) {
            res = n[1] + n[2];
        }
        else if(d > 1){
            res = max(n[1], n[2]);
        }
        res += i;
        cout << res << "\n";
    }
}

void process(){
    cin >> k >> d >> q;
    lr[0] = {0, 0};
    tmp[k + 1] = 0;
    for(int i = 1; i <= k; i ++) cin >> n[i];
    for(int i = 1; i <= q; i ++) cin >> lr[i].first >> lr[i].second;

    if(k == 2 && q <= 100) return sub1();

    for(int t = 0; t <= q; t ++){
        ll s = 0;
        for(int j = lr[t].first; j <= lr[t].second; j ++){
            n[j] --;
        }
        for(int j = 1; j <= k; j ++) tmp[j] = n[j];
        while(1){
            sort(tmp + 1, tmp + k + 1);
            int p = upper_bound(tmp + 1, tmp + k + 1, 0) - tmp;
            int tr = tmp[p];
            if(p > k || tr == 0) break;
            for(int j = p; j <= min(k, p + d - 1); j ++){
                tmp[j] -= tr;
            }
            s += tr;
        }
        s += t;
        cout << s << "\n";
    }
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