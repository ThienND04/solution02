#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define reset(a) memset(a, 0, sizeof(a))
#define clearst(st) while(! st.empty()) st.pop();
#define task "c"
#define inf 999999999
#define maxn 102

int n, m, ha, sa, hb, sb;
vector<pii> adj[maxn];
int df1[maxn], pref1[maxn];
int df2[maxn], pref2[maxn];
int d1[maxn], pre1[maxn];
int d2[maxn], pre2[maxn];
int res = inf, node = 0;
stack<int> st1, st2;

void dijkstra(int s, int dist[], int pre[]){
    fill(dist + 1, dist + n + 1, inf);
    fill(pre + 1, pre + n + 1, 0);
    dist[s] = 0;
    priority_queue<pii> q;
    q.push({0, s});
    while(! q.empty()){
        int u = q.top().second, l = -q.top().first;
        q.pop();
        if(l != dist[u]) continue;
        for(pii e: adj[u]){
            int v = e.first, w = e.second;
            if(l + w < dist[v]){
                dist[v] = l + w;
                pre[v] = u;
                q.push({-dist[v], v});
            }
        }
    }
}

void calc(int s){
    if(df1[s] != df2[s] || df1[s] > res) return;
    dijkstra(s, d1, pre1);
    dijkstra(s, d2, pre2);
    if(df1[s] + d1[sa] != df1[sa]) return;
    if(df2[s] + d2[sb] != df2[sb]) return;
    clearst(st1); clearst(st2);
    res = df1[s];
    node = s;
    int u = sa;
    while(u != s){
        st1.push(u);
        u = pre1[u];
    }
    while(u != ha){
        st1.push(u);
        u = pref1[u];
    }
    st1.push(ha);
    u = sb;
    while(u != s){
        st2.push(u);
        u = pre2[u];
    }
    while(u != hb){
        st2.push(u);
        u = pref2[u];
    }
    st2.push(hb);
}

void print(stack<int>& st){
    while(! st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    cin >> n >> m;
    cin >> ha >> sa >> hb >> sb;
    while( m --){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    dijkstra(ha, df1, pref1);
    dijkstra(hb, df2, pref2);
    for(int s = 1; s <= n; s ++){
        calc(s);
    }
    if(!node){
        cout << "NO";
        return 0;
    }
    cout << "YES\n" ;
    cout << df1[sa] << "\n";
    print(st1);
    cout << df2[sb] << "\n";
    print(st2);
    cout << node << "\n" <<  res;
    return 0;
}