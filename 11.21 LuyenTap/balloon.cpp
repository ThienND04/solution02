#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "balloon"
#define inf 1000000000
#define mod 1000000007
#define maxn 201

int n;
string s;
int a[maxn];
char chrs[maxn];

int calc(){
    n = s.size();
    s = ' ' + s;
    int cnt = 0, m = 0;
    for(int i = 1; i <= n; i ++){
        if(s[i] != s[i - 1]){
            chrs[m] = s[i - 1];
            a[m ++] = cnt;
            cnt = 1;
        }
        else cnt ++;
    }
    chrs[m] = s[n];
    a[m] = cnt;
    n = m;
    for(int i = 1; i <= n; i ++) cerr << a[i] << " ";
    cerr << endl;
    for(int i = 1; i <= n; i ++) cerr << chrs[i] << " ";
    cerr << "\n---------------\n";
    return 0;
}

void process(){
    int t;
    cin >> t;
    while(t --){
        cin >> s;
        cout << calc() << "\n";
    }
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