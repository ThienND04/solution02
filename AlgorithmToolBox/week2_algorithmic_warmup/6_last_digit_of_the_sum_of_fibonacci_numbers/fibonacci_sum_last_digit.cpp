#include <bits/stdc++.h>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n){
    const int m = 10;
    int f[100], s[100];
    bool check[100];
    memset(check, 0, sizeof(check));
    memset(f, 0, sizeof(f));
    memset(s, 0, sizeof(s));
    f[1] = 1;
    s[1] = 1;
    check[1 * 10] = 1;
    int start = 0, t = 0;
    for(int i = 2; i <= n; i ++){
        f[i] = (f[i - 1] + f[i - 2]) % m;
        s[i] = (s[i - 1] + f[i]) % m;
        int tmp = f[i] * 10 + f[i - 1];
        if(check[tmp]){
            int j = i - 1;
            while(j >= 0){
                int tmp2 = f[j] * 10 + f[j - 1];
                if(tmp2 == tmp) break;
                j --;
            }
            start = j - 1;
            t = i - j;
            break;
        }
        check[tmp] = 1;
    }
    if(! t) return s[n];
    int tot = (s[start + t] - s[start] + m) % m;
    return s[start] + tot * ((n / t) % m) + s[n % t + start] - s[start];
}

int main() {
    long long n = 0;
    // std::cin >> n;
    // std::cout << fibonacci_sum_naive(n) << "\n";
    // std::cout << fibonacci_sum_fast(n) << "\n";
    for(int i = 1; i <= 50; i ++){
        int res1 = fibonacci_sum_naive(i);
        int res2 = fibonacci_sum_fast(i);
        std::cerr << i << ": " << res1 << " " << res2 << "\n";
        assert(res1 == res2);
    }
    return 0;
}
