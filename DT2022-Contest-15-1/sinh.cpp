#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "diary"
#define maxn 1000005
#define inf 1e18
#define reset(a) memset(a, 0, sizeof(a))

ofstream fi(task ".inp");

int n;
int x[maxn], y[maxn], z[maxn];

int rand(int gh){
    return rand() % gh + rand() % 2;
}

void print(ofstream& f, int arr[], int sz){
    for(int i = 1; i <= sz; i ++) f << arr[i] << " ";
}

void sinhTest(){
    cin >> n;
    fi << n << endl;
    for(int i = 1; i <= n; i ++) {
        x[i] = rand(n);
        fi << x[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    sinhTest();
    fi.close();
    return 0;
}