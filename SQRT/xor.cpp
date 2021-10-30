#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 2000000
#define task "xor"
#define BLOCK_SIZE 330

#define inBlock(pos) ((pos - 1) / BLOCK_SIZE + 1)

#define reset(a) memset(a, 0, sizeof(a))


struct Query
{
    int left, right, id;
};

#define inBlock(pos) ((pos - 1) / BLOCK_SIZE + 1)

bool cmp(Query &q1, Query &q2)
{
    if (inBlock(q1.left) != inBlock(q2.left))
        return q1.left < q2.left;
    return q1.right < q2.right;
}

int n, numQueries, k;
int a[maxn], s[maxn];
int cnt[maxn];
ll result[maxn], ans = 0;
Query queries[maxn];

void Add(int num){
    ans += cnt[num ^ k];
    cnt[num] ++;
}

void Remove(int num){
    if((num ^ k) != num) ans -= cnt[num ^ k];
    else ans -= cnt[num] - 1;
    cnt[num] --;
}

void init(){
    cin >> n >> numQueries >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++) s[i] = s[i - 1] ^ a[i];
    for(int i = 1; i <= numQueries; i ++) {
        cin >> queries[i].left >> queries[i].right;
        queries[i].id = i;
    }
    sort(queries + 1, queries + numQueries + 1, cmp);
}

void solve(){
    // for(int i = 0; i <= n; i ++) cerr << i << " ";
    cerr << endl;
    // for(int i = 0; i <= n; i ++) cerr << s[i] << " ";
    cerr << endl;
    int curLeft = 0, curRight = -1;
    for(int i = 1; i <= numQueries; i ++){
        int left = queries[i].left, right = queries[i].right;
        while(curRight < right){
            // cerr << "Add: " << curRight + 1 << endl;
            Add(s[++ curRight]);
        }
        while(curLeft > left - 1){
            // cerr << "Add: " << curLeft - 1 << endl;
            Add(s[-- curLeft]);
        }
        while(curLeft < left - 1){
            // cerr << "Remove: " << curLeft << "\n";
            Remove(s[curLeft ++]);
        }
        while(curRight > right){
            // cerr << "Remove: " << curRight << endl;
            Remove(s[curRight --]);
        }
        // cerr << "--------------" << endl;
        result[queries[i].id] = ans;
    }
    for(int i = 1; i <= numQueries; i ++) cout << result[i] << "\n";
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