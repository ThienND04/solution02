#include <iostream>
#include <vector>
#include <map>

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

struct Answer {
	size_t i, j, len;
};

Answer solve(const string &s, const string &t) {

	HashTable hashS(s);
	HashTable hashT(t);

	// binary search to find result then check it
	int left = 0, right = min(s.size(), t.size()) + 1;
	while(right - left > 1){
		int mid = (left + right) / 2;
		map<int, int> mp;
		bool ok = 0;
		for(int i = 0; i + mid - 1 < s.size(); i ++){
			mp[hashS.getHash(i, i + mid - 1)] = i;
		}
		for(int i = 0; i + mid - 1 < t.size(); i ++){
			if(mp.find(hashT.getHash(i, i + mid - 1)) != mp.end()) {
				ok = 1;
				break;
			}
		}
		if(ok) left = mid;
		else right = mid;
	}
	map<int, int> mp;
	for(int i = 0; i + left - 1 < s.size(); i ++){
		mp[hashS.getHash(i, i + left - 1)] = i;
	}
	if(left == 0) return {0, 0, 0};
	for(int i = 0; i + left - 1 < t.size(); i ++){
		if(mp.find(hashT.getHash(i, i + left - 1)) != mp.end()) {
			Answer ans;
			ans.i = mp[hashT.getHash(i, i + left - 1)];
			ans.j = i;
			ans.len = left;
			return ans;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	string s, t;
	while (cin >> s >> t) {
		if(s == "-1") break;
		auto ans = solve(s, t);
		cout << ans.i << " " << ans.j << " " << ans.len << "\n";
	}
}
