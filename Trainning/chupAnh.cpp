#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 1001
#define task "chupAnh"
#define inf 1000000000
#define bit(x, i) ((x >> i) & 1)

int n,k;
pii ed[maxn];

bool cmp(pii& a, pii& b){
    if(a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r",  stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= k; i ++){
        cin >> ed[i].first >> ed[i].second;
        if(ed[i].first > ed[i].second) swap(ed[i].first, ed[i].second);
    }
    sort(ed + 1, ed + k + 1, cmp);
    int pos = 0;
    int cnt = 0;
    for(int i = 1; i <= k; i ++){
        if(pos < ed[i].first){
            cnt ++;
            pos = ed[i].second - 1;
        }   
    }
    if(pos < n) cnt ++;
    cout << cnt;
    return 0;
}