#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a))
#define task "sub"
#define mod 1000000007
#define inf 999999999
#define maxn 100009

int n;
int s[maxn], a[maxn], sl[maxn];

void update(int x, int v, int l){
    while(x <= n + 1){
        if(s[x] == v){
            sl[x] = (sl[x] + l) % mod;
        }
        else if(s[x] < v){
            s[x] = v;
            sl[x] = l;
        }
        x += x & -x;
    }
}

pii get(int x){
    int smax = 0, l = 0;
    while(x){
        if(smax == s[x]){
            l = (l + sl[x]) % mod;
        }
        else if(smax < s[x]){
            smax = s[x];
            l = sl[x];
        }
        x -= x & -x;
    }
    return {l, smax};
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;   
    for(int i = 1; i <= n; i ++) cin >> a[i];
    vector<int>v;
    v.assign(a + 1, a + n + 1);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 1; i <= n; i ++) {
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
    }
    a[n + 1] = n + 1;
    for(int i = 1; i <= n + 1; i ++){
        pii p = get(a[i] - 1);
        update(a[i], p.second + 1, p.first);
        update(a[i], 1, 1);
    }
    cout << get(n + 1).first;
    return 0;
}