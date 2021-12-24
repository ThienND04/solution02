#include<bits/stdc++.h>

using  namespace std;

typedef pair<double, double> pdd;
typedef pair<int, int> pii;
typedef long long ll;
#define reset(a) memset(a, 0, sizeof(a))
#define task "dtas"
#define inf 1e9
#define mod 1000000007
#define maxn 600001
#define delta 0.0000001

#define bit(x, i) ((x >> i) & 1)

struct people
{
    string name;
    int c, dung;
    ll score = 0;
    vector<int> w;
    void init();
    void updateScore();
};

int n, q;
int fail[maxn]; // so nguoi fail cua 1 cau
ll total = 0;
people pp[maxn];

void people::init(){
    cin >> name;
    string tmp;
    while(1){
        cin >> tmp;
        if(tmp[0] >= 'a' && tmp[0] <= 'z') {
            name += " " + tmp;
        }
        else{
            c = stoi(tmp);
            break;
        }
    }
    w.resize(c);
    dung = q - c;
    for(int i = 0; i < c; i ++) {
        cin >> w[i];
        fail[w[i]] ++;
    }
}

void people::updateScore(){
    score = total;
    for(int i: w) score -= fail[i];
}

bool cmp(people& p1, people& p2){
    if(p1.score != p2.score) return p1.score > p2.score;
    if(p1.dung != p2.dung) return p1.dung > p2.dung;
    return p1.name < p2.name;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if(fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> q;
    for(int i = 1; i <= n; i ++){
        pp[i].init();
    }
    for(int i = 1; i <= q; i ++) total += fail[i];
    for(int i = 1; i<= n; i ++) pp[i].updateScore();
    sort(pp + 1, pp + n + 1, cmp);
    for(int i = 1; i<= n; i ++) cout << pp[i].name << " " << pp[i].score << "\n";
    return 0;
}