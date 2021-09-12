#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[10], b[10], c[20];
    for(int i = 0; i < 10; i ++){
        a[i] = i;
        b[i] = i + 10;
    }
    merge(a, a + 10, b, b + 10, c);
    for(int i = 0; i < 20; i ++) cout << c[i] << " ";
}