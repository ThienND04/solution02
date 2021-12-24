#include<iostream> 

using namespace std;

bool f[11][11];

int main(){
    int n = 10;
    f[0][0] = 0;
    for(int i = 0; i <= n; i ++){
        for(int j = 0; j <= n; j ++){
            if(j - 1 >= 0 && !f[i][j - 1])  f[i][j] = 1;
            if(i - 1 >= 0 && !f[i - 1][j])  f[i][j] = 1;
            if(i - 1 >= 0 && j - 1 >= 0 && !f[i - 1][j - 1])  f[i][j] = 1;
        }
    }
    int left, right;
    while(cin >> left >> right){
        if(! left && !right) return 0;
        if(left - 1 >= 0 && !f[left - 1][right]) cout << "left: -1\n";
        else if(right - 1 >= 0 && !f[left][right - 1]) cout << "right: -1\n";
        else if(left - 1 >= 0 && right - 1 >= 0 && !f[left - 1][right - 1]) cout << "lr\n";
    }
    return 0;
}