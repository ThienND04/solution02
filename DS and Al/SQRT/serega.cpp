#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define maxn 100001
#define task "serega"
#define BLOCK_SIZE 660

#define reset(a) memset(a, 0, sizeof(a))

class Block{
public:
    int size, tot;
    int elements[BLOCK_SIZE + 1], cnt[maxn], values[BLOCK_SIZE + 1];

    Block(){
        size = tot = 0;
        reset(cnt);
    }

    void append(const int& val){
        cnt[val] ++;
        elements[++ size] = val;
        values[++ tot] = val;
    }

    void init(){
        for(int i = 1; i <= tot; i ++){
            cnt[values[i]] = 0;
        }
        tot = size = 0;
    }
};

int n, q, numBlocks;
int a[maxn];
Block bl[BLOCK_SIZE / 2];

void build(){
    numBlocks = 0;
    for(int i = 1; i <= n; i += BLOCK_SIZE / 2){
        numBlocks ++;
        for(int j = i; j <= min(n, i + BLOCK_SIZE / 2 - 1); j ++){
            bl[numBlocks].append(a[j]);
        }
    }
}

void rebuild(){
    n = 0;
    for(int i = 1; i <= numBlocks; i ++){
        for(int j = 1; j <= bl[i].size; j ++){
            a[++ n] = bl[i].elements[j];
        }
        bl[i].init();
    }
    build();
}

int erase(int pos){
    for(int i = 1, sum = 0; i <= numBlocks; i ++){
        sum += bl[i].size;
        if(pos <= sum){
            sum -= bl[i].size;
            pos -= sum;
            int ret = bl[i].elements[pos];
            for(int j = pos + 1; j <= bl[i].size; j ++){
                bl[i].elements[j - 1] = bl[i].elements[j];
            }
            bl[i].cnt[ret] --;
            bl[i].size --;
            return ret;
        }
    }
    return 0;
}

void insert(int pos, int value){
    for(int i = 1, sum = 0; i <= numBlocks; i ++){
        sum += bl[i].size;
        if(pos <= sum){
            sum -= bl[i].size;
            pos -= sum;
            bl[i].size ++;
            for(int j = bl[i].size; j > pos; j --){
                bl[i].elements[j] = bl[i].elements[j - 1];
            }
            bl[i].values[++ bl[i].tot] = value;
            bl[i].cnt[value] ++;
            bl[i].elements[pos + 1] = value;
            return; 
        }
    }
}

void shift(int left, int right){
    if(left == right) return;
    insert(left - 1, erase(right));
}

int count(int pos, int key){
    // count key from 1 --> pos
    if(pos <= 0) return 0;
    int result  = 0;
    for(int i = 1, sum = 0; i <= numBlocks; i ++){
        sum += bl[i].size;
        if(pos <= sum){
            sum -= bl[i].size;
            pos -= sum;
            for(int j = 1; j <= pos; j ++){
                if(bl[i].elements[j] == key) result ++;
            }
            break;
        }
        else result += bl[i].cnt[key];
    }
    return result;
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
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    build();
    cin >> q;
    int lastAns = 0;
    for(int i = 1; i <= q; i ++) {
        int type, left, right, key;
        cin >> type >> left >> right;
        left = (left + lastAns - 1) % n + 1;
        right = (right + lastAns - 1) % n + 1;
        if(left > right) swap(left, right);
        if(type == 1){
            shift(left, right);
        }
        else{
            cin >> key;
            key = (key + lastAns - 1) % n + 1;
            lastAns = count(right, key) - count(left - 1, key);
            cout << lastAns << "\n";
        }

        if(i % (BLOCK_SIZE / 2) == 0) {
            rebuild();
        }
    }
    return 0;
}