#include<bits/stdc++.h>

using namespace std;

bool isPrime[10000001];

int main(){
    fill(isPrime + 2, isPrime + 10000001, 1);
    int cnt = 0;
    for(int i = 2; i < 10000001; i ++){
        if(!isPrime[i]) continue;
        cnt ++;
        for(long long j = 1LL * i * i; j < 10000001; j += i) isPrime[j] = 0;
    }
    cout << cnt;
    return 0;
}