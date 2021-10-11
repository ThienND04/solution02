#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "station"
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
    f << "\n";
}

void sinhTest(){
    cin >> n;
    fi << n << "\n";
    for(int i = 1; i <= n; i ++) fi << rand(10000) << " ";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    sinhTest();
    fi.close();
    return 0;
}