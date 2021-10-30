#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define maxn 100001
#define task "color"
#define BLOCK_SIZE 500

#define inBlock(pos) ((pos - 1) / BLOCK_SIZE + 1)

#define reset(a) memset(a, 0, sizeof(a))

string c1, c2;
map<string, string> tp;
string color[] = {"Red", "Orange", "Yellow", "Green", "Blue", "Violet"};


void init(){
    cin >> c1 >> c2;
    tp["Red"] = "Green";
    tp["Green"] = "Red";
    tp["Orange"] = "Blue";
    tp["Blue"] = "Orange";
    tp["Yellow"] = "Violet";
    tp["Violet"] = "Yellow";
}

string solve(){
    if(c1 == c2){
        return "Same";
    }
    if(tp[c1] == c2) {
        return "Complementary";
    }
    int p1 = -5, p2 = - 5;
    for(int i = 0; i < 6; i ++){
        if(c1 == color[i]) p1 = i;
        if(c2 == color[i]) p2 = i;
    }
    assert(p1 != -5 && p2 != -5);
    if(p1 > p2) swap(p1, p2);
    if(abs(p1 - p2) == 1) return "Adjacent";
    if(p2 - p1 == 2) return color[(p2 + p1) / 2];
    if(p2 == 5) p2 = -1;
    else if(p1 == 0) p1 = 6;
    if(p1 > p2) swap(p1, p2);
    if(abs(p1 - p2) == 1) return "Adjacent";
    if(p2 - p1 == 2) return color[(p2 + p1) / 2];
    return "None";
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
    cout << solve();
    return 0;
}