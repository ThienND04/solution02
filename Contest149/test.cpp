#include<iostream>

using namespace std;

double f(int n){
    if(n == 1) return 1.0 / 4;
    double result = f(n - 1);
    if(n % 2 == 0) result -= 1.0 / (1ll * 4 * n * n);
    else result += 1.0 / (1ll * 4 * n * n);
    return result;
}

int main(){
    int n;
    cin >> n; // n >= 1
    cout << f(n);
    return 0;
}