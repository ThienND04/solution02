#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "e"
#define maxn 1000002
#define inf 1000000000007

int n;
int p[2 * maxn], d[2 * maxn], pos[2 * maxn], d2[2 * maxn], p2[2 * maxn];
ll a[2 * maxn], s[2 * maxn];
bool l[2 * maxn], r[2 * maxn];

void calc1(){
    deque<int> dq;
    for(int i = 1; i < 2 * n; i ++){
        while(! dq.empty() && dq.front() < i - n + 1) dq.pop_front();
        while(! dq.empty() && s[dq.back()] >= s[i]) dq.pop_back();
        dq.push_back(i);
        if(i - n + 1 < 1) continue;
        l[i - n + 1] = (s[i - n] <= s[dq.front()]);
    }
}

void calc2(){
    deque<int> dq;
    for(int i = 1; i < 2 * n; i ++){
        while(! dq.empty() && dq.front() < i - n + 1) dq.pop_front();
        while(! dq.empty() && s[dq.back()] >= s[i]) dq.pop_back();
        dq.push_back(i);
        if(i - n + 1 < 1) continue;
        r[pos[i - n + 1]] = (s[i - n] <= s[dq.front()]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> p[i] >> d[i];
        p[i + n] = p[i];
        d[i + n] = d[i];
    }
    for(int i = 1; i <= 2 * n; i ++){
        a[i] = p[i] - d[i];
        s[i] = s[i - 1] + a[i];
    }
    calc1();
    pos[1] = 1;
    for(int i = 2; i <= n; i ++) pos[i] = n + 2 - i;
    d2[1] = d2[n + 1] = d[n];
    p2[1] = p2[n + 1] = p[1];
    for(int i = 2; i <= n; i ++){
       d2[i] = d2[i + n] = d[pos[i] - 1];
       p2[i] = p2[i + n] = p[pos[i]];
    }
    for(int i = 1; i <= 2 * n; i ++){
        a[i] = p2[i] - d2[i];
        s[i] = s[i - 1] + a[i];
    }
    calc2();
    for(int i = 1; i <= n; i ++){
        // cerr << l[i] << " " << r[i] << "\n";
        if(l[i] || r[i]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}