#include <iostream>
#include<cassert>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd(int a, int b){
  while(a * b != 0){
    if(a > b) a %= b;
    else b %= a;
  }
  return a + b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_naive(a, b) << std::endl;
  assert(gcd(6, 9) == 3);
  for(int i = 1; i <= 20; i ++){
    for(int j = 1; j <= 20; j ++){
      assert(gcd(i, j) == gcd_naive(i, j));
    }
  }
  return 0;
}
