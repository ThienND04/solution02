#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "n"
#define inf 1000000000
#define mod 1000000007
#define maxn 100001

template<class T> 
void maximize(T& x, T y){
    if(y > x) x = y;
}

void process(){
    int l = 0, r = inf + 1;
    int left, top;
    int d, h;
    ll s;
    cout << "? " << 0 << " " << 0 << " " << inf << " " << inf << "\n";
    cerr << "? " << 0 << " " << 0 << " " << inf << " " << inf << "\n";
    cin >> s;
    while(r - l > 1){
        int mid = (l + r) / 2;
        cout << "? " << l << " " << 0 << " " << inf << " " << inf << "\n";
        ll tmp;
        cin >> tmp;
        if(tmp == s){
            l = mid;
        }
        else r = mid;
    }
    left = l;
    cout << "? " << left << " " << 0 << " " << l << " " << inf << "\n";
    cin >> d;
    l = 0, r = inf + 1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        cout << "? " << left << " " << l << " " << inf << " " << inf << "\n";
        ll tmp;
        cin >> tmp;
        if(tmp == s){
            l = mid;
        }
        else r = mid;
    }
    top = l;
    cout << "? " << 0 << " " << top << " " << inf << " " << top << "\n";
    cin >> h;
    cout << "! " << left << " " << top << " " << left + d - 1 << " " << top + h - 1;
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