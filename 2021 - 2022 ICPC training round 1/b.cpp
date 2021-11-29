#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "b"
#define inf 1000000000
#define mod 1000000007
#define maxn 500001

int n;
int cost[maxn];
ll result = 0;

void process(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> cost[i];
    sort(cost + 1, cost + n + 1);
    int cnt = 0, tmp = 0;
    for(int i = n; i >= 1; i --){
        if(cnt) cnt --;
        else{
            tmp ++;
            result += cost[i];
        }
        if(i != 1 && cost[i] != cost[i - 1]) {
            cnt += tmp;
            tmp = 0;
        }
    }
    cout << result;
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