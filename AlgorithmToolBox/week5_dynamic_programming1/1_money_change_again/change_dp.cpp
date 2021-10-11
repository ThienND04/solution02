#include <iostream>
#include<math.h>

int get_change(int m)
{
    int dp[1001];
    int moneys[] = {1, 3, 4};
    dp[0] = 0;
    for(int i = 1; i <= m; i ++){
        dp[i] = 1e9;
        for(int j = 0; j < 3; j ++){
            int v = moneys[j];
            if(i - v < 0) continue;
            dp[i] = std::min(dp[i], dp[i - v] + 1);
        }
    }
    return dp[m];
}

int main()
{
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
