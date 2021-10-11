#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right)
{
    int index = 0;
    int count  = 1;
    for(int i = left + 1; i < right; i ++){
        if(a[i] == a[index]) count ++;
        else count --;
        if(! count){
            count = 1;
            index = i;
        }
    }
    count = 0;
    for(int i = left; i < right; i ++){
        count += a[i] == a[index];
    }
    if(count > (right / 2)) return 1;
    return -1;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i)
    {
        std::cin >> a[i];
    }
    //std::sort(a.begin(), a.end());
    std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
