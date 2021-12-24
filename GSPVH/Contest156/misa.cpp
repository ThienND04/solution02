#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 51
#define task "misa"

#define reset(a) memset(a, 0, sizeof(a))

int row, collum;
string mp[maxn];
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

void init(){
    cin >> row >> collum;
    for(int i = 1; i <= row; i ++){
        cin >> mp[i];
        mp[i] = " " + mp[i];
    }
}

void solve(){
    int result = 0, pvh = 0;
    for(int i = 1; i <= row; i ++){
        for(int j = 1; j <= collum; j ++){
            if(mp[i][j] == '.') continue;
            for(int p = 0; p < 8; p ++){
                if(i + dx[p] < 1 || i + dx[p] > row || j + dy[p] < 1 || j + dy[p] > collum) continue;
                if(mp[i + dx[p]][j + dy[p]] == 'o') result ++;
            }
        }
    }
    result /= 2;
    // cerr << result;
    for(int i = 1; i <= row; i ++){
        for(int j = 1; j <= collum; j ++){
            if(mp[i][j] == 'o') continue;
            int tmp = 0;
            for(int p = 0; p < 8; p ++){
                if(i + dx[p] < 1 || i + dx[p] > row || j + dy[p] < 1 || j + dy[p] > collum) continue;
                if(mp[i + dx[p]][j + dy[p]] == 'o') tmp ++;
            }
            pvh = max(pvh, tmp);
            // cerr << i << " " << j << ": " << tmp << endl;
        }
    }
    cout << result + pvh;
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
    solve();
    return 0;
}