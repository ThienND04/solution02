#include<bits/stdc++.h>

using namespace std;

int main(){
    map<int, int> mp;
    mp[2] = 3;
    auto f = mp.find(2);
    if(f != mp.end()) cout << 1 << endl;
    else cout << 0 << endl;

    f = mp.find(3);
    if(f != mp.end()) cout << 1 << endl;
    else cout << 0 << endl;
}