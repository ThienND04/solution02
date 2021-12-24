#include<iostream>
#include<cassert>

using namespace std;

char cd[500];
char st[1001];

string solve(string s){
    int sz = 0;
    for(char c: s){
        assert(sz >= 0);
        if(cd[c] == '0'){
            st[++ sz] = c;
        }
        else{
            if(sz == 0 || st[sz --] != cd[c]) return "NO";
        }
    }
    if(sz) return "NO";
    return "YES";
}   

int main(){
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < 500; i ++) cd[i] = '0';
    cd['}'] = '{';
    cd[')'] = '(';
    cd[']'] = '[';
    while(n --){
        cin >> s;
        cout << solve(s) << "\n";
    }
    return 0;
}