#include <iostream>
#include <string>

using namespace std;

int edit_distance(string &str1, string &str2)
{
    int n = str1.size(), m = str2.size();
    str1 = " " + str1;
    str2 = " " + str2;
    int dp[101][101];
    dp[0][0] = 0;
    for(int i = 1; i <= n; i ++) {
        dp[i][0] = i;
    }
    for(int i = 1; i <= m; i ++){
        dp[0][i] = i;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(str1[i] == str2[j]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string str1;
    string str2;
    std::cin >> str1 >> str2;
    std::cout << edit_distance(str1, str2) << std::endl;
    return 0;
}
