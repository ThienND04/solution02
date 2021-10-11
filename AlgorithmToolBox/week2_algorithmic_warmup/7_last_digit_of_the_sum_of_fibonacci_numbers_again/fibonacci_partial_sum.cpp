#include <bits/stdc++.h>

using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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

int get_fibonacci_partial_sum_fast(long long n, long long m){
    return (fibonacci_sum_fast(m) - fibonacci_sum_fast(n - 1) + 10) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << "\n";
    for(int i = 2; i <= 50; i ++){
        for(int j = i; j <= 50; j ++){
            int res1 = get_fibonacci_partial_sum_naive(i, j);
            int res2 = get_fibonacci_partial_sum_fast(i, j);
            assert(res1 == res2);
        }
    }
}
