#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a = {1, 2, 2, 2 ,4};
    int res = upper_bound(a.begin(), a.end(), - 2) - a.begin();
    cerr << res;
    return 0;
}