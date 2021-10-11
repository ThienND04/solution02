#include <iostream>

int get_change(int m)
{
    int arr[] = {1, 5, 10}, res = 0;
    for(int i = 2; i >= 0; i --) {
        res += m / arr[i];
        m %= arr[i];
    }
    return res;
}

int main()
{
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
