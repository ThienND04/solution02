#include <iostream>
#include <vector>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b)
{
    int dp[101][101];
    for(int i = 0; i < a.size(); i ++) dp[i][0] = (a[i] == b[0]);
    for(int i = 0; i < b.size(); i ++) dp[0][i] = (a[0] == b[i]);
    for(int i = 1; i < a.size(); i ++){
        for(int j = 1; j < a.size(); j ++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }
    return dp[a.size() - 1][b.size() - 1];
}

int main()
{
    size_t n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    size_t m;
    std::cin >> m;
    vector<int> b(m);
    for (size_t i = 0; i < m; i++)
    {
        std::cin >> b[i];
    }

    std::cout << lcs2(a, b) << std::endl;
}
