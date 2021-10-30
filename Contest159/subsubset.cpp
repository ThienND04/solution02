#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 2222
#define task "subsubset"
#define BLOCK_SIZE 100001

#define maxc 600

#define mod 998244353

// #define inf 1e18

#define inBlock(pos) ((pos - 1) / BLOCK_SIZE + 1)

#define reset(a) memset(a, 0, sizeof(a))

#define bit(x, i) ((x >> i) & 1)

int n, delta;
int c[maxn];

void sub(int& x, int y){
    x -= y;
    if(x < 0) x += mod;
}

int POW(int a, int b){
    int result = 1;
    for(int i = 1; i <= b; i ++) {
        result = (1ll * result * a) % mod;
    }
    return result;
}

void init(){
    cin >> n >> delta;
    for(int i = 0; i < n; i ++) cin >> c[i];

    if(delta == 0){
        int result = POW(2, n);
        sub(result, 1);
        cout << result;
        exit(0);
    }
}

/*
    Tuy nhiên, An và Bình còn đặt ra thêm các điều kiện sau đây:

    -Nếu An mua một ly trà xanh loại i, Bình chắc chắn cũng mua trà xanh loại này.
    Điều ngược lại có thể không đúng, nghĩa là có thể Bình mua trà xanh loại j nào đó nhưng An không mua.

    -Chênh lệch giữa tổng số tiền phải trả của An và Bình không quá δ.
*/

int solve(){
    int cnt = 0;
    for(int x = 1; x < (1 << n); x ++){
        int sum = 0;
        for(int i = 0; i < n; i ++) if(bit(x, i)) sum += c[i];
        for(int y = 1; y < (1 << n); y ++){
            bool ok = 1;
            int sum2 = 0;
            for(int i = 0; i < n; i ++){
                if(bit(x, i) && !bit(y, i)){
                    ok = 0;
                    break;
                }
                else if(bit(y, i)) sum2 += c[i];
            }
            if(ok){
                if(sum2 - sum <= delta) cnt ++;
            }
        }
    }
    return cnt;
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
    cout << solve();
    return 0;
}