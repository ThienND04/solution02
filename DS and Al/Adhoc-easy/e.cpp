#include<bits/stdc++.h>

using  namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "e"
#define maxn 1000001

int n;
ll s = 0;
int arr[32], uoc[32], sz = 0;

void init(int a){
    for(int i  = 2; i <= sqrt(a); i ++){
        if(a % i == 0){
            while(a % i == 0) a /= i;
            uoc[++ sz] = i;
        }
    }
    if(a > 1) uoc[++ sz] = a;
}

void duyet(int p, int m){
    if(p > sz){
        if(m <= 1) return;
        int t = 1;
        for(int i = 2; i <= m; i ++){
            t *= arr[i];
        }
        if(m % 2 == 1) s -= n / t;
        else s += n / t;
        return;
    }
    arr[++ m] = uoc[p];
    for(int i = p + 1; i <= sz + 1; i ++){
        duyet(i, m);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    init(n);
    duyet(0, 0);
    cout << n - s;
    return 0;
}