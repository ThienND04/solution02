#include <bits/stdc++.h>

using namespace std;

int partition3(vector<int> &A)
{
    bool ok[3][21][601];
    int sum = 0;
    for(int v: A) sum += v;
    if(sum % 3 != 0) return 0;
    sum /= 3;
    memset(ok, 0, sizeof(ok));
    for(int i = 0; i < 3; i ++){
        ok[i][0][A[0]] = 1;
        ok[i][0][0] = 1;
    }
    for(int i = 1; i < A.size(); i ++){
        for(int j = 0; j < 3; j ++){
            for(int k = 0; k < 3; k ++){
                if(j == k) continue;
                for(int t = 0; t <= 600; t ++){
                    if(ok[k][i - 1][t]) ok[k][i][t] = 1;
                }
            }
            for(int t = A[i]; t <= 600; t ++){
                if(ok[j][i - 1][t - A[i]]) ok[j][i][t] = 1;
            }
        }
    }
    int n = A.size() - 1;
    return (ok[0][n][sum] && ok[1][n][sum] && ok[2][n][sum]);
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> A(n);
    for (size_t i = 0; i < A.size(); ++i)
    {
        std::cin >> A[i];
    }
    std::cout << partition3(A) << '\n';
}
