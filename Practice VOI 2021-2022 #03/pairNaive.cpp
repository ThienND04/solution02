#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "pair"
#define inf 1e9
#define mod 1000000007
#define maxn 100

#define bit(x, i) ((x >> i) & 1)

// subtask 1

int numBoys, numGirls, k;
int boysHigh[maxn], girlsHight[maxn];
int tmp[2][maxn];
bool ok[2][maxn];

int result = inf;

void init(){
    cin >> numBoys >> numGirls >> k;
    for(int i = 1; i <= numBoys; i ++) cin >> boysHigh[i];
    for(int i = 1; i <= numGirls; i ++) cin >> girlsHight[i];
}

void calc(){
    int ans = 0;
    for(int i = 1; i <= k; i ++){
        ans = max(ans, abs(tmp[0][i] - tmp[1][i]));
    }
    result = min(result, ans);
}

void Try(int p, int n, int hight[], int id){    
    if(p == k + 1){
        if(id == 0){
            Try(1, numGirls, girlsHight, 1);
        }
        else{
            calc();
        }
        return ;
    }
    for(int i = 1; i <= n; i ++){
        if(! ok[id][i]){
            tmp[id][p] = hight[i];
            ok[id][i] = 1;
            Try(p + 1, n, hight, id);
            ok[id][i] = 0;
        }
    }
}

void process(){
    reset(ok);
    Try(1, numBoys, boysHigh, 0);
    cout << result;
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
    init();
    process();
    return 0;
}