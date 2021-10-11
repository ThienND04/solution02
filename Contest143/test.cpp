#include<bits/stdc++.h>
using  namespace std;
long long ma=0,n,a[101][101],d;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    d=n-1;
    while (n!=0)
    {
        for (int i=1;i<=d;i++)
            ma+=a[n][i];
        n--;
        d--;
    }
    cout<<ma;
}