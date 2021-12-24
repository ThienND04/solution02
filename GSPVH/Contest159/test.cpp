#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[] = {1, 2, 3, 4 , 4, 5, 9};
    int res = upper_bound(a, a + 7, 4) - a;
    cout << res;
}