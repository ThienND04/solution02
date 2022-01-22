#include<iostream>
#include<iomanip>

using namespace std;

int main(){
    int m, n, **matrix, maxNum = 0;
    cin >> m >> n;
    matrix = new int*[m];
    for(int i = 0; i < m; i ++) matrix[i] = new int[n];
    for(int i= 0; i < m; i ++){
        for(int j = 0; j < n; j ++) {
            cin >> matrix[i][j];
            maxNum = max(maxNum, matrix[i][j]);
        }
    }
    cout << maxNum;
    return 0;
}