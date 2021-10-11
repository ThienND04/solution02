#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

struct Segment
{
    int start, end;
};

vector<int> optimal_points(vector<Segment> &segments)
{
    vector<int> points;
    vector<pii> p;
    for(Segment i: segments){
        p.push_back({i.start, 0});
        p.push_back({i.end, 1});
    }
    sort(p.begin(), p.end());
    for(int i = 1; i < p.size(); i ++){
        if(p[i].second == 1 && p[i - 1].second == 0) {
            points.push_back(p[i - 1].first);
        }
    }
    return points;
}

int main()
{
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i)
    {
        std::cin >> segments[i].start >> segments[i].end;
    }
    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (size_t i = 0; i < points.size(); ++i)
    {
        std::cout << points[i] << " ";
    }
}
