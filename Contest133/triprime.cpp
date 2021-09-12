#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "triprime"
#define inf 1e9
#define maxn 400001
#define delta 0.0000001

int n;
vector<int> t;

bool check(int x){
    if(t.size() == 3) return 0;
    for(int v: t){
        if(v == x) return 0;
    }
    t.push_back(x);
    return 1;
}

bool solve(){
    for(int i = 2; i <= sqrt(n); i ++){
        while(n % i == 0){
            if(! check(i)) return 0;
            n /= i;
        }
    }
    if(n != 1) {
        if(! check(n)) return 0;
    }
    return (t.size() == 3);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    if(solve()) cout << "YES";
    else cout << "NO";
    return 0;
}