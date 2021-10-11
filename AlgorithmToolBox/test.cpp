#include<bits/stdc++.h>

using  namespace std;

int n, cnt = 0;
long long d = 0;

int main(){
    cin >> n;
    int i;
    for (i=1;i<sqrt(n);i++)
    {
        if (n%i==0)
        {
            cnt += 2;
            d += i+(n/i);
        }
    }
    if(i * i == n) {
        cnt ++;
        d += i;
    }
    cout << cnt << " " << d;
    return 0;
}