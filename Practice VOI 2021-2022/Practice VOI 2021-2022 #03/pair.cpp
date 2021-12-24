#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "pair"
#define inf 1e9
#define mod 1000000007
#define maxn 1000001

#define bit(x, i) ((x >> i) & 1)

// subtask 1

int numBoys, numGirls, k;
int boysHigh[maxn], girlsHight[maxn];

int result = inf;

void init(){
    cin >> numBoys >> numGirls >> k;
    for(int i = 1; i <= numBoys; i ++) cin >> boysHigh[i];
    for(int i = 1; i <= numGirls; i ++) cin >> girlsHight[i];
    sort(boysHigh + 1, boysHigh + numBoys + 1);
    sort(girlsHight + 1, girlsHight + numGirls + 1);
}

bool ok(int x){
    int j = 1;
    int cnt = 0;
    for(int i = 1; i <= numBoys; i ++){
        while(j <= numGirls && girlsHight[j] < boysHigh[i] - x){
            j ++;
        }
        if(j <= numGirls && abs(girlsHight[j] - boysHigh[i]) <= x){
            j ++;
            cnt ++;
        }
    }
    return cnt >= k;
}

void process(){
    int left = -1, right = inf;
    while(right - left > 1){
        int mid = (left + right) / 2;
        if(ok(mid)) right = mid;
        else left = mid;
    }
    cout << right;
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