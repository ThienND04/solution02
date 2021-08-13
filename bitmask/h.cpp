#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "h"
#define maxn 11
#define reset(arr) memset(arr, 0, sizeof(arr))
#define bit(x, i) ((x >> i) & 1)
#define inf 1000000007

int n, m;
int cnt = 0;
int f[100][9000]; // 3 ** 10
/* 
    1: /
    2: \
*/

vector<int> tp[9000];
vector<int> ke[9000];

bool check(vector<int> & vt){
    for(int i = 0; i < m - 1; i ++){
        if(vt[i] && vt[i + 1] && vt[i] != vt[i + 1]) return 0;
    }
    return 1;
}

bool check(vector<int> & a, vector<int> & b){ // a truoc b
    for(int i = 0; i < m; i ++){
        if(a[i] == 1){
            if(b[i] == 2) return 0;
            if(i != m - 1 && (a[i + 1] == 2 || b[i + 1] == 1)) return 0;
        }
        else if(a[i] == 2){
            if(b[i] == 1) return 0;
            if(i != 0 && b[i - 1] == 2) return 0;
            if(i != m - 1 && a[i + 1] == 1) return 0;
        }
    }
    return 1;
}

int count(vector<int> & a){
    int res = 0;
    for(int i = 0; i < m; i ++){
        if(a[i] != 0) res ++;
    }
    return res;
}

void update(vector<int> & a, int& sum){
    for(int i = 0; i < m; i ++){
        if(a[i] == 2){
            a[i] = 0;
            sum -= 2;
        }
        else {
            a[i] ++;
            sum ++;
            return;
        }
    }
}

void sol()
{
    if(n < m) swap(n, m);
    cnt = 0;
    reset(f);
    for(int i = 0; i < cnt; i ++) ke[i].clear();
    vector<int> tmp(m, 0);
    int sum = 0;
    while(1){
        if(check(tmp)){
            //tp[cnt].assign(tmp.begin(), tmp.end());
            tp[cnt] = tmp;
            f[0][cnt++] = count(tmp);
        }
        if(sum == 2 * m) break;
        update(tmp, sum);
    }
    for(int x = 0; x < cnt; x ++){
        for(int y = 0; y < cnt; y ++){
            if(check(tp[x], tp[y])){
                ke[x].push_back(y);
            }
        }
    }
    for(int i = 1; i < n; i ++){
        for(int x = 0; x < cnt; x ++){
            vector<int>x1 = tp[x];
            for(int y: ke[x]){
                f[i][x] = max(f[i][x], f[i - 1][y] + count(x1));
            }
        }
    }
    cout << *max_element(f[n - 1], f[n - 1] + cnt) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    while (cin >> n >> m)
        sol();
    return 0;
}
