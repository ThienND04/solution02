#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "g"
#define maxn 5001
#define maxk 19
#define bit(x, i) ((x >> i) & 1)
#define reset(arr) memset(arr, -1, sizeof(arr))
#define inf 1000000007

int n, bonus = 0;
int b[maxn], f[1 << maxk];
vector<int> nt, a;
int snt[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
vector<int> gr[maxn], nogr;
bool prime[maxn];

bool isPrime(int x)
{
    if (x < 2)
        return 0;
    else if (x > 2)
    {
        if (x % 2 == 0)
            return 0;
        for (int i = 3; i <= sqrt(x); i++)
        {
            if (x % i == 0)
                return 0;
        }
    }
    return 1;
}

void callB(int x, int v){
    for(int i = 0; i < maxk; i ++){
        if(v % snt[i] == 0) b[x] |= 1 << i;
    }
}

void fact(int x){
    for(int i = 0; i < a.size(); i ++){
        if(a[i] % x == 0) {
            gr[x].push_back(a[i]);
            callB(a[i], a[i] / x);
            a.erase(a.begin() + i--);
        }
    }
}

void init()
{
    cin >> n;
    for (int i = 0; i < maxn; i++)
    {
        prime[i] = isPrime(i);
    }
    for (int i = 71; i < maxn; i++)
    {
        if (prime[i])
            nt.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++){
        for(int j = i + 1; j < a.size(); j++){
            if(a[j] % a[i] == 0){
                a.erase(a.begin() + j--);
            }
        }
        if(prime[a[i]] || a[i] == 1) {
            bonus ++;
            a.erase(a.begin() + i--);
        }
    }
    for(int i: nt) fact(i);
    for(int i: a) callB(i, i);
}

void solve()
{
    reset(f);
    f[0] = 0;
    for(int k: nt) {
        if(gr[k].empty()) continue;
        for(int x = (1 << maxk) - 1; x >= 0; x --){
            if(f[x] == -1) continue;
            for(int i: gr[k]){
                if(x & b[i])  continue;
                f[x | b[i]] = max(f[x | b[i]], f[x] + 1);
            }
        }
    }
    for(int x = 0; x < 1 << maxk; x ++){
        if(f[x] == -1) continue;
        for(int i: a){
            if(x & b[i])  continue;
            f[x | b[i]] = max(f[x | b[i]], f[x] + 1);
        }
    }
    cout << *max_element(f, f + (1 << maxk)) + bonus;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    init();
    solve();
    return 0;
}
