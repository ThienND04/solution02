// Nguyen Duc Thien
#include<bits/stdc++.h>

using namespace std;

int main(){
    int result = 0, i = 0, maxNum = 10, numDigits = 1;
    string s;
    cin >> s;
    while(i < s.size()){
        result ++;
        if(result == maxNum){
            maxNum *= 10;
            numDigits ++;
        }
        i += numDigits;
    }
    cout << result;
    return 0;
}