#include <iostream>
#include <vector>
#include<deque>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using std::deque;

void max_sliding_window(vector<int> const & A, int w) {
    deque<int> q;
    for(int i = 0; i < A.size(); i ++){
        while(! q.empty() && i - q.front() + 1 > w) q.pop_front();
        while(! q.empty() && A[q.back()] <= A[i]) q.pop_back();
        q.push_back(i);
        if(i > w - 1) cout << A[q.front()] << " ";
    }
}


int main() {
    int n = 0;
    cin >> n;

    vector<int> A(n);
    for (size_t i = 0; i < n; ++i)
        cin >> A.at(i);

    int w = 0;
    cin >> w;

    max_sliding_window(A, w);

    return 0;
}
