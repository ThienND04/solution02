#include <iostream>
#include <vector>

using std::vector;

typedef long long ll;

ll Merge(vector<int>& a, int lf1, int rt1, int lf2, int rt2){
    int j = lf2;
    ll res = 0;
    for(int i = lf1; i <= rt1; i ++){
        while(j <= rt2 && a[j] < a[i]) j ++;
        res += j - lf2;
    }
    int i = lf1;
    j = lf2;
    vector<int> b;
    while(i <= rt1 && j <= rt2){
        if(a[i] < a[j]) b.push_back(a[i ++]);
        else b.push_back(a[j ++]);
    }
    while(i <= rt1) b.push_back(a[i ++]);
    while(j <= rt2) b.push_back(a[j ++]);
    i = lf1;
    for(int v: b) a[i ++] = v;
    return res;
}

long long get_number_of_inversions(vector<int> &a, size_t left, size_t right)
{
    ll res = 0;
    if(left + 1 >= right) return res;
    int mid = (left + right) / 2;
    res += get_number_of_inversions(a, left, mid);
    res += get_number_of_inversions(a, mid + 1, right);
    res += Merge(a, left, mid, mid + 1, right);
    return res;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cin >> a[i];
    }
    std::cout << get_number_of_inversions(a, 0, a.size() - 1) << '\n';
}
