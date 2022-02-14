#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "palin"
#define inf 1e9
#define mod 1000000007
#define maxn 10001

#define maxbit 1024

#define bit(x, i) ((x >> i) & 1)
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

string s;
int n, k, L[14];

bool checkPalin(int l, int r){
    while(l < r){
        if(s[l] != s[r]) return 0;
        l ++;
        r --;
    }
    return 1;
}

namespace subtask1{

    void subtask1(){
        for(int i = L[1]; i <= n; i ++){
            if(checkPalin(i - L[1] + 1, i)) {
                //cerr << i;
                cout << L[1];
                return;
            }
        }
        cout << -1;
    }
}

namespace subtask2{
    int calc(){
        int pos = -1;
        int res = -1;

        for(int i = 1; i <= n; i ++){
            int l = i - L[2] + 1;
            int l1 = l - 1;
            if(l1 >= L[1] && checkPalin(l1 - L[1] + 1, l1)) pos = l1 - L[1] + 1;

            if(pos != -1 && checkPalin(l, i)) {
                //cerr << i << " " << pos << "\n";
                if(res == -1) res = i - pos + 1;
                else minimize(res, i - pos + 1);
            }
        }
        return res;
    }

    void subtask2(){
        int tmp1 = calc();
        swap(L[1], L[2]);
        int tmp2 = calc();

        if(tmp1 == -1) cout << tmp2;
        else if(tmp2 == -1) cout << tmp1;
        else cout << min(tmp1, tmp2);
    }
}

namespace subtask3{
    bool IsPalin[maxn][maxn];

    void init(){
        reset(IsPalin);
        IsPalin[1][1] = 1;
        for(int i = 2; i <= n; i ++){
            IsPalin[i][i] = 1;
            for(int j = 1; j <= i - 1; j ++){
                if(s[i] != s[j]) continue;
                if(j + 1 > i - 1) IsPalin[j][i] = 1;
                else if(IsPalin[j + 1][i - 1]) IsPalin[j][i] = 1;
            }
        }
    }

    int pos[maxn][1 << 13];

    void subtask3(){
        init();
        reset(pos);

        for(int i = 1; i <= n; i ++){
            for(int x = 0; x < (1 << k); x ++) pos[i][x] = pos[i - 1][x];

            for(int j = 1; j <= k; j ++){
                if(i < L[j]) continue;
                int l = i - L[j] + 1;

                if(! IsPalin[l][i]) continue;

                for(int x = 0; x < (1 << k); x ++){
                    if(x == 0) {
                        maximize(pos[i][1 << (j - 1)], l);
                    }

                    if(pos[l - 1][x] == 0 || ((1 << (j - 1)) & x) != 0) continue;
                    maximize(pos[i][(1 << (j - 1)) | x], pos[l - 1][x]);
                }
            }
        }

        int res = -1;
        for(int i = 1; i <= n; i ++){
            if(pos[i][(1 << k) - 1]){
                if(res == -1) res = i - pos[i][(1 << k) - 1] + 1;
                else minimize(res, i - pos[i][(1 << k) - 1] + 1);
            }
        }
        cout << res;
    }
}

namespace process{
    void process(){
        cin >> s;
        n = s.size();
        s = " " + s;
        cin >> k;
        for(int i = 1; i <= k; i ++) cin >> L[i];

        if(k == 1) return subtask1::subtask1();
        else if(k == 2) return subtask2::subtask2();
        else return subtask3::subtask3();
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
