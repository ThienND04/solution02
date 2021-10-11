#include<bits/stdc++.h>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, int m){
    assert(m <= 1000);
    int f[1000001];
    bool check[1000001];
    memset(check, 0, sizeof(check));
    f[1] = 1;
    check[1 * 1000] = 1;
    int start = 0, t = 0;
    for(int i = 2; i <= n; i ++){
        f[i] = (f[i - 1] + f[i - 2]) % m;
        int tmp = f[i] * 1000 + f[i - 1];
        if(check[tmp]){
            int j = i - 1;
            while(j >= 0){
                int tmp2 = f[j] * 1000 + f[j - 1];
                if(tmp2 == tmp) break;
                j --;
            }
            start = j - 1;
            t = i - j;
            break;
        }
        check[tmp] = 1;
    }
    if(! t) return f[n];
    return f[start + (n - start) % t];
}

int main() {
    long long n, m;
    n = 4, m = 2;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << "\n";
    for(int i = 1; i <= 40; i ++){
        for(int j = 2; j <= 30; j ++){
            int res1 = get_fibonacci_huge_naive(i, j);
            int res2 = get_fibonacci_huge_fast(i, j);
            std::cerr << i << " " << j << ": " << res1 << " " << res2 << "\n";
            assert(res1 == res2);
        }
    }
}
