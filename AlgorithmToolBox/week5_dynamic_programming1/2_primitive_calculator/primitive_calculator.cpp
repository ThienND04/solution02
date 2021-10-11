#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n)
{
    vector<int> dp(n + 1, 999999999);
    dp[1] = 0;
    for(int i = 2; i <= n; i ++){
        if(i % 2 == 0) dp[i] = std::min(dp[i], dp[i / 2] + 1);
        if(i % 3 == 0) dp[i] = std::min(dp[i], dp[i / 3] + 1);
        dp[i] = std::min(dp[i], dp[i - 1] + 1);
    }
    vector<int> traces(dp[n] + 1);
    for(int i = dp[n]; i >= 0; i --){
        traces[i] = n;
        if(n % 2 == 0 && dp[n] == dp[n / 2] + 1) {
            n /= 2;
            continue;
        }
        if(n % 3 == 0 && dp[n] == dp[n / 3] + 1){
            n /= 3;
            continue;
        }
        n --;
    }
    return traces;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> sequence = optimal_sequence(n);
    std::cout << sequence.size() - 1 << std::endl;
    for (size_t i = 0; i < sequence.size(); ++i)
    {
        std::cout << sequence[i] << " ";
    }
}
