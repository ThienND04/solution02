#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "boots"
#define maxn 1000005
#define inf 1e18
#define reset(a) memset(a, 0, sizeof(a))

ofstream fi(task ".inp");

int n, m;
int x[maxn], y[maxn], z[maxn];

int rand(int gh){
    return rand() % gh;
}

void print(ofstream& f, int arr[], int sz){
    for(int i = 1; i <= sz; i ++) f << arr[i] << " ";
}

void sinhTest(){
    cin >> n >> m;
    fi << n << " " << m << endl;
    fi << 0 << " ";
    for(int i = 1; i <= n - 2; i ++) fi << rand(20) << " ";
    fi << 0 << endl;
    for(int i = 1; i <= m; i ++) fi << rand(20) << " " << rand(20) << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    sinhTest();
    fi.close();
    return 0;
}