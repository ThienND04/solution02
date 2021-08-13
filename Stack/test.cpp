#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(task ".inp", "r", stdin); freopen(task ".out", "w", stdout);
    int a[] = {0, 1, 2, 3, 4, 5 ,6 ,7};
    int x = 7;
    cout << upper_bound(a + 1, a + 8, x) - a;
    return 0;
}