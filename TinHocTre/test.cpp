#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "bitstr"
#define maxn 200001
#define inf 1000000007
#define mod 1000000007

int n;
string l = "hello";

bool check(string& s){
    int t = 0;
    for(char c: s){
        if(c == l[t]) t ++;
        if(t == 5) return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")) { freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout); }
    cin >> n;
    while(n --){
        string s;
        cin >> s;
        if(check(s)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}