#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[] = {0, 0, 0, 1};
    cout << upper_bound(a, a + 4, 0) - a;
}