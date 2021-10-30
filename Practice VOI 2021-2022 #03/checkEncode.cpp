#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "checkEncode"
#define inf 1e9
#define mod 1000000007
#define maxn 10000

#define bit(x, i) ((x >> i) & 1)

#define MAX_RESULT 10

// subtask 1
int n;
string s[maxn];
string result = "Linzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
map<string, bool> ok;
int cnt[maxn];

void Try(string tmp){
    if(ok[tmp]){
        if(result.size() > tmp.size()){
            result = tmp;
        }
        else if(tmp.size() == result.size() && tmp < result)  result = tmp;
        return ;
    }
    ok[tmp] = 1;
    for(int i = 1; i <= n; i ++){
        if(cnt[i] < 2) {
            cnt[i] ++;
            Try(tmp + s[i]);
            cnt[i] --;
        }
    }
}

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> s[i];
    }
}

void process(){
    if(n > 10) {
        cout << -1;
        return;
    }
    Try("");
    if(result != "Linzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"){
        cout << result;
    } 
    else cout << -1;
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