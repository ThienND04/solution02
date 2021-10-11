#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "bidoimau"
#define maxn 1000005
#define inf 1e18
#define reset(a) memset(a, 0, sizeof(a))

ofstream fi(task ".inp");

int rand(int gh){
    return rand() % gh;
}

void print(ofstream& f, int arr[], int sz){
    for(int i = 1; i <= sz; i ++) f << arr[i] << " ";
    f << "\n";
}

void sinhTest(){
    int m, n, k;
    cin >> m >> n >> k;
    fi << m << " " << n << " " << k << "\n";
    char c[] = {'.', 'b', 'r'};
    for(int i = 1; i <= m; i ++){
        // cerr << rand(3) << " ";
        for(int j = 1; j <= n; j ++) fi << c[rand(3)];
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