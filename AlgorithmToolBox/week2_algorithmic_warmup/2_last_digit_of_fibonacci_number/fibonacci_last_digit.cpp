#include <iostream>
#include<cassert>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int get_fibonacci_last_digit_fast(int n){
    int f[10001];
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= n; i ++){
        f[i] = (f[i - 1] + f[i - 2]) % 10;
    }
    return f[n];
}

void testSolution(){
    assert(get_fibonacci_last_digit_fast(10) == 5);
    for(int i = 1; i <= 10; i ++) {
        assert(get_fibonacci_last_digit_fast(i) == get_fibonacci_last_digit_naive(i));
    }
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_naive(n);
    testSolution();
    std::cout << c << '\n';
    }
