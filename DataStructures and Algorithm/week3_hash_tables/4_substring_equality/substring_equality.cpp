#include <iostream>
#include <vector>

using namespace std;


class HashTable{
public:
    static const size_t multiplier = 263;
    static const size_t prime = 1000000007;
    std::vector<int> power;
    string s;
    std::vector<int> hash;
	HashTable(){}
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

class Solver {
	string s;
	HashTable hs;
public:	
	Solver(string s) : s(s) {	
		hs = HashTable(s);
	}
	bool ask(int a, int b, int l) {
		return hs.getHash(a, a + l - 1) == hs.getHash(b, b + l - 1);
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
