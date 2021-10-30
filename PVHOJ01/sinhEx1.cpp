#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "ex1"
#define maxn 1000005
#define inf 1e18
#define reset(a) memset(a, 0, sizeof(a))

ofstream fi(task ".inp");

int vt[3001 * 3001];

int rand(int gh){
    return rand() % gh;
}

void print(ofstream& f, int arr[], int sz){
    for(int i = 1; i <= sz; i ++) f << arr[i] << " ";
    f << "\n";
}

void sinhTest(){
    int r, c, h, w;
    cin >> r >> c >> h >> w;
    fi << r << " " << c << " " << h << " " << w << endl;
    int cnt = 0;
    for(int i = 1; i <= r * c; i ++) vt[++ cnt] = i;
    random_shuffle(vt + 1, vt + cnt + 1);
    cnt =  0;
    for(int i = 1; i <= r; i ++){
        for(int j = 1; j <= c; j ++){
            fi << vt[++ cnt] << " ";
        }
        fi << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    sinhTest();
    fi.close();
    return 0;
}