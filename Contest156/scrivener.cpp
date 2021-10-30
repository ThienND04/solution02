#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 1000001
#define task "scrivener"

#define reset(a) memset(a, 0, sizeof(a))

#define LOG 21

int subtask;
int numNode = 0, curNode = 0, q;
int node[maxn][27], id[maxn], hight[maxn], p[maxn][LOG];
char nt[maxn];

void insert(int query_id, char c){
    c -= 'a';
    if(! node[curNode][c]) {
        node[curNode][c] = ++numNode;
        hight[numNode] = hight[curNode] + 1;
        p[numNode][0] = curNode;
        nt[numNode] = c + 'a';
        for(int i = 1; i < LOG; i ++) {
            p[numNode][i] = p[p[numNode][i - 1]][i - 1];
        }
        curNode = numNode;
    }
    else curNode = node[curNode][c];
    id[query_id] = curNode;
}   

void under(int query_id, int num){
    curNode = id[query_id - num - 1];
    id[query_id] = curNode;
}

char print(int num){
    if(num == hight[curNode]) return nt[curNode];
    int delta = hight[curNode] - num;
    int u = curNode;
    for(int i = LOG - 1; i >= 0; i --){
        if((delta >> i) & 1){
            u = p[u][i];
        }
    }
    return nt[u];
}

void solve(){
    cin >> subtask >> q;
    int id_query = 0;
    for(int i = 1; i <= q; i ++) {
        char t;
        cin >> t;
        if(t == 'T'){
            id_query ++;
            char c;
            cin >> c;
            insert(id_query, c);
        }
        else if(t == 'U'){
            id_query ++;
            int num;
            cin >> num;
            under(id_query, num);
        }
        else{
            int num;
            cin >> num;
            cout << print(num);
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
    solve();
    return 0;
}