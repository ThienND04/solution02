#include <bits/stdc++.h>
using namespace std;

bool ok[100000];
int n, k, res = 0;
long long a;

int main()
{
    cin >> n >> k;
    while(n --)
    {
        cin >> a;
        ok[a % k] = 1;
    }
    for (int i = 0; i < k; i ++)
        res += ok[i];
    cout << res;
    return 0;
}