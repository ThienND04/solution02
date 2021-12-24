#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "pair"
#define maxn 1000005
#define inf 1e18
#define reset(a) memset(a, 0, sizeof(a))

ofstream fi(task ".inp");

int rand(int gh){
    return rand() % gh + 1;
}

void print(ofstream& f, int arr[], int sz){
    for(int i = 1; i <= sz; i ++) f << arr[i] << " ";
    f << "\n";
}

void sinhTest(){
    int n, m, k;
    cin >> n >> m >> k;
    fi << n << " " << m << " " << k << endl;
    for(int i = 1; i <= n; i ++) {
        fi << rand(1000000000) << " ";
    }
    fi << endl;
    for(int i = 1; i <= m; i ++) {
        fi << rand(1000000000) << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    sinhTest();
    fi.close();
    return 0;
}