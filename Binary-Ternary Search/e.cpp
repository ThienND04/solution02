#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "e"
#define maxn 1000001
#define reset(a) memset(a, 0, sizeof(a))

int n, k;
int c[maxn];
bool used[maxn];

bool check(int x){
    int cnt = 0;
    for(int i = 2; i <= 2 * n * k; i ++){
        if(i > 2 * cnt * k + 2) return 0;
        else if(c[i] - c[i - 1] <= x) {
            cnt ++;
            i ++;
        }
        if(cnt == n) return 1;
    }
    return (cnt == n);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= 2 * n * k; i ++){
        cin >> c[i];
    }
    sort(c + 1, c + 2 * n * k + 1);
    int l = -1, r = 2000000000;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l =  mid;
    }
    cout << r;
    return 0;
}