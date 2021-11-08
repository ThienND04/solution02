// Nguyen Duc Thien
#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int m, numQuery1 = 0, numQuery2 = 0, numQuery3 = 0;
    cin >> s >> m;
    for(int i = 0; i < m; i ++){
        int t;
        cin >> t;
        if(t == 1) numQuery1 ++;
        else if(t == 2) numQuery2 ++;
        else numQuery3 ++;
    }
    for(int i = 0; i < s.size(); i ++){
        if(s[i] >= 'A' && s[i] <= 'Z' && numQuery1 % 2 == 1){
            s[i] += 32;
        }
        else if(s[i] >= 'a' && s[i] <= 'z' && numQuery2 % 2 == 1){
            s[i] -= 32;
        }
        else if(s[i] >= '0' && s[i] <= '9' && numQuery3 % 2 == 1){
            s[i] = '9' - s[i] + '0';
        }
    }
    cout << s;
    return 0;
}