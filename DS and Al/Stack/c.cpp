#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "c"
#define maxn 50009
#define inf 1000000007

int n, d;
pii cow[maxn];
bool bl[maxn], br[maxn];

void calcLeft(){
    deque<int> q;
    for(int i = 1; i <= n; i ++){
        while(! q.empty() && cow[i].first - cow[q.front()].first > d) q.pop_front();
        while(! q.empty() && cow[i].second >= cow[q.back()].second) q.pop_back();
        bl[i] = (! q.empty() && cow[q.front()].second >= cow[i].second * 2);
        q.push_back(i);
    }
}

void calcRight(){
    deque<int> q;
    for(int i = n; i >= 1; i --){
        while(! q.empty() && cow[q.front()].first - cow[i].first > d) q.pop_front();
        while(! q.empty() && cow[i].second >= cow[q.back()].second) q.pop_back();
        br[i] = (!q.empty() && cow[q.front()].second >= cow[i].second * 2);
        q.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> d;
    for(int i = 1; i <= n; i ++) cin >> cow[i].first >> cow[i].second;
    sort(cow + 1, cow + n + 1);
    calcLeft();
    calcRight();
    int res = 0;
    for(int i = 1; i <= n; i ++) {
        if(bl[i] && br[i]) res ++;
    }
    cout << res;
}