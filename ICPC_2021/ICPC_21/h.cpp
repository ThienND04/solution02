#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "h"
#define inf 1000000000
#define mod 1000000007
#define maxn 100001

template<class T> 
void maximize(T& x, T y){
    if(y > x) x = y;
}

const int B = 311;

int Hash(const vector<int>& a){
    int res = 0;
    for(int i : a){
        res = (1ll * res * B + i) % mod;
    }
    return res;
}

const int maxT = 30;

int n, m, d;
map<int, bool> ok[maxT];
vector<int> trainingData, testData;

void process(){
    cin >> n >> m >> d;
    testData.resize(d);
    trainingData.resize(d);
    for(int i = 1; i <= n; i ++){
        int t;
        cin >> t;
        for(int j = 0; j < d; j ++){
            cin >> trainingData[j];
        }
        ok[t][Hash(trainingData)] = 1;
    }
    while(m --){
        int t;
        cin >> t;
        for(int j = 0; j < d; j ++) cin >> testData[j];
        int tmp = Hash(testData);
        if(ok[t][tmp]) cout << "BAD\n";
        else cout << "GOOD\n";
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