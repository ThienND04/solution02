#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

#define reset(a) memset(a, 0, sizeof(a))
#define task "cay"
#define maxn 3000001
#define inf 1000000007
#define mod 998244353

void Add(int& x, int y){
    x += y;
    if(x >= mod) x -= mod;
}

int n;
int s[maxn];
vector<int> adj[maxn];
bool visited[maxn];
int cnt[maxn], total[maxn];

void DFS(int u){
    s[u] = 1;
    visited[u] = 1;
    for(int v: adj[u]){
        if(! visited[v]){
            DFS(v);
            s[u] += s[v];
        }
    }
}

bool check(int k){
    if(n % k != 0) return 0;
    return (total[n / k] == k);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n;
    for(int i = 2; i <= n; i ++) {
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    DFS(1);
    // for(int i = 1; i <= n; i ++) cerr << s[i] << " ";
    // cerr << endl;
    for(int i = 1; i <= n; i ++) cnt[s[i]] ++;
    // for(int i = 1; i <= n; i ++) cerr << cnt[i] << " ";
    for(int i = 1; i <= n; i ++){
        for(int j = i; j <= n; j += i) total[i] += cnt[j];
    }
    for(int i = 1; i <= n; i ++) {
        if(check(i)) cout << i << " ";
    }
    return 0;
}