#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w)
{
    vector<vector<bool> > ok(w.size());
    for(int i = 0; i < ok.size(); i ++){
        vector<bool>b(W + 1, 0);
        ok[i] = b;
    }
    ok[0][0] = 1;
    for(int i = 1; i < w.size(); i ++){
        int v = w[i];
        for(int j = 0; j <= W; j ++) ok[i][j] = ok[i - 1][j];
        for(int j = v; j <= W; j ++){
            if(ok[i - 1][j - v]) ok[i][j] = 1;
        }
    }
    for(int i = W; i >= 0; i --){
        if(ok[w.size() - 1][i]) return i;
    }
}

int main()
{
    int n, W;
    std::cin >> W >> n;
    vector<int> w(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> w[i];
    }
    std::cout << optimal_weight(W, w) << '\n';
}
