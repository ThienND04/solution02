// Nguyen Duc Thien
#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int cntV = 0, cntVT = 0;    
    cin >> s;
    bool ok = 1;
    for(int i = 0; i < s.size(); i ++){
        if(s[i] == 'V') cntV ++;
        else if(s[i] == 'T'){
            if(cntV == 0) {
                ok = 0;
                break;
            }
            cntVT ++;
            cntV --;
        }
        else {
            if(cntVT == 0) {
                ok = 0;
                break;
            }
            else cntVT --;
        }
    }
    if(ok) cout << "YES";
    else cout << "NO";
    return 0;
}