 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "rotgame"
#define inf 1e9
#define mod 1000000007
#define maxn 101

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
#define LOG 30
#define ALPHABET 26

namespace caculate{
    template<class T>
    void add(T& x, T y){
        x += y;
        if(x >= mod) x -= mod;
    }
    template<class T>
    void sub(T& x, T y){
        x -= y;
        if(x < 0) x += mod;
    }
    template<class T>
    void maximize(T& x, T y){
        if(x < y) x = y;
    }
    template<class T>
    void minimize(T& x, T y){
        if(x > y) x = y;
    }
}

using namespace caculate;

namespace process{
    int n;
    int a[2][maxn];

    map<vector<vector<int>>, int> pre;

    // mp: vector 2x3
    // t = 0: turn left
    // t = 1: turn right
    // pos = 0 || pos = 1
    vector<vector<int>> rotation(vector<vector<int>> mp, const int& pos, const int& t){
        if(t == 0){
            int tmp = mp[0][pos];
            mp[0][pos] = mp[0][pos + 1];
            mp[0][pos + 1] = mp[1][pos + 1];
            mp[1][pos + 1] = mp[1][pos];
            mp[1][pos] = tmp;
        }
        else{
            int tmp = mp[0][pos];
            mp[0][pos] = mp[1][pos];
            mp[1][pos] = mp[1][pos + 1];
            mp[1][pos + 1] = mp[0][pos + 1];
            mp[0][pos + 1] = tmp;
        }
        return mp;
    }

    bool check(const vector<vector<int>>& mp, int up, int down){
        for(int j = 0; j < 3; j ++){
            if(mp[0][j] == 5 || mp[0][j] == 6 || mp[0][j] == up) return 0;
            if(mp[1][j] == 3 || mp[1][j] == 4 || mp[1][j] == down) return 0;
        }
        return 1;
    }

    string turn[3];
    int big[2][maxn];

    void BFS(int row, int up, int down){
        // BFS tren 2x3
        pre.clear();
        vector<vector<int> > start = {{0, 0, 0}, {0, 0, 0}};
        start[0][row] = up; start[1][row] = down;
        for(int i = 0, cnt = 3; i < 2; i ++){
            for(int j = 0; j < 3; j ++){
                if(j != row) start[i][j] = cnt ++;
            }
        }
        queue<vector<vector<int>>>q;
        q.push(start);
        pre[start] = -1;
        while(! q.empty()){
            vector<vector<int>> u = q.front();
            q.pop();
            for(int j = 0; j < 2; j ++){
                vector<vector<int>> v = rotation(u, j, 0);
                if(pre.find(v) == pre.end()){
                    pre[v] = j;
                    if(check(v, up, down)){
                        while(pre[v] != -1){
                            turn[row] += char(pre[v] + '0');
                            v = rotation(v, pre[v], 1);
                        }
                        return;
                    }
                    q.push(v);
                }
            }
        }
    }

    void rotation(int (*mp)[101], const int& pos, const int& t){
        if(t == 0){
            int tmp = mp[0][pos];
            mp[0][pos] = mp[0][pos + 1];
            mp[0][pos + 1] = mp[1][pos + 1];
            mp[1][pos + 1] = mp[1][pos];
            mp[1][pos] = tmp;
        }
        else{
            int tmp = mp[0][pos];
            mp[0][pos] = mp[1][pos];
            mp[1][pos] = mp[1][pos + 1];
            mp[1][pos + 1] = mp[0][pos + 1];
            mp[0][pos + 1] = tmp;
        }
    }

    void init(){
        cin >> n;
        for(int i = 1; i <= n; i ++) cin >> a[0][i];
        for(int i = 1; i <= n; i ++) cin >> a[1][i];
        for(int i = 0; i < 3; i ++) {
            turn[i] = "";
            BFS(i, 1, 2);
            reverse(turn[i].begin(), turn[i].end());
            // cerr << turn[i] << "\n";
        }
        vector<int> v;
        for(int i = 0; i < 2; i ++){
            for(int j = 1; j <= n; j ++){
                v.push_back(a[i][j]);
            }
        }
        sort(v.begin(), v.end());
        int tmp = v[n];
        // cerr << tmp << "\n";
        for(int i = 0; i < 2; i ++){
            for(int j = 1; j <= n; j ++){
                big[i][j] = (a[i][j] >= tmp);
            }
        }
    }

    pii Found(){
        pii res = {-1, -1};
        for(int i = 1; i <= n; i ++){
            if(! big[0][i] && res.first == -1) res.first = i;
            if(big[1][i] && res.second == -1) res.second = i;
        }
        return res;
    }

    void process(){
        init();
        if(n == 2){
            int res = a[0][1] + a[0][2];
            int numTurn = 0;
            for(int i = 1; i < 4; i ++){
                rotation(a, 1, 0);
                if(res < a[0][1] + a[0][2]) {
                    res = a[0][1] + a[0][2];
                    numTurn = i;
                }
            }
            cout << numTurn << "\n";
            for(int i = 0; i < numTurn; i ++) cout << 1 << " ";
        }
        else{
            vector<int> res;
            // for(int i = 0; i < 2; i ++){
            //     for(int j = 1; j <= n; j ++) cerr << big[i][j] << " ";
            //     cerr << "\n";
            // }
            while(1){
                pii f = Found();
                if(f.first == -1) break;
                if(f.first == f.second){
                    if(f.first == 1){
                        for(char c: turn[0]){
                            res.push_back(c - '0' + 1);
                            rotation(big, c - '0' + 1, 0);
                        }
                    }
                    else if(f.first == n){
                        for(char c: turn[2]){
                            res.push_back(c - '0' + n - 2);
                            rotation(big, c - '0' + n - 2, 0);
                        }
                    }
                    else{
                        for(char c: turn[1]){
                            res.push_back(c - '0' + f.first - 1);
                            rotation(big, c - '0' + f.first - 1, 0);
                        }
                    }
                }
                else if(f.first < f.second){
                    for(int i = f.first; i < f.second; i ++){
                        res.push_back(i);
                        rotation(big, i, 0);
                    }
                }
                else{
                    for(int i = f.second; i < f.first; i ++){
                        res.push_back(i);
                        res.push_back(i);
                        res.push_back(i);
                        rotation(big, i, 1);
                    }
                }
            }
            cout << res.size() << "\n";
            for(int c: res) cout << c << " ";
        }
    }
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
    process::process();
    return 0;
}
