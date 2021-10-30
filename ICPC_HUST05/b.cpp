#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "b"
#define inf 1e9
#define mod 1000000007
#define maxn 100001

#define bit(x, i) ((x >> i) & 1)

#define SIZE 500
#define IN_BLOCK(i) ((i - 1) / SIZE + 1)

struct Data
{
    int val, leftPos, rightPos, leftNeg, rightNeg;
    int left, right, glf, grt;
};


int n, m;
int a[maxn];
Data blocks[SIZE];

int sig(int t){
    int x = a[t + 1] - a[t];
    if(x == 0) return 0;
    return (x > 0 ? 1: -1);
}

Data init(int x){
    Data z;
    z.val = (x != 0);
    int t = sig(x);
    if(t == 0){
        z.leftPos = z.rightPos = 0;
        z.leftNeg = z.rightNeg = 0;
        z.glf = z.grt = 0;
    }
    else if(t == 1){
        z.leftPos = z.rightPos = 1;
        z.leftNeg = z.rightNeg = 0;
        z.glf = z.grt = 1;
    }
    else{
        z.leftPos = z.rightPos = 0;
        z.leftNeg = z.rightNeg = 1;
        z.glf = z.grt = -1;
    }
    z.left = z.right = x;
    return z;
}

Data sum(const Data& dt1, const Data& dt2){
    Data z;
    
    z.left = dt1.left;
    z.right = dt2.right;
    
    z.leftPos = dt1.leftPos;
    z.leftNeg = dt1.leftNeg;
    z.glf = dt1.glf;
    z.rightPos = dt2.rightPos;
    z.rightNeg = dt2.rightNeg;
    z.grt = dt2.grt;

    if(sig(dt1.right) == 0 || sig(dt2.left) == 0 || sig(dt1.right) < sig(dt2.left)){
        z.val = max(dt1.val, dt2.val);
    }
    else{
        int t1, t2;
        if(sig(dt1.right) == 1) t1 = dt1.rightPos;
        else t1 = dt1.rightPos + dt1.rightNeg;
        if(sig(dt2.left) == 1) t2 = dt2.leftPos + dt2.leftNeg;
        else t2 = dt2.leftNeg;
        z.val = max(dt1.val, dt2.val);
        z.val = max(z.val, t1 + t2);
        
        if(dt1.grt == 1){
            if(dt2.rightPos == dt2.right - dt2.left + 1) {
                z.rightPos = dt1.rightPos + t2;
                z.rightNeg = dt1.rightNeg;
            }
            else if(dt2.rightNeg == dt2.right - dt2.left + 1) {
                z.rightNeg = t2;
                z.rightPos = dt1.rightPos;
            }
        }
        else{
            if(dt2.rightPos == dt2.right - dt2.left + 1) {
                z.rightPos = t2;
                z.rightNeg = dt1.rightNeg;
            }
            else if(dt2.rightNeg == dt2.right - dt2.left + 1) {
                z.rightNeg = dt1.rightNeg + t2;
                z.rightPos = dt1.rightPos;
            }
        }

        if(dt2.grt == 1){
            if(dt1.leftPos == dt1.right - dt1.left + 1) {
                z.leftPos = t1 + dt2.leftPos;
                z.leftNeg = dt2.leftNeg;
            }
            else if(dt1.leftNeg == dt1.right - dt1.left + 1) {
                z.leftNeg = t1;
                z.leftPos = dt2.leftPos;
            }
        }
        else{
            if(dt1.leftPos == dt1.right - dt1.left + 1) {
                z.leftPos = t1;
                z.leftNeg = dt2.leftNeg;
            }
            else if(dt1.leftNeg == dt1.right - dt1.left + 1) {
                z.leftPos = dt2.leftPos;
                z.leftNeg = t1 + dt2.leftNeg;
            }
        }
    }
    return z;
}

void build(){
    for(int i = 1; i <= (n - 1) / SIZE + 1; i ++){
        blocks[i] = init((i - 1) * SIZE + 1);
        for(int j = (i - 1) * SIZE + 2; j <= min(n, i * SIZE); j ++){
            Data tmp = init(j);
            blocks[i] = sum(blocks[i], tmp);
        }
    }
}

int query(int p, int x){
    a[p] = x;
    for(int i = 1; i <= n; i ++) cerr << a[i] << " ";
    cerr << endl;
    int t = IN_BLOCK(p);
    blocks[t] = init((t - 1) * SIZE + 1);
    for(int i = (t - 1) * SIZE + 2; i <= min(n, t * SIZE); i ++){
        Data tmp = init(i);
        blocks[t] = sum(blocks[t], tmp);
    }
    Data total = blocks[1];
    for(int i = 2; i <= n / SIZE + 1; i ++){
        if((i - 1) * SIZE >= n) break;
        total = sum(total, blocks[i]);
    }
    return total.val + 1;
}

void process(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    build();
    while(m --){
        int p, x;
        cin >> p >> x;
        cout << query(p, x) << "\n";
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
    process();
    return 0;
}