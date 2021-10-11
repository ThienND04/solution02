#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HeapBuilder
{
private:
    vector<int> data_;
    vector<pair<int, int>> swaps_;

    void WriteResponse() const
    {
        cout << swaps_.size() << "\n";
        for (int i = 0; i < swaps_.size(); ++i)
        {
            cout << swaps_[i].first << " " << swaps_[i].second << "\n";
        }
    }

    void ReadData()
    {
        int n;
        cin >> n;
        data_.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> data_[i];
    }

    void GenerateSwaps()
    {
        swaps_.clear();
        for(int i = (data_.size() - 2) / 2; i >= 0; i --){
            int j = i;
            while(1){
                int l = j * 2 + 1;
                int r = j * 2 + 2;
                if(l > data_.size() - 1) break;
                if(r > data_.size() - 1){
                    if(data_[j] > data_[l]){
                        swaps_.push_back({j, l});
                        swap(data_[j], data_[l]);
                    }
                    break;
                }
                if(data_[j] <= min(data_[l], data_[r])) break;
                int k;
                if(data_[l] < data_[r]) k = l;
                else k = r;
                swaps_.push_back({j, k});
                swap(data_[j], data_[k]);
                j = k;
            }
        }
    }

public:
    void Solve()
    {
        ReadData();
        GenerateSwaps();
        WriteResponse();
    }
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::freopen("04.a", "r", stdin); std::freopen("04.a", "w", stdout);
    HeapBuilder heap_builder;
    heap_builder.Solve();
    return 0;
}
