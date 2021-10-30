#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

class HashTable{
public:
    static const size_t multiplier = 263;
    static const size_t prime = 1000000007;
    std::vector<int> power;
    string s;
    std::vector<int> hash;
    HashTable(const string& s1): s(s1) {
        hash.resize(s.size() + 1);
        power.resize(s.size() + 1);
        computePower();
        computeHash();
    }

    void computePower(){
        power[0] = 1;
        for(int i = 1; i <= s.size(); i ++){
            power[i] = (1ull * power[i - 1] * multiplier) % prime;
        }
    }

    void computeHash(){
        hash[s.size()] = 0;
        for(int i = s.size() - 1; i >= 0; i --){
            hash[i] = (1ull * hash[i + 1] * multiplier + s[i]) % prime;
        }
    }
    int getHash(){
        // get hash of whole string 
        return hash[0];
    }
    int getHash(int left, int right){   
        int tmp = (0ull + hash[left] - 1ull * hash[right + 1] * power[right - left + 1] + prime * prime) % prime;
        return tmp;
    }
};

Data read_input() {
    Data data;
    std::cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const std::vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        std::cout << output[i] << " ";
    std::cout << "\n";
}

std::vector<int> get_occurrences(const Data& input) {
    string s = input.pattern, t = input.text;
    int pattern_size = s.size();
    HashTable ptHash(s);
    HashTable textHash(t);
    std::vector<int> result;
    for(int i = 0; i + pattern_size <= t.size(); i ++){
        if(ptHash.getHash() == textHash.getHash(i, i + pattern_size - 1)) result.push_back(i);
    }
    return result;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
