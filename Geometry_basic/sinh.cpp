#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define task "closestPair"
#define maxn 1000005
#define inf 1e18
#define reset(a) memset(a, 0, sizeof(a))

int n, m, k, g;
int a[maxn], b[maxn], c[maxn];

int randint(int gh){
    return rand() % (2 * gh) - gh + 1;
}

void print(ofstream& f, int arr[], int sz){
    for(int i = 1; i <= sz; i ++) f << arr[i] << " ";
}

void sinhTest(){
    cin >> n;
    cout << n << "\n";
    for(int i = 1; i <= n; i ++) {
        cout << randint(50000) << " " << randint(50000) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    srand(time(NULL));
    freopen(task ".inp", "w", stdout);
    sinhTest();
    return 0;
}