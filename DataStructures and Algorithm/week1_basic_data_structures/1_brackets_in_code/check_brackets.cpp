#include <iostream>
#include <stack>
#include <string>

using namespace std;

#define maxn 100001

int sz = 0;
char brakets[300];
char st[maxn];
char open[] = {'[', '{', '('};
char close[] = {']', '}', ')'};

bool In(char arr[], char c){
    for(int i = 0; i < 3; i ++) {
        if(c == arr[i]) return 1;
    }
    return 0;
}

int solve(string text){
    for(int i = 0; i < text.size(); i ++){
        char c = text[i];
        if(In(close, c)){
            if(! sz || brakets[st[sz]] != c) return i + 1;
            sz --;
        }
        else if(In(open, c)){
            st[++ sz] = c;
        }
    }
    if(sz == 0) return 0;
    return text.size();
}

int main() {
    string text;
    cin >> text;
    brakets['['] = ']';
    brakets['{'] = '}';
    brakets['('] = ')';
    int res = solve(text);
    if(! res) cout << "Success";
    else cout << res;
    return 0;
}
