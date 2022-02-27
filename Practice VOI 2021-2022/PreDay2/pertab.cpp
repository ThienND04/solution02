#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "pertab"
#define inf 1e9
#define mod 1000000007
#define maxn 1001

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

int n, m;
int a[maxn][maxn], b[maxn][maxn];
string s;

namespace subtask1{
    void shiftRight(){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                b[i][j] = a[i][(j - 2 + n) % n + 1];
            }
        }
        for(int i = 1; i<=n; i ++) {
            for(int j = 1; j <= n; j ++){
                a[i][j] = b[i][j];
            }
        }
    }

    void shiftLeft(){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                b[i][j] = a[i][j % n + 1];
            }
        }
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= n; j ++){
                a[i][j] = b[i][j];
            }
        }
    }

    void shiftDown(){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                b[i][j] = a[(i - 2 + n) % n + 1][j];
            }
        }
        for(int i = 1; i<=n; i ++) {
            for(int j = 1; j <= n; j ++){
                a[i][j] = b[i][j];
            }
        }
    }

    void shiftUp(){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                b[i][j] = a[i % n + 1][j];
            }
        }
        for(int i = 1; i<=n; i ++) {
            for(int j = 1; j <= n; j ++){
                a[i][j] = b[i][j];
            }
        }
    }

    int tmp[maxn], hv[maxn];
    void hvdao(){
        for(int i = 1; i <= n; i ++){
            hv[tmp[i]] = i;
        }
    }

    void queryI(){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++) tmp[j] = a[i][j];
            hvdao();
            for(int j = 1; j <= n; j ++) a[i][j] = hv[j];
        }
    }

    void queryC(){
        for(int j = 1; j <= n; j ++){
            for(int i = 1; i <= n; i ++) tmp[i] = a[i][j];
            hvdao();
            for(int i = 1; i <= n; i ++) a[i][j] = hv[i];
        }
    }

    void subtask1(){
        for(char c: s){
            if(c == 'R') shiftRight();
            else if(c == 'L') shiftLeft();
            else if(c == 'D') shiftDown();
            else if(c == 'U') shiftUp();
            else if(c == 'I') queryI();
            else if(c == 'C') queryC();
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++) cout << a[i][j] << " ";
            cout << "\n";
        }
    }
}

void shiftRight(int num){
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            b[i][j] = a[i][(j - 1 - num + n) % n + 1];
        }
    }
    for(int i = 1; i<=n; i ++) {
        for(int j = 1; j <= n; j ++){
            a[i][j] = b[i][j];
        }
    }
}
void shiftLeft(int num){
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            b[i][j] = a[i][(j - 1 + num + n) % n + 1];
        }
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++){
            a[i][j] = b[i][j];
        }
    }
}

void shiftDown(int num){
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            b[i][j] = a[(i - 1 - num + n) % n + 1][j];
        }
    }
    for(int i = 1; i<=n; i ++) {
        for(int j = 1; j <= n; j ++){
            a[i][j] = b[i][j];
        }
    }
}
void shiftUp(int num){
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            b[i][j] = a[(i - 1 + num + n) % n + 1][j];
        }
    }
    for(int i = 1; i<=n; i ++) {
        for(int j = 1; j <= n; j ++){
            a[i][j] = b[i][j];
        }
    }
}

namespace subtask2{

    bool check(){
        for(char c: s){
            if(c != 'L' && c != 'R') return 0;
        }
        return 1;
    }

    void subtask2(){
        int cnt = 0;
        for(char c: s){
            cnt += (c == 'L' ? -1 : 1);
        }
        if(cnt < 0){
            cnt = -cnt;
            shiftLeft(cnt % n);
        }
        else if(cnt > 0){
            shiftRight(cnt % n);
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++) cout << a[i][j] << " ";
            cout << "\n";
        }
    }
}

namespace subtask3{
    bool check(){
        for(char c: s){
            if(c != 'D' && c != 'U') return 0;
        }
        return 1;
    }

    void subtask3(){
        int cnt = 0;
        for(char c: s) {
            cnt += (c == 'D' ? 1 : -1);
        }
        if(cnt < 0){
            cnt = - cnt;
            shiftUp(cnt % n);
        }
        else {
            shiftDown(cnt % n);
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++) cout << a[i][j] << " ";
            cout << "\n";
        }
    }
}

namespace subtask4{
    bool check(){
        for(char c: s){
            if(c == 'I' || c == 'C') return 0;
        }
        return 1;
    }

    void subtask4(){
        int cnt1 = 0, cnt2 = 0;
        for(char c: s) {
            if(c == 'L') cnt1 --;
            if(c == 'R') cnt1 ++;
            if(c == 'D') cnt2 ++;
            if(c == 'U') cnt2 --;
        }
        if(cnt1 < 0){
            cnt1 = - cnt1;
            shiftLeft(cnt1 % n);
        }
        else shiftRight(cnt1 % n);
        if(cnt2 < 0){
            cnt2 = -cnt2;
            shiftUp(cnt2 % n);
        }
        else shiftDown(cnt2 % n);

        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++) cout << a[i][j] << " ";
            cout << "\n";
        }
    }

}

namespace process{
    void process(){
        cin >> n >> m;
        for(int i = 1; i<= n; i ++) {
            for(int j = 1; j<= n; j ++) {
                cin >> a[i][j];
            }
        }
        cin >> s;
        if(m <= 10) return subtask1::subtask1();
        if(subtask2::check()) return subtask2::subtask2();
        if(subtask3::check()) return subtask3::subtask3();
        if(subtask4::check()) return subtask4::subtask4();
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
