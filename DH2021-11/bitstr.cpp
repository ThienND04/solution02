#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "bitstr"
#define maxn 401
#define inf 1000000007
#define mod 1000000007

int n, k;
string s;
bool visited[maxn];
int res;

bool check(){
    int cnt = 1;
    for(int i = 1; i < n; i ++){
        int l = (s[i] - '0' + visited[i]) % 2;
        int r = (s[i + 1] - '0' + visited[i + 1]) % 2;
        if(l != r) cnt ++;
    }
    return (cnt <= k);
}

void duyet(int p){
    if(p > n){
        if(check()){
            int cnt = 0;
            for(int i = 1; i <= n; i ++) if(visited[i]) cnt ++;
            res = min(res, cnt);
        }
        if(res == 0) {
            return ;
        }
        return;
    }
    visited[p] = 1;
    for(int i = p + 1; i <= n + 1; i ++){
        duyet(i);
    }
    visited[p] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> k;
    cin >> s;
    s = " " + s;
    res = n;
    duyet(0);
    cout << res;
    return 0;
}