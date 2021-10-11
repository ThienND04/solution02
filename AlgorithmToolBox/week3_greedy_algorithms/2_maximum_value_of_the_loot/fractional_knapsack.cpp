#include <iostream>
#include <vector>
#include<algorithm>
#include<math.h>
#include<iomanip>

using std::vector;
using std::pair;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values)
{
    double value = 0.0;
    vector<pair<double, int>> tl(weights.size());
    for(int i = 0; i < weights.size(); i ++){
        tl[i] = {1.0 * values[i] / weights[i], weights[i]};
    }
    sort(tl.begin(), tl.end());
    for(int i = weights.size() - 1; i >= 0; i --){
        int tmp = std::min(capacity, tl[i].second);
        value += tmp * tl[i].first;
        capacity -= tmp;
    }
    return value;
}

int main()
{
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<int> values(n);
    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i] >> weights[i];
    }

    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout << std::fixed << std::setprecision(4) << optimal_value << std::endl;
    return 0;
}
