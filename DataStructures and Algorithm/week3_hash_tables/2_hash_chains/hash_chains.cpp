#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    // store all strings in one vector
    vector<vector<string> > bucket;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count) {
        bucket.resize(bucket_count);
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        std::cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if(query.type == "check"){
            // reverse to print
            for(int i = bucket[query.ind].size() - 1; i >= 0; i --){
                std::cout << bucket[query.ind][i] << " ";
            }
            std::cout << "\n";
        }
        else{
            int hs = hash_func(query.s);
            int index = bucket[hs].size();
            for(int i = 0; i < bucket[hs].size(); i ++){
                if(bucket[hs][i] == query.s) {
                    index = i;
                    break;
                }
            }
            if(query.type == "add"){
                if(index == bucket[hs].size()) bucket[hs].push_back(query.s);
            }
            else if(query.type == "del"){
                if(index != bucket[hs].size()) {
                    bucket[hs].erase(bucket[hs].begin() + index);
                }
            }
            else{
                if(index == bucket[hs].size()) std::cout << "no\n";
                else std::cout << "yes\n";
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
