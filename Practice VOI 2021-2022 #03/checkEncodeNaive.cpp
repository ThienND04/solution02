#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "checkEncode"
#define inf 1e9
#define mod 1000000007
#define maxn 100

#define bit(x, i) ((x >> i) & 1)

#define MAX_RESULT 3

// subtask 1
int n;
string s[maxn];
string result = "Linzzzzzzzzzzzzzzzzz";
map<string, bool> ok;

void Try(string tmp){
    if(tmp.size() > MAX_RESULT){
        return ;
    }
    if(ok[tmp]){
        if(result.size() > tmp.size()){
            result = tmp;
        }
        else if(tmp.size() == result.size() && tmp < result)  result = tmp;
        return ;
    }
    ok[tmp] = 1;
    for(int i = 1; i <= n; i ++){
        Try(tmp + s[i]);
    }
}

void init(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> s[i];
    }
}

void process(){
    Try("");
    if(result != "Linzzzzzzzzzzzzzzzzz"){
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