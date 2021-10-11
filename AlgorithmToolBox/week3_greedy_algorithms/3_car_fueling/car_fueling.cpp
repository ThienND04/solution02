#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    int last = 0, res = 0;
    stops.push_back(dist);
    if(stops[0] > dist) return -1;
    for(int i = 0; i < stops.size() - 1; i ++){
        if(stops[i + 1] - stops[i] > tank) return -1;
        if(stops[i + 1] - last > tank) {
            last = stops[i];
            res ++;
        }
    }
    return res;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
