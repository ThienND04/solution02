#include<iostream>

using namespace std;

string s;
int k, n, nt[1000001];
long long res = 0;

int main(){
    cin >> k >> s;
    int j = 0, num = 0, tmp = 0;
    n = s.size();

    nt[n - 1] = (s[n - 1] == '1' ? 1 : 2);

    for(int i = n - 2; i >= 0; i --){
        if(s[i] == '1') nt[i] = 1;
        else nt[i] = 1 + nt[i + 1];
    }

    for(int i = 0; i < s.size(); i ++){
        if(s[i] == '1') num ++;
        while(num > k && j <= i){
            if(s[j] == '1') {
                num --;
                tmp = 1;
            }
            j ++;
        }
        if(j > i) continue;
        if(num == k) res += min(i - j + 1, nt[j]);
    }
    cout << res;
}