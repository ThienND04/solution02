#include <bits/stdc++.h>
using namespace std;

string s, a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            a += s[i];
        }
    }
    sort(a.begin(), a.end());
    int j = 0;
    for(int i = 0; i < s.size(); i ++){
        if(s[i] >= '0' && s[i] <= '9') s[i] = a[j ++];
    }
    cout << s;
    return 0;
}