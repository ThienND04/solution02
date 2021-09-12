#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "digits"
#define inf 1e9
#define maxn 10
#define delta 0.0000001

bool check[maxn], check2[maxn];

bool isFriend(string& x, string& y){
    reset(check);
    reset(check2);
    for(char c: x){
        check[c - '0'] = 1;
    }
    for(char c: y){
        check2[c - '0'] = 1;
    }
    for(int i = 0; i < 10; i ++) {
        if(check[i] != check2[i]) return 0;
    }
    return 1;
}   

bool isAlmostFriend(string x, string y){
    int n = x.size();
    for(int i = 0; i < n - 1; i ++){
        if(x[i] < '9' && x[i + 1] > '0'){
            x[i] ++;
            x[i + 1] --;
            if(isFriend(x, y)) return 1;
            x[i] --;
            x[i + 1] ++;
        }
        if(x[i] > '0' && x[i + 1] < '9'){
            if(x[i] == '1' && i == 0) continue;
            x[i] --;
            x[i + 1] ++;
            if(isFriend(x, y)) return 1;
            x[i] ++;
            x[i + 1] --;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string x, y;
    cin >> x >> y;
    if(isFriend(x, y)){
        cout << "friends";
    }
    else if(isAlmostFriend(x, y) || isAlmostFriend(y, x)) {
        cout << "almost friends";
    }
    else cout << "nothing";
    return 0;
}