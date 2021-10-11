#include <iostream>
#include<cassert>

long long lcm_naive(int a, int b)
{
    for (long l = 1; l <= (long long)a * b; ++l)
        if (l % a == 0 && l % b == 0)
            return l;

    return (long long)a * b;
}

int gcd(int a, int b)
{
    while (a * b != 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

long long lcm(int a, int b)
{
    return (long long)(1) * a * b / gcd(a, b);
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << lcm_naive(a, b) << std::endl;
    assert(lcm(30, 9) == 90);
    for(int i = 1; i <= 30; i ++){
        for(int j = 1; j<= 30; j ++) assert(lcm(i, j) == lcm_naive(i, j));
    }
    return 0;
}
