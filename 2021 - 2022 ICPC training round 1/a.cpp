#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "a"
#define inf 1000000000
#define mod 1000000007
#define maxn 500001

string s;
int n;
int cnt[27];

bool ok(int x){
    int tmp = 0;
    for(int i = 0; i <= 26; i ++){
        if(cnt[i]){
            tmp += (cnt[i] - 1) / x + 1;
        }
    }
    return (tmp <= n);
}

void process(){
    cin >> s >> n;
    reset(cnt);
    int tmp = 0;
    for(char c: s){ 
        if(cnt[c - 'a'] == 0) tmp ++;
        cnt[c - 'a'] += 1;
    }
    if(tmp > n) {
        cout << -1;
        return ;
    }
    int l = 0, r = s.size() + 1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(ok(mid)) r = mid;
        else l = mid;
    }
    cout << r << "\n";
    string result = "";
    for(int i = 0; i <= 26; i ++){
        if(cnt[i]){
            int tmp = (cnt[i] - 1) / r + 1;
            for(int j = 1; j <= tmp; j ++) result += char(i + 'a');
        }
    }
    while(result.size() < n) result += 'l';
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