#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;
using std::pair;

typedef pair<int, int> pii;

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
    vector<pii> ps;
    for(int v: starts){
        ps.push_back({v, -1});
    }
    for(int v: ends) ps.push_back({v, 99999999});
    for(int i = 0; i < points.size(); i ++){
        ps.push_back({points[i], i});
    }
    vector<int> cnt(points.size());
    sort(ps.begin(), ps.end());
    int Count = 0;
    for(pii e: ps){
        if(e.second == -1) Count += 1;
        else if(e.second == 99999999) Count -= 1;
        else{
            cnt[e.second] = Count;
        }
    }
    return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
    vector<int> cnt(points.size());
    for (size_t i = 0; i < points.size(); i++)
    {
        for (size_t j = 0; j < starts.size(); j++)
        {
            cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
        }
    }
    return cnt;
}

int main()
{
    int n, m;
    std::cin >> n >> m;
    vector<int> starts(n), ends(n);
    for (size_t i = 0; i < starts.size(); i++)
    {
        std::cin >> starts[i] >> ends[i];
    }
    vector<int> points(m);
    for (size_t i = 0; i < points.size(); i++)
    {
        std::cin >> points[i];
    }
    //use fast_count_segments
    vector<int> cnt = naive_count_segments(starts, ends, points);
    for (size_t i = 0; i < cnt.size(); i++)
    {
        std::cout << cnt[i] << ' ';
    }
}
