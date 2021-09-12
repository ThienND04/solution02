#include<bits/stdc++.h>

using  namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define task "f"
#define maxn 1000001

ll x;
vector<ll> v;

string decToBin(ll a){
    string res = "";
    int t;
    while(a){
        t = a % 2;
        res = char(t + '0') + res;
        a /= 2;
    }
    return res;
}

ll binToDec(string s){
    ll res = 0;
    for(char c: s){
        res = res * 2 + c - '0';
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> x;
    string s = decToBin(x);

    for(int i = 0; i < s.size(); i ++){
        for(int j = 1; j <= s.size() - i; j ++){
            v.push_back(binToDec(s.substr(i, j)));
        }
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    ll res = 0;
    for(ll t: v) res += t;
    cout << res;
    return 0;
}