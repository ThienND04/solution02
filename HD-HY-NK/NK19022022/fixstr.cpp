 
#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "fixstr"
#define inf 1e9
#define mod 1000000007
#define maxn 1000001

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

struct Query{
    char type;
    int id, i, j;
};

struct Node{
    int pos = -1;
    vector<int> child;
    vector<Query> queries;
};

string s;
int n, m;
Query qr[maxn];

namespace process{
    int id[maxn], result[maxn];
    Node nodes[maxn];
    int num = 0;
    int minSum[4 * maxn], sum[4 * maxn];

    void build(int node, int l, int r){
        if(l == r){
            sum[node] = (s[l] == ')' ? -1 : 1);
            minSum[node] = min(sum[node], 0);
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2 + 1, l, mid);
        build(node * 2 + 2, mid + 1, r);
        sum[node] = sum[node * 2 + 1] + sum[node * 2 + 2];
        minSum[node] = min(minSum[node * 2 + 1], minSum[node * 2 + 2] + sum[node * 2 + 1]);
    }

    void update(int node, int l, int r, int u){
        if(u < l || u > r) return;
        if(l == r){
            s[l] = (s[l] == '(' ? ')' : '(');
            sum[node] = (s[l] == ')' ? -1 : 1);
            minSum[node] = min(sum[node], 0);
            return;
        }
        int mid = (l + r) / 2;
        update(node * 2 + 1, l, mid, u);
        update(node * 2 + 2, mid + 1, r, u);
        sum[node] = sum[node * 2 + 1] + sum[node * 2 + 2];
        minSum[node] = min(minSum[node * 2 + 1], minSum[node * 2 + 2] + sum[node * 2 + 1]);
    }

    pii getMinSum(int node, int l, int r, int u, int v){
        if(l > v || r < u) return {inf, 0};
        if(u <= l && r <= v) return {minSum[node], sum[node]};
        int mid = (l + r) / 2;
        pii tmp1 = getMinSum(node * 2 + 1, l, mid, u, v);
        int res1 = tmp1.first;
        pii tmp2 = getMinSum(node * 2 + 2, mid + 1, r, u, v);
        int res2 = tmp2.first + tmp1.second;
        return {min(res1, res2), tmp1.second + tmp2.second};
    }

    void init(){
        int curNode = 0;
        for(int i = 1; i <= m; i ++){
            if(qr[i].type == 'C'){
                ++ num;
                nodes[num].pos = qr[i].i;
                nodes[curNode].child.push_back(num);
                curNode = num;
            }
            else if(qr[i].type == 'U'){
                curNode = id[qr[i].i - 1];
            }
            id[i] = curNode;
            if(qr[i].type == 'Q') nodes[curNode].queries.push_back(qr[i]);
        }
    }

    bool visited[maxn];

    void DFS(int u){
        visited[u] = 1;
        //cerr << u << " : " << s << "\n";
        for(Query curQr: nodes[u].queries){
            //cerr << s << "\n";
            pii tmp = getMinSum(1, 1, n, curQr.i, curQr.j);
            int ms = tmp.first, sm = tmp.second;
            result[curQr.id] = -ms + abs(sm - ms);
        }
        for(int v: nodes[u].child){
            if(visited[v]) continue;
            if(nodes[v].pos != -1){
                update(1, 1, n, nodes[v].pos);
            }
            DFS(v);
            if(nodes[v].pos != -1){
                update(1, 1, n, nodes[v].pos);
            }
        }
    }

    void process(){
        cin >> s >> m;
        n = s.size();
        s = " " + s;
        for(int i = 1; i <= m; i ++){
            cin >> qr[i].type;
            qr[i].id = i;
            if(qr[i].type == 'C') cin >> qr[i].i;
            else if(qr[i].type == 'U') cin >> qr[i].i;
            else cin >> qr[i].i >> qr[i].j;
        }
        reset(visited);
        init();
        build(1, 1, n);
        //for(int i = 1; i <= 10; i ++) cerr << minSum[i] << "\n";
        DFS(0);
        for(int i = 1; i <= m; i ++){
            if(qr[i].type == 'Q') cout << result[i] << "\n";
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
