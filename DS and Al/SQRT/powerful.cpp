#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 1000001
#define task "powerful"
#define BLOCK_SIZE 330

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

int n, numQueries;
int a[maxn];
int cnt[maxn];
ll result[maxn];
ll ans = 0;
Query queries[maxn];

void Add(int num){
    if(!num) return; 
    ans -= 1ll * num * cnt[num] * cnt[num];
    cnt[num] ++;
    ans += 1ll * num * cnt[num] * cnt[num];
}

void Remove(int num){
    if(!num) return; 
    ans -= 1ll * num * cnt[num] * cnt[num];
    cnt[num] --;
    ans += 1ll * num * cnt[num] * cnt[num];
}

void init()
{
    cin >> n >> numQueries;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= numQueries; i++)
    {
        cin >> queries[i].left >> queries[i].right;
        queries[i].id = i;
    }
    sort(queries + 1, queries + numQueries + 1, cmp);
}

void solve(){
    int curLeft = 0, curRight = 0;
    for(int i = 1; i <= numQueries; i ++){
        int left = queries[i].left, right = queries[i].right;
        while(curLeft < left){
            Remove(a[curLeft ++]);
        }
        while(curRight < right){
            Add(a[++ curRight]);
        }
        while(curLeft > left){
            Add(a[-- curLeft]);
        }
        while(curRight > right){
            Remove(a[curRight --]);
        }
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