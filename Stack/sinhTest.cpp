#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "f"
#define maxn 1000005
#define inf 1e18
#define reset(a) memset(a, 0, sizeof(a))

ofstream fia("a.inp");
ofstream fib("b.inp");

int n, m, k, g;
int a[maxn], b[maxn], c[maxn];

int rand(int gh){
    return rand() % gh + 1;
}

void print(ofstream& f, int arr[], int sz){
    f << "[";
    for(int i = 1; i < sz; i ++) f << arr[i] << ",";
    f << arr[sz] << "]";
}

void sinhTest(){
    cin >> n >> m >> k >> g;
    if(k > n * m) return exit(-1);
    for(int i = 1; i <= n; i ++) a[i] = rand(g);
    for(int i = 1; i <= m; i ++) b[i] = rand(g);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    sinhTest();
    system(".\"" task);
    fia.close();
    fib.close();
    return 0;
}